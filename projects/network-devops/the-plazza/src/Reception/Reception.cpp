/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Reception
*/


#include "../../include/Utils/Message.hpp"
#include "../../include/Reception/Reception.hpp"

Reception::Reception()
{
    _cookingTime = 0;
    _numberOfCooks = 0;
    _restockTime = 0;
    _nbKitchens = 0;
}

Reception::Reception(float cookingTime, int numberOfCooks, float restockTime)
{
    _cookingTime = cookingTime;
    _numberOfCooks = numberOfCooks;
    _restockTime = restockTime;
    _nbKitchens = 0;
}

Reception::~Reception()
{
}

void Reception::startReception()
{
    std::cout << "Start Reception" << std::endl;
    std::cout << "Cooking Time: " << _cookingTime << std::endl;
    std::cout << "Number of Cooks: " << _numberOfCooks << std::endl;
    std::cout << "Restock Time (ms): " << _restockTime << std::endl;
    shell();
}

std::size_t Reception::nbKitchensToCreate(std::size_t nbCooks, std::size_t nbPizza)
{
    std::size_t totalCooks = nbCooks * 2;
    std::size_t nbKitchens = nbPizza / totalCooks;
    if (nbPizza % totalCooks != 0)
        nbKitchens++;
    return nbKitchens;
}

void Reception::sendToKitchen(const kitchenPreparation& kitchen, int index)
{
    Sender sender;
    PizzaTools piz;
    Message msg;
    msg > std::make_tuple(kitchen.id[index], piz.recupNumPizza(kitchen._command[index]),
    piz.recupNumSize(kitchen._size[index]), kitchen._number[index]);
    sender.prepareMessage(msg.getSerializedMessage());
    sender.sendMessage(kitchen._pipefd[index]);
}

void Reception::receiveFromKitchen(const kitchenPreparation& kitchen, int index)
{
    Reciever receiver;
    receiver.recieveMessage(kitchen._pipefd2[index]);
    std::string message = receiver.getMessage();
}

void Reception::createPipeLink(kitchenPreparation& kitchen, int index)
{
    int fd[2], fd2[2];
    pid_t pid;

    pipe_Utils.create(fd);
    pipe_Utils.create(fd2);
    kitchen._pipefd.push_back({fd[0], fd[1]});
    kitchen._pipefd2.push_back({fd2[0], fd2[1]});

    pid = fork_Utils.create();
    if (pid == 0) {
        Kitchen k(_cookingTime, _numberOfCooks, _restockTime, kitchen._pipefd2[index]);
        k.startKitchen(kitchen._pipefd[index]);
        exit(0);
    } else if (pid < 0)
        throw err::Error(err::List_error::FORK_FAILED);
}

int calc(int nbPizza, int nbKitchen, int idKitchen, int maxPizza)
{
    if (nbKitchen == 1)
        return (nbPizza > maxPizza) ? maxPizza : nbPizza;
    int basePizzas = nbPizza / nbKitchen;
    int extraPizzas = nbPizza % nbKitchen;
    int pizzasForThisKitchen = (idKitchen <= extraPizzas) ? (basePizzas + 1) : basePizzas;
    return (pizzasForThisKitchen > maxPizza) ? maxPizza : pizzasForThisKitchen;
}

std::vector<kitchenPreparation> Reception::createAllKitchens(std::vector<Shell>& shells)
{
    std::vector<kitchenPreparation> kitchens;
    int id = 1, numbKitchen = 0;

    for (auto& shell : shells) {
        kitchenPreparation tempKitchen;
        std::string nbr = shell.NUMBER;
        shell.NUMBER_INT = std::stoi(nbr.erase(0, 1));
        if (_nbKitchens != 0) {
            std::size_t t = nbKitchensToCreate(_numberOfCooks, shell.NUMBER_INT);
            numbKitchen = (t > _nbKitchens) ? t : _nbKitchens;
        } else
            numbKitchen = nbKitchensToCreate(_numberOfCooks, shell.NUMBER_INT);
        for (int j = 0; j < numbKitchen; ++j) {
            createPipeLink(tempKitchen, j);
            tempKitchen._command.push_back(shell.TYPE);
            tempKitchen._size.push_back(shell.SIZE);
            int numPizzas = calc(shell.NUMBER_INT, numbKitchen, j + 1, _numberOfCooks * 2);
            tempKitchen._number.push_back(numPizzas);
            tempKitchen.id.push_back(id++);
        }
        if (numbKitchen > (int)_nbKitchens)
            _nbKitchens += numbKitchen;
        kitchens.push_back(tempKitchen);
    }
    return kitchens;
}

void Reception::interpretCommand(const std::string& input)
{
    _parsing.parseShell(input);
    std::vector<Shell> shells = _parsing.getShell();
    _kitchens = createAllKitchens(shells);

    for (const auto& kitchen : _kitchens)
        for (std::size_t j = 0; j < kitchen._command.size(); ++j) {
            sendToKitchen(kitchen, j);
            receiveFromKitchen(kitchen, j);
        }
}

void Reception::shell()
{
    std::string input;
    _nbKitchens = 0;
    std::vector<Shell> shell;
    std::atomic<int> resetNbrKitch = 0;

    while (true) {
        std::cout << "S : ";
        resetNbrKitch = 0;
        if (_nbKitchens != 0)
            _timer.start(5, [&resetNbrKitch]() {
                std::cout << "\nClose kitchen not used!\nS : " << std::flush;
                resetNbrKitch = 1;
            });
        if (!std::getline(std::cin, input))
            break;
        if (resetNbrKitch == 1)
            _nbKitchens = 0;
        _timer.stop();
        if (input.empty())
            continue;
        if (input == "exit")
            break;
        interpretCommand(input);
    }
}
