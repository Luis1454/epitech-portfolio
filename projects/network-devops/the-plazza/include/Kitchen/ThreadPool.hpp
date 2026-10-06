/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** thread_pool.hpp
*/

#ifndef THREADPOOL_HPP
    #define THREADPOOL_HPP

    #include <queue>
    #include <mutex>
    #include <vector>
    #include <thread>
    #include <functional>
    #include <condition_variable>

class ThreadPool {
    public:
        ThreadPool() = default;
        ThreadPool(std::size_t numThreads);
        ~ThreadPool();
        void setNumThreads(std::size_t numThreads);
        void assignTasks();
        void enqueue(std::function<void()> f);
        void workerThread();
        bool isStop();

    private:
        std::vector<std::thread> _threads;
        std::queue<std::function<void()>> _tasks;
        std::mutex _queueMtx;
        std::condition_variable _cond;
        bool _stop;
        std::size_t _numThreads;
};

#endif /* THREADPOOL_HPP */
