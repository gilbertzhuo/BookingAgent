#ifndef FINAL_HOTELVOUCHER_H
#define FINAL_HOTELVOUCHER_H


#include "Ticket.h"
#include "iostream"
#include "Constant.h"

class HotelVoucher: public Ticket {
public:
    int HotelStar;
    HotelVoucher(int _date, int _HotelStar, double _discount);

    void printTicket();


};


#endif //FINAL_HOTELVOUCHER_H
