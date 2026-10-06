/*
** EPITECH PROJECT, 2024
** Parser.hpp
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <memory>
#include <vector>
#include <functional>
#include "Factory.hpp"
#include "AComponent.hpp"

namespace nts {
    typedef std::vector<std::vector<std::string>> line_t;

    class Parser {
        public:
            Parser(std::string const &filename);
            Parser();
            ~Parser();

            void getContent();
            void handleKeyword(const nts::line_t &content, const std::string &keyword);

            void checkMinSpecs(const nts::line_t &content);

            void checkChipsets(const nts::line_t &content);
            void checkChipsetsDesc(const nts::line_t &content);

            void checkLinks(const nts::line_t &content);
            void checkLinksDesc(const nts::line_t &content);

            void testLinkDescA(const std::string &pin);
            void testLinkDescB(const std::string &pin);

            bool isPinUsed(const std::string &chipset, const std::size_t pin);

            std::vector<std::string> getChipsets() const {return _chipsets;}
            std::vector<std::string> getChipsetsPrebuilt() const {return _chipsetsType;}
            line_t getLinks() const {return _links;}

        private:
            std::string _filename;
            line_t _content;
            std::vector<std::string> _chipsets;
            std::vector<std::string> _chipsetsType;
            line_t _links;
    };
}

#endif /* !PARSER_HPP_ */
