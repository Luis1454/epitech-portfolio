/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

CLO Parser::parseCommandLine(int argc, char *argv[])
{
    CLO options;

    try {
        int option_index = 0;
        int c;

        struct option long_options[] = {
            {"help", no_argument, nullptr, 'h'},
            {"version", no_argument, nullptr, 'v'},
            {"port", required_argument, nullptr, 'p'},
            {0, 0, 0, 0}
        };

        while ((c = getopt_long(argc, argv, "hvp:", long_options, &option_index)) != -1) {
            switch (c) {
                case 'h':
                    help();
                    options.showHelp = true;
                    break;
                case 'v':
                    version();
                    options.showVersion = true;
                    break;
                case 'p':
                    options.port = std::stoi(optarg);
                    break;
                case '?':
                    break;
                default:
                    abort();
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Parser error: " << e.what() << std::endl;
    }

    return options;
}

void Parser::help()
{
    std::cout << "Usage: [options]\n"
              << "Options:\n"
              << "  -h, --help       Show this help message\n"
              << "  -v, --version    Show version information\n"
              << "  -p, --port       Specify port number\n";
}

void Parser::version()
{
    std::cout << "Version 1.0\n";
}
