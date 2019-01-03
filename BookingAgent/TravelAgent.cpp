#include "TravelAgent.h"

void TravelAgent::ReadText(){
        //Initialise String to be stored
        int Budget;
        int starHotel, Events,i=0,line;
        vector <int> E;

        while(file >> line){
            ClientRequest cr;
            Budget = line;
            cr.budget=Budget;
            cr.cId = i;
            char c;
            file >> c;
            if(c == ','){
                file >> starHotel;
                cr.hotelType=starHotel;
            }
            file >> c;

            while(c != ']'){
                file>>Events;
                cr.events[Events] = true;
                E.emplace_back(Events);
                file >> c;
            }
            cRequests.emplace_back(cr);

            i++;
        }


    }

double TravelAgent::gDiscount(int date, int hotelStar){
    double vacancy;
    switch(hotelStar){
        case 3:
            return 0.0;
        case 4:
            vacancy = hotelDailyQuota[1][date]/hotelQuota[1];
            if(vacancy > 0.5)
                return 0.2;
            else return 0.0;
        case 5:
            vacancy = hotelDailyQuota[2][date]/hotelQuota[2];
            if(vacancy > 0.5)
                return 0.4;
            else if (vacancy > 0.2)
                return 0.2;
            else return 0.0;

        default:
            return 0.0;

    }

}

void TravelAgent::purchaseFlightTickets(Package &p, int arrival, int departure){
    FlightTicket aft(arrival,true);
    FlightTicket dft(departure,false);
    p.fTickets.push_back(aft);
    p.fTickets.push_back(dft);
}

void TravelAgent::purchaseEventVoucher(Package &p,int eNo){
    if(dEventQuota[eNo]>0){
        EventTicket ev(eNo);
        p.eTickets.push_back(ev);
    }
}

void TravelAgent::purchaseHotelVoucher(Package & p,int date,int hotelStar){
    if(hotelDailyQuota[hotelStar-3][date]>0){
        HotelVoucher hv(date,hotelStar,gDiscount(date,hotelStar));
        p.hVouchers.push_back(hv);
    }
}

void TravelAgent::updateQuota(Package &p){
    for(EventTicket et: p.eTickets)
        dEventQuota[et.eventNo]--;
    for(HotelVoucher hv: p.hVouchers)
        hotelDailyQuota[hv.HotelStar-3][hv.getDate()]--;
}

void TravelAgent::summary(){
    cout<<"Summary of packages:"<<endl;
    cout<<"Total packages generated:"<< Packages.size()<<endl;
    cout<<"\nTotal hotel vouchers sold:"<<endl;
    cout<<"3 star hotel rooms"<<endl;
    for(int i = 0; NUMBEROFDAYS>i;i++){
        cout<< hotelQuota[0]-hotelDailyQuota[0][i]<<" ";
    }
    cout<<"\n4 star hotel rooms"<<endl;
    for(int i = 0; NUMBEROFDAYS>i;i++){
        cout<< hotelQuota[1]-hotelDailyQuota[1][i]<<" ";
    }
    cout<<"\n5 star hotel rooms"<<endl;
    for(int i = 0; NUMBEROFDAYS>i;i++){
        cout<< hotelQuota[2]-hotelDailyQuota[2][i]<<" ";
    }
    cout<<"\n\nTotal event tickets sold:"<<endl;
    for(int i = 0; i < NUMBEROFEVENTS;i++){
        cout<< eventQuota[i]-dEventQuota[i]<<" ";
    }
    cout<<"\n\nTotal Profit: $";
    double profits = 0;
    for(Package p:Packages){
        profits+= p.getProfit();
    }
    cout<<profits<<"\n\n\n"<<endl;

}

void TravelAgent::makePackages(){
    for(ClientRequest cr: cRequests){
        int arrival, departure;
        Package p(cr);
        arrival = cr.earliestEventDate();
        departure = cr.latestEventDate();

        purchaseFlightTickets(p,arrival,departure);

        //Loop through the dates and book the hotel
        for(int i = arrival; departure>i;i++) {
            purchaseHotelVoucher(p,i,cr.hotelType);
        }

        //Buy Event Voucher for those events that is true inside the boolean
        for(int i = 0;NUMBEROFEVENTS>i;i++){
            if(cr.events[i]){
                purchaseEventVoucher(p,i);
            }
        }

        //Check if the package is valid
        if(p.isPackageValid()){
            Packages.push_back(p);
            updateQuota(p);
            p.printPackage();
        }

    }
}

    TravelAgent::TravelAgent(string fileName){
    for(int i = 0; i<NUMBEROFEVENTS;i++){
        dEventQuota[i] = eventQuota[i];
    }
    for(int i=0; i<NUMBEROFDAYS;i++){
        hotelDailyQuota[0][i] = hotelQuota[0];
        hotelDailyQuota[1][i] = hotelQuota[1];
        hotelDailyQuota[2][i] = hotelQuota[2];
    }
    file.open(fileName);
    if(file.fail()){
        cout<<"Program cant open " << fileName <<endl;
        cout<<"Terminating"<<endl;
        exit(1);
    }
    ReadText();
    for(ClientRequest cr : cRequests){
        cr.print();
    }


}