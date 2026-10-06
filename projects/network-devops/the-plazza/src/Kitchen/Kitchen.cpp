/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Kitchen.cpp
*/

#include "../../include/Kitchen/Kitchen.hpp"

Kitchen::Kitchen(float cookingTime, int numberOfCooks, float restockTime, std::vector<int> pipefd)
{
    _cookingTime = cookingTime;
    _numberOfCooks = numberOfCooks;
    _restockTime = restockTime;
    _secondpipefd = pipefd;
}

Kitchen::~Kitchen()
{
}

void Kitchen::writeInLogFile(std::string pizza, std::string size, std::string number, std::string kitchen)
{
    std::ofstream file("kitchen.log", std::ios::app);

    if (file.is_open()) {
        file << "Kitchen nb " << kitchen << " is cooking " << number << " " << size << " " << pizza << std::endl;
        file.close();
    }
}

std::string Kitchen::readMessage(std::vector<int> pipefd)
{
    std::string message;
    Reciever recept;
    recept.recieveMessage(pipefd);
    message = recept.getMessage();
    return message;
}

void Kitchen::revieveFromReception(std::vector<int> pipefd)
{
    std::string message;
    Reciever recept;
    recept.recieveMessage(pipefd);
    std::string receivedMessage = recept.getMessage();
    Message msg;
    msg < receivedMessage;
    _NumberPizza = msg.getNumber();
    _KitchensId = msg.getKitchen();
    _PizzaId = msg.getPizza();
    _SizeId = msg.getSize();
}

void Kitchen::sendToReception(std::string msg)
{
    Sender sender;
    sender.prepareMessage(msg);
    sender.sendMessage(_secondpipefd);
}

#include "../../include/Kitchen/Cook.hpp"

void Kitchen::createCook(int nbCooks, int _PizzaId, int _NumberPizza,
    int _SizeId, Stock &stock, std::mutex &stockMtx, int &nbPizzaCook)
{
    Cook cook(nbCooks, _PizzaId, _NumberPizza, _SizeId, stock, stockMtx, nbPizzaCook);
}

void Kitchen::startKitchen(std::vector<int> pipefd)
{
    PizzaTools piz;
    Stock stock;

    revieveFromReception(pipefd);
    std::cout << "Kitchen nb " << _KitchensId << " is cooking " << _NumberPizza << " "
        << piz.getPizzaSizeWithNumber(_SizeId) << " " << piz.getPizzaStringWithNumber(_PizzaId) << std::endl;
    ThreadPool pool(_numberOfCooks);
    int CookId = 0;
    std::mutex mtx;
    std::mutex stockMtx;
    int PizzaId = _PizzaId;
    int NumberPizza = _NumberPizza;
    int SizeId = _SizeId;

    int nbPizzaCook = 0;

    for (int i = 0; i < _numberOfCooks; i++) {
        pool.enqueue([&CookId, &mtx, &stockMtx, &PizzaId, &NumberPizza, &SizeId, &stock, &nbPizzaCook] {
            std::lock_guard<std::mutex> lock(mtx);

            createCook(CookId, PizzaId, NumberPizza, SizeId, stock, stockMtx, nbPizzaCook);
            CookId++;
        });
    }
    writeInLogFile(std::to_string(_PizzaId), std::to_string(_SizeId),
        std::to_string(_NumberPizza), std::to_string(_KitchensId));
    std::this_thread::sleep_for(std::chrono::milliseconds((std::size_t)_cookingTime + 10));
    sendToReception("done");
}
