#ifndef FINAL_SMARTTRAVELAGENT_H
#define FINAL_SMARTTRAVELAGENT_H


#include "TravelAgent.h"

class SmartTravelAgent: public TravelAgent {
public:

    SmartTravelAgent(string fileName): TravelAgent(fileName){
    };
    void makePackages();
};





















#endif //FINAL_SMARTTRAVELAGENT_H
