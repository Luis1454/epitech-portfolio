/*
** EPITECH PROJECT, 2024
** Parser.cpp
** File description:
** Parser
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Parser.hpp"

nts::Parser::Parser(std::string const &filename) {
    _filename = filename;
    try {
        getContent();
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        std::exit(84);
    }
}

nts::Parser::Parser() {}

nts::Parser::~Parser() {
    _filename.clear();
}

void nts::Parser::getContent() {
    std::ifstream file(_filename);
    nts::line_t content;
    std::string raw;

    if (_filename.find(".nts") == std::string::npos)
        throw std::invalid_argument("Invalid file extension (expected .nts).");
    if (!file.is_open())
        throw std::invalid_argument("File not found");
    while (std::getline(file, raw)) {
        std::vector<std::string> words;
        std::istringstream iss(raw);
        std::string word;

        while (iss >> word && word[0] != '#')
            words.push_back(word);
        if (!words.empty())
            content.push_back(words);
    }
    file.close();

    if (content.empty())
        throw std::invalid_argument("Empty file");
    checkChipsets(content);
    checkLinks(content);
    content.clear();
}

void nts::Parser::checkLinks(const nts::line_t &content) {
    try {
        handleKeyword(content, ".links:");
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        std::exit(84);
    }
    checkLinksDesc(content);
}

void nts::Parser::testLinkDescA(const std::string &pin) {
    if (pin.find(":") == std::string::npos)
        throw std::invalid_argument("Invalid link description \
(declaration does not match the a:pin b:pin format).");
    if (pin.find(":") != pin.rfind(":"))
        throw std::invalid_argument("Invalid link description (multiple ':' found).");

}

void nts::Parser::testLinkDescB(const std::string &pin) {
    std::string a = pin.substr(0, pin.find(":"));
    std::string b = pin.substr(pin.find(":") + 1, pin.size());

    if (a.empty() || b.empty())
        throw std::invalid_argument("Invalid link description ('"
        + pin + "' contains an empty value, expected a:b).");
    if (std::find(_chipsets.begin(), _chipsets.end(), a) == _chipsets.end())
        throw std::invalid_argument("Invalid link description ('"
        + a + "' is not a valid chipset).");
    if (!std::all_of(b.begin(), b.end(), ::isdigit) || std::stoi(b) < 1)
        throw std::invalid_argument("Invalid link description ('"
        + b + "' is not a valid pin).");
    if (isPinUsed(a, std::stoi(b)))
        throw std::invalid_argument("Invalid link description ('"
        + a + ":" + b + "' is already used).");

    if ((_links.empty() || _links.back().size() == 4))
        _links.push_back({a, b});
    else {
        _links.back().push_back(a);
        _links.back().push_back(b);
    }
}

void nts::Parser::checkLinksDesc(const nts::line_t &content) {
    auto it = std::find_if(content.begin(), content.end(),
    [](const std::vector<std::string> &l) {
        return l[0] == ".links:";
    });

    for (auto i = it + 1; i != content.end(); i++) {
        if (i->size() != 2)
            throw std::invalid_argument("Invalid link description (" +
            std::to_string(i->size()) + " arguments given, 2 expected).");
        for (const auto &pin : i[0]) {
            testLinkDescA(pin);
            testLinkDescB(pin);
        }
    }
}

void nts::Parser::checkChipsets(const nts::line_t &content) {
    std::vector<std::string> keywords = {".chipsets:", ".links:"};
    auto it = std::find_if(content.begin(), content.end(),
    [keywords](const std::vector<std::string> &l) {
        return l[0] == keywords[0] || l[0] == keywords[1];
    });

    if (it->at(0) == keywords[1])
        throw std::invalid_argument("Invalid file structure \
(chipsets must be declared before links).");

    try {
        handleKeyword(content, ".chipsets:");
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        std::exit(84);
    }
    checkChipsetsDesc(content);
}

void nts::Parser::checkChipsetsDesc(const nts::line_t &content) {

    auto it = std::find_if(content.begin(), content.end(),
    [](const std::vector<std::string> &l) {
        return l[0] == ".chipsets:";
    });

    for (auto i = it + 1; i != content.end(); i++) {
        if (i->at(0) == ".links:")
            break;
        if (i->size() != 2)
            throw std::invalid_argument("Invalid chipset description (" +
            std::to_string(i->size()) + " arguments given, 2 expected).");
        if (std::find(nts::specials.begin(), nts::specials.end(), i->at(0)) == nts::specials.end()
        && std::find(nts::logicals.begin(), nts::logicals.end(), i->at(0)) == nts::logicals.end()
        && std::find(nts::prebuilt.begin(), nts::prebuilt.end(), i->at(0)) == nts::prebuilt.end())
            throw std::invalid_argument("Invalid chipset description ('"
            + i->at(0) + "' is not a valid chipset).");
        if (std::find(_chipsets.begin(), _chipsets.end(), i->at(1)) != _chipsets.end())
            throw std::invalid_argument("Invalid chipset description (name '"
            + i->at(1) + "' already used).");
        _chipsets.push_back(i->at(1));
        _chipsetsType.push_back(i->at(0));
    }
    checkMinSpecs(content);
}

void nts::Parser::checkMinSpecs(const nts::line_t &content) {
    if (std::count_if(_chipsetsType.begin(), _chipsetsType.end(), [](const std::string &chipset)
    {return chipset == "input" || chipset == "clock"
    || chipset == "true" || chipset == "false";}) < 1)
        throw std::invalid_argument("No input, clock or boolean found.");
    if (std::count_if(_chipsetsType.begin(), _chipsetsType.end(), [](const std::string &chipset)
    {return chipset == "output";}) < 1)
        throw std::invalid_argument("No output found.");
}

void nts::Parser::handleKeyword(const nts::line_t &content, const std::string &keyword) {
    int link = std::count_if(content.begin(), content.end(),
    [keyword](const std::vector<std::string> &line) {
        return line[0] == keyword;
    });

    if (link != 1)
        throw std::invalid_argument(link > 1 ? "multiple "
        + keyword + " keys." : "no " + keyword + " key.");
}

bool nts::Parser::isPinUsed(const std::string &chipset, const std::size_t pin) {
    for (const auto &link : _links)
        if (link[0] == chipset && std::stoi(link[1]) == pin)
            return true;
    return false;
}
