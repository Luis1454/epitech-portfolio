#include "story.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

Story::Story() {
    // Charger la police
    if (!font.loadFromFile("src/client/assets/nasa.otf")) {
        throw std::runtime_error("Impossible de charger la police.");
    }

    // Charger l'image de fond
    if (!backgroundTexture.loadFromFile("src/client/assets/bcg.png")) {
        throw std::runtime_error("Impossible de charger l'image de fond.");
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Configurer le texte
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(50, 50);

    // Charger le texte de l'histoire depuis le fichier JSON
    try{
        std::string rawText = loadStoryFromJson("src/client/assets/story.json");
        storyText = wrapText(rawText, 1200.0f, font, 24); // Largeur maximale de 700 pixels
    } catch (const std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        storyText = "Erreur lors du chargement de l'histoire.";
    }

    std::cout << "Story constructor initialized" << std::endl;

    // Initialisation des variables
    visibleText = "";
    charIndex = 0;
    scrollSpeed = 0.05f;
}

// Charger l'histoire depuis un fichier JSON basique
std::string Story::loadStoryFromJson(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filePath);
    }

    std::string line;
    std::string storyKey = "\"story\":";
    std::string storyContent;
    bool foundStory = false;

    // Lire le fichier ligne par ligne
    while (std::getline(file, line)) {
        size_t pos = line.find(storyKey);
        if (pos != std::string::npos) {
            pos += storyKey.size();

            // Supprimer les espaces et les guillemets au début
            while (pos < line.size() && (line[pos] == ' ' || line[pos] == '\"'))
                pos++;
            
            // Lire le texte jusqu'à la fermeture des guillemets
            while (pos < line.size() && line[pos] != '\"')
                storyContent += line[pos++];

            foundStory = true;
            break;
        }
    }

    file.close();

    if (!foundStory || storyContent.empty()) {
        throw std::runtime_error("Clé 'story' introuvable ou vide dans le fichier.");
    }

    return storyContent;
}

// Mise à jour pour le défilement progressif du texte
void Story::update() {
    if (clock.getElapsedTime().asSeconds() > scrollSpeed && charIndex < storyText.size()) {
        visibleText += storyText[charIndex++];
        clock.restart();
        text.setString(visibleText);
    }
}

// Rendu du texte et du fond
void Story::render(sf::RenderWindow &window) {
    window.clear(); // Nettoyer la fenêtre avant de dessiner
    window.draw(backgroundSprite); // Dessiner l'image de fond
    window.draw(text); // Dessiner le texte visible
}

// Gestion des événements utilisateur
bool Story::handleEvents(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Tab) {
                // Affiche immédiatement tout le texte si Tab est pressé
                visibleText = storyText;
                charIndex = storyText.size();
                text.setString(visibleText);
            }
        }
    }
    return true;
}

std::string Story::wrapText(const std::string& text, float maxWidth, const sf::Font& font, unsigned int characterSize) {
    std::string wrappedText;
    std::string currentLine;
    std::string currentWord;
    float currentLineWidth = 0.0f;

    for (char c : text) {
        if (c == ' ' || c == '\n') {
            // Vérifie si le mot courant peut tenir sur la ligne
            sf::Text tempText(currentLine + currentWord, font, characterSize);
            if (tempText.getLocalBounds().width > maxWidth) {
                // Ajouter la ligne actuelle au texte final
                wrappedText += currentLine + '\n';
                currentLine = currentWord + c; // Commencer une nouvelle ligne avec le mot courant
            } else {
                // Ajouter le mot courant à la ligne actuelle
                currentLine += currentWord + c;
            }
            currentWord.clear(); // Réinitialiser le mot courant
        } else {
            // Construire le mot courant
            currentWord += c;
        }
    }

    // Ajouter la dernière ligne et le dernier mot
    if (!currentWord.empty()) {
        sf::Text tempText(currentLine + currentWord, font, characterSize);
        if (tempText.getLocalBounds().width > maxWidth) {
            wrappedText += currentLine + '\n' + currentWord;
        } else {
            wrappedText += currentLine + currentWord;
        }
    }

    return wrappedText;
}

// Boucle principale de l'application
void Story::run(sf::RenderWindow &window) {
    while (window.isOpen()) {
        if (!handleEvents(window)) break; // Gestion des événements
        update(); // Mise à jour du texte
        render(window); // Rendu du texte et du fond
        window.display(); // Afficher la fenêtre
    }
}
