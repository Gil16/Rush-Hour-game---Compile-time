#ifndef OOP5_OBSERVER_H
#define OOP5_OBSERVER_H

template <typename T>
class Observer {

public:
    Observer(){};
    virtual void handleEvent(const T&) = 0;

    bool operator==(Observer& ob1){
        return (&ob1 == this);  // ??
    }
};




#endif //OOP5_OBSERVER_H
