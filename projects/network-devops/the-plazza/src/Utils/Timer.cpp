/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Timer
*/

#include "../../include/Utils/Timer.hpp"

Timer::Timer()
{
    _done = false;
    _running = false;
}

Timer::~Timer()
{
    stop();
}

void Timer::start(int duration, std::function<void()> timeoutCallback)
{
    stop();
    _done = false;
    _running = true;
    _thread = std::thread([this, duration, timeoutCallback]() {
        for (int i = 0; i < duration * 10; ++i) {
            {
                std::lock_guard<std::mutex> lock(_mutex);
                if (_done) return;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (!_done) {
                timeoutCallback();
                _running = false;
            }
        }
    });
}

void Timer::stop()
{
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (_running)
            _done = true;
    }
    if (_thread.joinable())
        _thread.join();
    _running = false;
}
