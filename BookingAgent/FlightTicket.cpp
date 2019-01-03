#include "FlightTicket.h"

FlightTicket::FlightTicket(int _date, bool _arrival): Ticket(_date,2000){
    arrival = _arrival;
    discount = (arrival?0.05*date : 0.05*(9-date));
}

void FlightTicket::printTicket(){
    cout << "Flight ticket from " << (arrival ? "Sydney to Tokyo" : "Tokyo to Sydney") << " on day " << date << " at price $" << getTicketPrice() << endl;
};