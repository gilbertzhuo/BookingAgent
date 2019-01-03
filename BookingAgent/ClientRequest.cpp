#include "ClientRequest.h"
ClientRequest::ClientRequest() {
        cId = -1;
        hotelType = -1;
        budget = -1;
        for (int i = 0; i < NUMBEROFEVENTS; i++)
            events[i] = false;
}
int ClientRequest::earliestEventDate() {
    int minDate = NUMBEROFDAYS;
    for (int i = 0; i < NUMBEROFEVENTS; i++){
        if (events[i] && eventDateMap[i]<minDate)
            minDate = eventDateMap[i];
    }
    return minDate;
}

int ClientRequest::latestEventDate() {
    int maxDate = 0;
    for (int i = 0; i < NUMBEROFEVENTS; i++){
        if (events[i] && eventDateMap[i]>maxDate)
            maxDate = eventDateMap[i];
    }
    return maxDate;
}

void ClientRequest::print() {
    cout << "Client " << cId << ":" << setw(8) << budget << setw(8) << hotelType;

    for (int i = 0; i < NUMBEROFEVENTS; i++) {
        if (events[i])
            cout << setw(8) << i;
    }
    cout << endl;
}