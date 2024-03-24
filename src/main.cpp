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

//message encapsulation (((data)id)ack)src,dst)
template <typename T>
class MessageApi{
    public:
        virtual T GetMessage() = 0;
        virtual bool Send() = 0;
    private:
        T m_id;
        T m_data;
};

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
