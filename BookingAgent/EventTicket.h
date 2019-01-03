#ifndef FINAL_EVENTTICKET_H
#define FINAL_EVENTTICKET_H

#include "Ticket.h"
#include "Constant.h"
#include <iostream>

using namespace std;

class EventTicket: public Ticket {
public:
    int eventNo;
    EventTicket(int _eventNo);

    void printTicket();

};


#endif
