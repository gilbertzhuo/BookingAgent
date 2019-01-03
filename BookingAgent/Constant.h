#ifndef FINAL_CONSTANT_H
#define FINAL_CONSTANT_H

#include <string>
using namespace std;

    const string nameMap[15] = { "Opening", "Soccer 1", "Soccer 2", "Soccer 3",
                                 "Track and Field 1", "Track and Field 2", "Track and Field 3",
                                 "Track and Field 4", "Swimming 1", "Swimming 2", "Gymnastics 1",
                                 "Gymnastics 2", "Basketball 1", "Basketball 2", "Closing" };
    const int eventPriceMap[15] = { 2000, 80, 160, 500, 80, 100, 120, 140, 100, 100, 60, 100,
                                    150, 300, 800 };

    const int eventDateMap[15] = { 0, 3, 6, 9, 1, 2, 3, 4, 5, 6, 7, 8, 5, 7, 9 };

    const int eventQuota[15] = {60, 47, 30, 22, 50, 52, 42, 25, 37, 20, 43, 34, 35, 30, 40};

    const int hotelPriceMap[3] = {160, 210, 320};

    const int hotelQuota[3] ={20, 25, 30};

    const int MAXREQUESTS = 150;

    const int NUMBEROFEVENTS = 15;

    const int NUMBEROFDAYS = 10;

#endif
