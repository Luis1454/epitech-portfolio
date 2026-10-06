/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** thread_pool.cpp
*/

#include "../../include/Kitchen/ThreadPool.hpp"

ThreadPool::ThreadPool(std::size_t numThreads)
{
    _numThreads = numThreads;
    _stop = false;

    assignTasks();
}

void ThreadPool::setNumThreads(std::size_t numThreads)
{
     _numThreads = numThreads;
}

void ThreadPool::assignTasks()
{
    for (size_t i = 0; i < _numThreads; ++i)
        if (_threads.size() < _numThreads)
            _threads.emplace_back(&ThreadPool::workerThread, this);
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(_queueMtx);
        _stop = true;
    }
    _cond.notify_all();
    for (std::thread& worker : _threads)
        worker.join();
}

#include <iostream>

void ThreadPool::enqueue(std::function<void()> f)
{
    {
        std::unique_lock<std::mutex> lock(_queueMtx);
        _tasks.emplace(std::move(f));
    }
    _cond.notify_one();
}

bool ThreadPool::isStop()
{
    return _stop;
}

void ThreadPool::workerThread()
{
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(_queueMtx);
            _cond.wait(lock, [this] { return _stop || !_tasks.empty(); });
            if (_stop && _tasks.empty())
                return;
            task = std::move(_tasks.front());
            _tasks.pop();
        }
        task();
        if (_tasks.empty())
            break;
    }
    _stop = true;
}
