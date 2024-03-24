#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include "../include/ThreadPool.hpp"


   ThreadPool::ThreadPool(const int threads_cnt;){
        for (int i = 0; i < threads_cnt; i++){
            workers.emplace_back(std::thread(&ThreadPool::Worker, this));
        }
    }

    void ThreadPool::Worker(){
        while(run){
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lk (task_mutex);
                cv_new_task.wait(lk, [this](){return ((!tasks.empty()) || (!run));});
                if (!run){
                    return;
                }
            }
            task = tasks.front();
            tasks.pop();
            task();
        }
    }

    void ThreadPool::AddTask(const std::function<void()> & task){
        std::unique_lock<std::mutex> lk (task_mutex);
        tasks.emplace(task);
        cv_new_task.notify_one();
    }

    void ThreadPool::Terminate(){
        std::unique_lock<std::mutex> lk (task_mutex);
        run = false;
        cv_new_task.notify_all();
        for (std::thread & th : workers){
            th.join();
        }
        workers.clear();
    }


