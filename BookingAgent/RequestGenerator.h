#ifndef FINAL_REQUESTGENERATOR_H
#define FINAL_REQUESTGENERATOR_H


#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class RequestGenerator {
private:
    ofstream file;
    //Random function that gives between the min and max
    int random(int min, int max);

    //Events validation
    bool vectorContains(vector<int> events, int eventNo);
public:

    RequestGenerator(string fileName);
    void generate();


};


#endif