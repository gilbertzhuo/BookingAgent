#include "HotelVoucher.h"

   HotelVoucher :: HotelVoucher(int _date, int _HotelStar, double _discount):Ticket(_date,hotelPriceMap[_HotelStar-3]){
        HotelStar = _HotelStar;
        discount = _discount;

}
void HotelVoucher::printTicket(){
    cout<< "Hotel voucher for a " << HotelStar << " star room on day "<< date << " at price $" << Ticket::getTicketPrice() << endl;
}
