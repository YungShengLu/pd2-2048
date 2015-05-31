#ifndef SUBJECT_H
#define SUBJECT_H

#include "Headerfile.h"

using namespace std;

class Observer;

class Subject {
public:
    Subject();

    void notifyObs();
    void registerObs(Observer *observer);

private:
    vector<Observer*> observers;
};

#endif // SUBJECT_H
