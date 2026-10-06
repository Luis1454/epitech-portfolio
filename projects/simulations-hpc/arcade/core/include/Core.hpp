/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_

    #include <iostream>
    #include <ostream>
    #include <stdlib.h>
    #include <cstdlib>
    #include <string>
    #include <vector>
    #include <fstream>
    #include "../dlfonction/Dl.hpp"
    #include "Menu.hpp"
    #include <memory>

namespace arc {
    class ICore {
        public:
            ICore();
            ~ICore();
            std::unique_ptr<IDisplayModule> openGraphical(char *av, std::unique_ptr<IDisplayModule> displayModule);
            void mainloop(std::unique_ptr<IDisplayModule> displayModule);
        private:
            int key;
    };
}

#endif /* !ARCADE_HPP_ */
