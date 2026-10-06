/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** main.cpp
*/

#include "../include/Core.hpp"
#include "../include/Player.hpp"
#include <thread>

void print_usage(const char* program_name) {
    std::cout << "USAGE: " << program_name << " -p port -h machine\n";
    std::cout << "option description\n";
    std::cout << "-p port        port number\n";
    std::cout << "-h machine     hostname of the server\n";
}

int main(int ac, char **av) {
    try {
        int port = -1;
        Renderer gui;
        std::string machine;
        ServerConnect connect;

        if (ac == 2 && !(std::string(av[1]).compare("-help")))
            print_usage(av[1]);
        else if (ac != 5)
            throw err::NotEnoughArguments();
        else {
            for (int i = 1; i < ac; ++i) {
                std::string arg = av[i];
                if (arg == "-p") {
                    if (i + 1 < ac) {
                        port = std::atoi(av[++i]);
                        if (port <= 0)
                            throw err::InvalidPortNumber();
                    } else
                        throw err::NoPortNumberProvided();
                } else if (arg == "-h") {
                    if (i + 1 < ac)
                        machine = av[++i];
                    else
                        throw err::NoMachineNameProvided();
                } else
                    throw err::UnknownOption(arg);
            }
        }
        connect.connectToServer(machine, port);
        connect.sendMessage("GRAPHIC\n", 100);
        connect.sendMessage("msz\n");
        for (int i = 0; i < 10; i++) {
            connect.sendMessage("ppo " + std::to_string(i) + "\n");
            connect.sendMessage("plv " + std::to_string(i) + "\n");
        }
        while (gui.getWindow().isOpen()) {
            gui.eventHandler();
            connect.receiveMessages();
            std::vector<std::shared_ptr<Cmd>> cmds = connect.getCommands();
            for (auto &cmd : cmds)
                cmd->execute(gui);
            gui.setResolution(gui.getWindow().getSize());
            double mn = std::min(gui.getResolution().x, gui.getResolution().y);
            mn = std::max(mn, 1.0);
            if (gui.getMap("default").getShape().second) {
                double aspect_ratio = (double)gui.getMap("default").getShape().first / gui.getMap("default").getShape().second;
                if (aspect_ratio > 1)
                    gui.getMap("default").setSize(sf::Vector2f(mn, mn / aspect_ratio));
                else
                    gui.getMap("default").setSize(sf::Vector2f(mn * aspect_ratio, mn));
            }
            gui.getMap("default").updateShape();
            gui.getMap("default").updatePos((sf::Vector2f)gui.getResolution());
            gui.updateScoreboard();
            gui.render();
        }
    } catch (const err::InvalidArgument& e) {
        std::cerr << e.what() << "\n";
        print_usage(av[0]);
        return MY_EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
