#ifndef FINAL_FLIGHTTICKET_H
#define FINAL_FLIGHTTICKET_H

#include "Ticket.h"
#include <iostream>
using namespace std;
class FlightTicket: public Ticket {
public:
    bool arrival;
    FlightTicket(int _date, bool _arrival);
    void printTicket();
};


#endif
