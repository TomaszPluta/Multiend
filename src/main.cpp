#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include "../include/ThreadPool.hpp"
#include "../include/Message.hpp"




class Observer{
};


class Broker{
    private:
        ThreadPool pool;
        std::vector<std::shared_ptr<Observer>> observers;
    public:
        void Dispatch(){

        }
};





int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;
}
