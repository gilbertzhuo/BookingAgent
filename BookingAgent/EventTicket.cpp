#include "EventTicket.h"

EventTicket::EventTicket(int _eventNo) : Ticket(eventDateMap[_eventNo],eventPriceMap[_eventNo]){
    eventNo = _eventNo;
    discount = 0.0;
}
void EventTicket::printTicket(){
    cout <<"Event ticket for " <<nameMap[eventNo] <<" on day " << date << " at price $"<<Ticket::getTicketPrice()<<endl;
}