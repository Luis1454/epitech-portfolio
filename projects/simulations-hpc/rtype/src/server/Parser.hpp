// Parser.hpp
#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <getopt.h>
#include <string>
#include <vector>

typedef struct CommandLineOptions {
    bool showHelp = false;
    bool showVersion = false;
    int port;
} CLO;

class Parser {
    public:
        Parser();
        ~Parser();

        CLO parseCommandLine(int argc, char *argv[]);
        void help();
        void version();
};

#endif // PARSER_HPP
