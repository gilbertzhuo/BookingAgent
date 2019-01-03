#ifndef FINAL_CLIENTREQUEST_H
#define FINAL_CLIENTREQUEST_H

#include <iostream>
#include "Constant.h"
#include <iomanip>
using namespace std;

class ClientRequest {
private:

public:
    int cId;
    int hotelType;
    bool events[NUMBEROFEVENTS];
    int budget;

    ClientRequest();

    int earliestEventDate();

    int latestEventDate();

    void print();
};
#endif