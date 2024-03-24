#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <atomic>
#include <condition_variable>

#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP


class ThreadPool {


    ThreadPool(const int threads_cnt = max_threads);
    void Worker();
    void AddTask(const std::function<void()> & task);
    void Terminate();

    private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::atomic<bool> run {false};
    std::mutex task_mutex;
    std::condition_variable cv_new_task;
    inline static unsigned int max_threads = std::thread::hardware_concurrency();
};

#endif // THREADPOOL_HPP