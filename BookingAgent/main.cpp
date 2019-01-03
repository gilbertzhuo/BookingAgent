#include <iostream>
#include "Constant.h"
#include "FlightTicket.h"
#include "RequestGenerator.h"
#include "TravelAgent.h"
#include "SmartTravelAgent.h"

int main() {
    int choice;
    do {
        do {
            cout << "Choose a class to test:" << endl;
            cout << "1. Test basic classes with Simple Travel Agent" << endl;
            cout << "2. Test basic classes with Smart Travel Agent" << endl;
            cout << "3. Test request generator class with Simple Travel Agent" << endl;
            cout << "4. Test request generator class with Smart Travel Agent" << endl;
            cout << "5. Quit" << endl;
            cin >> choice;
        } while (choice < 1 || choice > 5);

        switch (choice) {
            case 1: {
                TravelAgent TA("requestList.txt");
                TA.makePackages();
                TA.summary();
                break;
            }

            case 2: {
                SmartTravelAgent STA("requestList.txt");
                STA.makePackages();
                STA.summary();
                break;
            }

            case 3: {
                RequestGenerator("Generated.txt");
                TravelAgent TA("Generated.txt");
                TA.makePackages();
                TA.summary();
                break;
            }

            case 4: {
                RequestGenerator("Generated.txt");
                SmartTravelAgent STA("Generated.txt");
                STA.makePackages();
                STA.summary();
                break;
            }
            case 5: {
                exit(0);
            }

        }

    } while (choice != 5);
};