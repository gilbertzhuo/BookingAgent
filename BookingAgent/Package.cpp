#include "Package.h"


double Package::getProfit(){
    double flightsHotelTotal = 0;
    double eventsTotal = 0;
    for(FlightTicket ft: fTickets) {
        flightsHotelTotal += ft.getTicketPrice();
    }
    for(HotelVoucher hv: hVouchers) {
        flightsHotelTotal += hv.getTicketPrice();
    }
    for(EventTicket et: eTickets) {
        eventsTotal += et.getTicketPrice();
    }

    return flightsHotelTotal*0.05+eventsTotal*0.1;
}

double Package::totalCost(){
        double total = 0;
        for(FlightTicket ft: fTickets) {
            total += ft.getTicketPrice();
        }
        for(HotelVoucher hv: hVouchers) {
            total += hv.getTicketPrice();
        }
        for(EventTicket et: eTickets) {
            total += et.getTicketPrice();
        }
        return total;
}

void Package::printPackage(){
    cout<<"Client "<<cNo.cId<<": The package contains : "<<endl;;
    for(FlightTicket ft: fTickets) {
        ft.printTicket();
    }
    for(HotelVoucher hv: hVouchers) {
        hv.printTicket();
    }
    for(EventTicket et: eTickets) {
        et.printTicket();
    }
    cout <<"Total cost of the package is $"<< totalCost()<<endl;
    cout <<"Total profit of the package is $"<<getProfit()<<endl;
    cout << (isPackageValid()?("The package is valid\n\n"):("The package is invalid\n\n"));


}

bool Package::isPackageValid(){
    //The date of fly-in ticket is earlier than the date of fly-out ticket
    int arrival, departure;
    for(FlightTicket ft: fTickets){
        if(ft.arrival){
            arrival = ft.getDate();
        }
        else{
            departure = ft.getDate();
        }
    }
    if(arrival > departure){
        return false;
    }

    //Hotel rooms cover every night between the arrival and departure date
    for(int i = arrival; i<departure;i++){
        bool valid = false;
        for(HotelVoucher hv: hVouchers) {
            if(hv.getDate()==i){
                valid=true;
                break;
            }
        }
        if(valid==false){
            return false;
        }

    }

    //Hotel type is the same or better
    for(HotelVoucher hv: hVouchers) {
        if(hv.HotelStar<cNo.hotelType){
            return false;
        }
    }

    //All the events ticket should be in the dates between arrival and departure
    for(EventTicket et: eTickets) {
        if(et.getDate()< arrival|| et.getDate()>departure){
            return false;
        }
    }

    //There must be at least one event
    if(eTickets.size()==0){
        return false;
    }

   // Only events that client request is included in the package
    for(EventTicket et: eTickets) {
        if(cNo.events[et.eventNo]==false){
            return false;
        }
   }

    //Total cost should not exceed client budget
    if(totalCost()>cNo.budget){
        return false;
    }

    return true;
}