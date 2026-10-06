/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Timer
*/

#ifndef TIMER_HPP_
    #define TIMER_HPP_

    #include <vector>
    #include <thread>
    #include <atomic>
    #include <chrono>
    #include <functional>

class Timer {
    public:
        Timer();
        ~Timer();
        void stop();
        void start(int duration, std::function<void()> timeoutCallback);
    private:
        std::atomic<bool> _done;
        std::atomic<bool> _running;
        std::thread _thread;
        std::mutex _mutex;
};

#endif /* !TIMER_HPP_ */
