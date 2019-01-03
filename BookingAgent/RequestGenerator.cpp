#include "RequestGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Constant.h"

using namespace std;

RequestGenerator::RequestGenerator(string fileName) {
    file.open(fileName);
    if(file.fail()){
        cout<<"Program cant open " << fileName <<endl;
        cout<<"Terminating"<<endl;
        exit(1);
    }
    generate();
}

void RequestGenerator::generate(){
    int numOfRequest = random(100,MAXREQUESTS);
    for(int i =0; numOfRequest>i;i++){
        int hotelStar = random(3,5);
        int numEvents = random(1,10);
        vector <int> events;
        for(int j =0; numEvents>j;j++){
            int num;
            do{
                num = random(0,14);
            }while(vectorContains(events,num) == false);
            events.push_back(num);

        }

        int budget = 0;
        if(vectorContains(events,0)){
            budget = random(4500+(150*numEvents),7500+(150*numEvents));
        }
        else if(vectorContains(events,14)){
            budget = random(3800+(150*numEvents),6800+(150*numEvents));
        }
        else{
            budget = random(3250+(150*numEvents),5250+(150*numEvents));
        }

        file<< budget<<","<<hotelStar<<"[";
        for(unsigned int i=0;i<events.size();i++){
            file<<events.at(i);
            if(i != events.size()-1){
                file<<",";
            }
        }
        file<<"]"<<endl;

    }
}

bool RequestGenerator::vectorContains(vector<int> events, int eventNo){
    for(int i : events){
        if(i==eventNo)
            return false;
    }
    return true;
}

int RequestGenerator::random(int min, int max){
    static bool first = true;
    if(first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max +1)-min);
}
