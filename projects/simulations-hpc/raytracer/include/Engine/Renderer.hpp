/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
    #define RENDERER_HPP_

    #include <SFML/Graphics.hpp>
    #include <future>
    #include <iostream>
    #include <vector>

    #include "../Physics/Color.hpp"
    #include "../Parser/Parser.hpp"
    #include "Camera.hpp"
    #include "Scene.hpp"

typedef std::vector<std::vector<int>> Array;

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void initWindow(Camera camera);
        void initializeRender(Scene& scene, int sfml, Image& img, std::pair<int, int>& tileSize, Array& tasks);
        void render(Scene scene, int sfml);
        void worker(std::vector<int> coords, Camera cam, Scene scene, Environment &env, std::vector<std::shared_ptr<Light>> lights, std::vector<std::vector<Color>> &image, std::pair<int, int> tileSize);
        Array generateTasks(const std::pair<int, int>& size, const std::pair<int, int>& tileSize, Array& tasks);
        void sortTasks(Array &tasks, const std::pair<int, int>& size, const std::pair<int, int>& tileSize);
        void processTask(Array& tasks, Scene& scene, std::map<int, Scene>& rayTracers,
            std::vector<std::future<void>>& futures, Array& run, Image& img, const std::pair<int, int>& tileSize);
        void eventHandler();
        void removeCompletedFutures(std::vector<std::future<void>>& futures);
        void drawImage(Image& img);
        void drawTasks(const Array& tasks, const std::pair<int, int>& tileSize);
        void drawRunningTasks(const Array& run, const std::pair<int, int>& tileSize);
        void applyPostProcessing(Image& img, bool &_render);
        void handleRenderCompletion(Image& img, bool& _render, int sfml, std::chrono::system_clock::time_point& start);
        void saveImage(Image& img, int sfml);

        Vector3d getDirection(Camera cam, Vector3d dir);
        int getNumThreads();
        sf::RenderWindow &getWindow();
        sf::Event &getEvent();
        sf::Image &getImage();
        sf::Texture &getTexture();
        sf::Sprite &getSprite();

    private:
        bool _render;
        int _num;
        int _numThreads;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Image _image;
        sf::Texture _texture;
        sf::Sprite _sprite;
        effect_t _effect;
        Clamp _clamp;
};

#endif /* !RENDERER_HPP_ */
