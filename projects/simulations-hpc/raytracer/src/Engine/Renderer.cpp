/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Renderer
*/

#include "../../include/RayTracer.hpp"
#include "../../include/Physics/Ray.hpp"
#include "../../include/Effects/Effect.hpp"
#include "../../include/Effects/Bloom.hpp"
#include "../../include/Effects/Clamp.hpp"
#include "../../include/Effects/GaussianBlur.hpp"

Renderer::Renderer()
{
    _numThreads = std::thread::hardware_concurrency();
    _numThreads = std::max(std::min(_numThreads, MAX_THREADS), 1);
    _num = 0;
}

Renderer::~Renderer()
{
}

void Renderer::initWindow(Camera cam)
{
    _window.create(sf::VideoMode(cam.getWidth(), cam.getHeight()), "RayTracer");
}

int Renderer::getNumThreads()
{
    return _numThreads;
}

sf::RenderWindow &Renderer::getWindow()
{
    return _window;
}

sf::Event &Renderer::getEvent()
{
    return _event;
}

sf::Image &Renderer::getImage()
{
    return _image;
}

sf::Texture &Renderer::getTexture()
{
    return _texture;
}

sf::Sprite &Renderer::getSprite()
{
    return _sprite;
}

Array Renderer::generateTasks(const std::pair<int,
int> &size, const std::pair<int, int>& tileSize, Array& tasks) {
    for (int i = 0; i <= size.first / tileSize.first; i++)
        for (int j = 0; j <= size.second / tileSize.second; j++) {
            std::pair<int, int> tile = tileSize;
            if (i == size.first / tileSize.first)
                tile.first = size.first % tileSize.first;
            if (j == size.second / tileSize.second)
                tile.second = size.second % tileSize.second;
            tasks.push_back({i, j, tile.first, tile.second});
        }
    return tasks;
}

void Renderer::sortTasks(Array &tasks,
const std::pair<int, int>& size, const std::pair<int, int>& tileSize) {
    std::sort(tasks.begin(), tasks.end(), [size, tileSize](std::vector<int> a, std::vector<int> b) {
        double d1 = std::sqrt(std::pow(a[0] * tileSize.first + a[2] / 2 - size.first / 2, 2)
            + std::pow(a[1] * tileSize.second + a[3] / 2 - size.second / 2, 2));
        double d2 = std::sqrt(std::pow(b[0] * tileSize.first + b[2] / 2 - size.first / 2, 2)
            + std::pow(b[1] * tileSize.second + b[3] / 2 - size.second / 2, 2));

        return d1 < d2;
    });
}

void Renderer::eventHandler() {
    while (_window.pollEvent(_event))
        if (_event.type == sf::Event::Closed)
            _window.close();
}

void Renderer::removeCompletedFutures(std::vector<std::future<void>> &futures)
{
    for (auto it = futures.begin(); it != futures.end(); ) {
        if (it->wait_for(std::chrono::seconds(0)) == std::future_status::ready)
            it = futures.erase(it);
        else
            it++;
    }
}

void Renderer::drawImage(Image &img)
{
    for (std::size_t i = 0; i < img.size(); i++)
        for (std::size_t j = 0; j < img.front().size(); j++) {
            if (i >= img.size() || j >= img.front().size())
                continue;
            _image.setPixel(i, j, sf::Color(img[i][j].getR() * 255,
                img[i][j].getG() * 255, img[i][j].getB() * 255));
        }
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);
    _window.draw(_sprite);
}

void Renderer::drawTasks(const Array &tasks, const std::pair<int, int> &tileSize)
{
    for (auto &t : tasks) {
        sf::RectangleShape rect(sf::Vector2f(t[2], t[3]));
        rect.setPosition(t[0] * tileSize.first, t[1] * tileSize.second);
        rect.setFillColor(sf::Color(91, 91, 91, 255));
        _window.draw(rect);
    }
}

void Renderer::drawRunningTasks(const Array &run, const std::pair<int, int> &tileSize)
{
    for (auto &r : run) {
        sf::RectangleShape rect(sf::Vector2f(r[2], r[3]));
        rect.setPosition(r[0] * tileSize.first, r[1] * tileSize.second);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color(255, 127, 0, 127));
        rect.setOutlineThickness(1);
        _window.draw(rect);
    }
}

void Renderer::applyPostProcessing(Image& img, bool& _render)
{
    if (!_render) {
        std::cout << "Applying post processing effects..." << std::endl;
        std::unique_ptr<Effect> imageEffect;
        if (_effect.bloom_threshold != -1) {
            imageEffect = std::make_unique<Bloom>(std::move(imageEffect), _effect.bloom_threshold, _effect.bloom_sigma, _effect.bloom_radius);
            imageEffect->applyEffect(img);
            std::cout << "Bloom effect applied" << std::endl;
        }
        if (_effect.gaussianBlur_sigma != -1) {
            imageEffect = std::make_unique<GaussianBlur>(std::move(imageEffect), _effect.gaussianBlur_sigma, _effect.gaussianBlur_radius);
            imageEffect->applyEffect(img);
            std::cout << "GaussianBlur effect applied" << std::endl;
        }
        _clamp.applyEffect(img);
        _render = true;
    }
}

Vector3d Renderer::getDirection(Camera cam, Vector3d dir)
{
    Vector3d up(0, 1, 0);
    Vector3d right = cam.getDirection().cross(up);
    up = right.cross(cam.getDirection());
    right.normalize();
    up.normalize();
    return cam.getDirection() + right * dir.getX() + up * dir.getY();
}

void Renderer::worker(std::vector<int> coords, Camera cam, Scene scene, Environment &env,
std::vector<std::shared_ptr<Light>> lights, std::vector<std::vector<Color>> &image, std::pair<int, int> tileSize)
{
    try {
        Ray ray;

        for (double i = coords[0] * tileSize.first; i < coords[0] * tileSize.first + coords[2]; i++) {
            for (double j = coords[1] * tileSize.second; j < coords[1] * tileSize.second + coords[3]; j++) {
                ray.setColor(Color(0, 0, 0));
                ray.setOrigin(cam.getPosition());
                double aspectRatio = cam.getWidth() / cam.getHeight();
                double x = (1 - 2 * (j + 0.5) / cam.getHeight()) * std::tan(cam.getFov() / 2);
                double y = (2 * (i + 0.5) / cam.getWidth() - 1) * aspectRatio * std::tan(cam.getFov() / 2);
                ray.setDirection(getDirection(cam, Vector3d(x, y, 0)));
                ray.normalize();
                Ray r;
                r.setColor(Color(0, 0, 0));
                r.setDirection(ray.getDirection());
                r.setOrigin(ray.getOrigin());
                for (auto &light : lights) {
                    scene.traceRay(r, light, env);
                    ray.setColor(ray.getColor() + r.getColor());
                }
                ray.clamp();
                image[i][j] = ray.getColor();
            }
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Renderer::processTask(Array &tasks, Scene &scene, std::map<int, Scene> &scenes,
std::vector<std::future<void>> &futures, Array &run,
Image &img, const std::pair<int, int> &tileSize)
{
    if (!tasks.empty()) {
        std::vector<int> task = std::move(tasks.front());
        tasks.erase(tasks.begin());

        int id = task[0] * getNumThreads() + task[1];
        Scene s;
        for (auto &obj : scene.getObjects()) {
            std::shared_ptr<AObject> clone = obj->clone();
            s.addObject(clone);
        }
        scenes.emplace(id, s);
        if (!task[2] || !task[3])
            return;
        futures.emplace_back(std::async(std::launch::async,
        [this, id, task, &run, &img, scenes, tileSize, &scene]() {
            auto a = std::chrono::system_clock::now();
            worker(task, scene.getCamera(), scenes.at(id), scene.env, scene.getLights(), img, tileSize);
            auto b = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = b - a;
            run.erase(std::remove(run.begin(), run.end(), task), run.end());
        }));
    }
}

void Renderer::initializeRender(Scene& scene, int sfml, Image& img,
std::pair<int, int> &tileSize, Array& tasks)
{
    _render = false;
    _effect = scene.getEffect();
    img = Image(scene.getCamera().getWidth(),
        std::vector<Color>(scene.getCamera().getHeight(), Color(0, 0, 0)));
    if (sfml)
        _image.create(scene.getCamera().getWidth(), scene.getCamera().getHeight());
    tasks = generateTasks({scene.getCamera().getWidth(), scene.getCamera().getHeight()}, tileSize, tasks);
    sortTasks(tasks, {scene.getCamera().getWidth(), scene.getCamera().getHeight()}, tileSize);
    std::cout << "Running with " << getNumThreads() << " threads" << std::endl;
}

void Renderer::handleRenderCompletion(Image& img,
bool& _render, int sfml, std::chrono::system_clock::time_point& start)
{
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    if (start != end && _num == 0) {
        if (elapsed_seconds.count() >= 60)
            std::cout << "Generate time: " <<  (int)(elapsed_seconds.count() / 60) << "m "
                << (int)elapsed_seconds.count() % 60 << "s" << std::endl;
        else
            std::cout << "Generate time: " <<  elapsed_seconds.count() << "s" << std::endl;
        _num++;
    }
    applyPostProcessing(img, _render);
    if (sfml) {
        drawImage(img);
        start = end;
    }
}

void Renderer::saveImage(Image& img, int sfml)
{
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string file = "Image " + std::string(ctime(&now)).substr(0, 24) + ".ppm";
    std::replace(file.begin(), file.end(), ' ', '_');
    if (!sfml) {
        Exporter exporter;
        std::cout << "Saving image..." << std::endl;
        exporter.writeImage(file, img);
    }
}

void Renderer::render(Scene scene, int sfml)
{
    std::vector<std::future<void>> futures;
    Array tasks;
    Image img;
    Array run;
    std::pair<int, int> tileSize = TILE_SIZE;

    initializeRender(scene, sfml, img, tileSize, tasks);
    auto start = std::chrono::system_clock::now();
    while (_window.isOpen() || sfml == 0) {
        std::map<int, Scene> scenes;
        for (int i = 0; i < getNumThreads() - (int)futures.size(); i++)
            processTask(tasks, scene, scenes, futures, run, img, tileSize);
        removeCompletedFutures(futures);
        if (sfml) {
            eventHandler();
            _window.clear();
            drawImage(img);
            drawTasks(tasks, tileSize);
            drawRunningTasks(run, tileSize);
        }
        if (tasks.empty() && futures.empty()) {
            handleRenderCompletion(img, _render, sfml, start);
            if (!sfml)
                break;
        }
        _window.display();
    }
    saveImage(img, sfml);
}
