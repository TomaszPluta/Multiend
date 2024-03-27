#ifndef MESSAGE_HPP
#define MESSAGE_HPP

template <typename T>
class Message {
    public:
    virtual T GetData() = 0;

    private:
    T data;
};

template <typename T>
class AckedMessage : public Message<T>{
    T GetData() override;
    private:
    bool ack;
};


class Metadata{};
class Destination{};





#endif // MESSAGE_HPP