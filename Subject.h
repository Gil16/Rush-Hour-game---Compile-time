#ifndef OOP5_SUBJECT_H
#define OOP5_SUBJECT_H

#include "Observer.h"
#include "OOP5EventException.h"
#include "list"
#include <algorithm>

template <typename T>
class Subject {
    std::list<Observer<T>*> *observers;

public:
    Subject() {
        this->observers = new std::list<Observer<T>*>;
    }
    ~Subject(){
        delete observers;
    }
    void notify(const T&);
    void addObserver(Observer<T>&);
    void removeObserver(Observer<T>&);
    Subject<T>& operator+=(Observer<T>&);
    Subject<T>& operator-=(Observer<T>&);
    Subject<T>& operator()(const T&);
};


template<typename T>
void Subject<T>::notify(const T& message) {
    for(Observer<T>* it : *observers){
        it->handleEvent(message);
    }
}

template<typename T>
void Subject<T>::addObserver(Observer<T>& ob) {
    if((std::find(observers->begin(), observers->end(), &ob) != observers->end())){
        throw ObserverAlreadyKnownToSubject();
    }
    observers->push_back(&ob);
}

template<typename T>
void Subject<T>::removeObserver(Observer<T>& ob) {
    if((std::find(observers->begin(), observers->end(), &ob)) != observers->end()){      // theoretical ?end?
        observers->remove(&ob);
    }
    throw ObserverUnknownToSubject();
}

template<typename T>
Subject<T> &Subject<T>::operator+=(Observer<T>& ob) {
    this->addObserver(ob);
    return (*this);
}

template<typename T>
Subject<T> &Subject<T>::operator-=(Observer<T> &ob) {
    this->removeObserver(ob);
    return (*this);
}

template<typename T>
Subject<T> &Subject<T>::operator()(const T &message) {
    this->notify(message);
    return (*this);
}


#endif //OOP5_SUBJECT_H
