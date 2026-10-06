/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Message
*/

#ifndef MESSAGE_H_
    #define MESSAGE_H_

    #include <sstream>
    #include <iostream>

class Message {
    public:
        int getNumber() const;
        int getKitchen() const;
        int getSize() const;
        int getPizza() const;
        std::string getSerializedMessage() const;
        void unpack(const std::string& serialized);
        Message& operator<(const std::string& serialized);
        Message& operator>(const std::tuple<int, int, int, int>& data);
        void pack(int kitchen, int pizza, int size, int number);

    private:
        int number;
        int kitchen;
        int size;
        int pizza;
        std::string serialized_message;
};

#endif /* !MESSAGE_H_ */
