/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Cmd.cpp
*/

#include "../../include/Commands/Cmd.hpp"
#include "../../include/Commands/Bct.hpp"
#include "../../include/Commands/Msz.hpp"
#include "../../include/Commands/Pnw.hpp"
#include "../../include/Commands/Ppo.hpp"
#include "../../include/Commands/Plv.hpp"
#include "../../include/Commands/Pdi.hpp"
#include "../../include/Commands/Tna.hpp"
#include "../../include/Commands/Ebo.hpp"
#include "../../include/Commands/Edi.hpp"
#include "../../include/Commands/Seg.hpp"
#include "../../include/Commands/Smg.hpp"
#include "../../include/Commands/Suc.hpp"
#include "../../include/Commands/Sbp.hpp"
#include "../../include/Commands/Sst.hpp"
#include "../../include/Commands/Sgt.hpp"
#include "../../include/Commands/Pic.hpp"
#include "../../include/Commands/Pie.hpp"
#include "../../include/Commands/Pin.hpp"
#include "../../include/Commands/Enw.hpp"
#include "../../include/Commands/Pin.hpp"

Cmd::Cmd()
{
}

Cmd::~Cmd()
{
}

void Cmd::setArgs(std::vector<std::string> args)
{
    _args = args;
}

std::vector<std::string> Cmd::getArgs()
{
    return _args;
}

void Cmd::setName(std::string name)
{
    _name = name;
}

std::string Cmd::getName()
{
    return _name;
}

std::shared_ptr<Cmd> Cmd::getCommand(std::vector<std::string> args)
{
    std::shared_ptr<Cmd> cmd = nullptr;

    if (args[0] == "bct")
        cmd = std::make_shared<Bct>();
    if (args[0] == "msz")
        cmd = std::make_shared<Msz>();
    if (args[0] == "pnw")
        cmd = std::make_shared<Pnw>();
    if (args[0] == "ppo")
        cmd = std::make_shared<Ppo>();
    if (args[0] == "plv")
        cmd = std::make_shared<Plv>();
    if (args[0] == "pdi")
        cmd = std::make_shared<Pdi>();
    if (args[0] == "tna")
        cmd = std::make_shared<Tna>();
    if (args[0] == "ebo")
        cmd = std::make_shared<Ebo>();
    if (args[0] == "edi")
        cmd = std::make_shared<Edi>();
    if (args[0] == "seg")
        cmd = std::make_shared<Seg>();
    if (args[0] == "enw")
        cmd = std::make_shared<Enw>();
    if (args[0] == "pin")
        cmd = std::make_shared<Pin>();
    if (cmd == nullptr)
        return nullptr;
    cmd->setName(args[0]);
    args.erase(args.begin());
    cmd->setArgs(args);
    return cmd;
}

std::vector<std::shared_ptr<Cmd>> Cmd::split(const std::string& request)
{
    std::istringstream commandStream(request);
    std::string cmd;
    std::vector<std::shared_ptr<Cmd>> commands = {};

    while (std::getline(commandStream, cmd, '\n')) {
        if (cmd.empty())
            continue;
        std::istringstream argStream(cmd);
        std::vector<std::string> args;
        std::string arg;

        while (std::getline(argStream, arg, ' '))
            args.push_back(arg);

        std::shared_ptr<Cmd> cmd = Cmd::getCommand(args);
        if (cmd != nullptr)
            commands.emplace_back(std::move(cmd));
    }
    return commands;
}

void Cmd::execute(Renderer &gui)
{
    (void)gui;
}
