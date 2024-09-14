#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib> 
#include <time.h> 

using namespace std;


class TimeMangment
{
public:

    static string getCurrentDateTime() {
        time_t currentTime;
        time(&currentTime);

        char buffer[80];

        struct tm timeInfo;
        localtime_s(&timeInfo, &currentTime);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeInfo);

        string dateTimeStr(buffer);

        return dateTimeStr;
    }

    // based on current time as a seed
    static int generateAutoNumbers() {

        srand(time(0));

        for (int i = 0; i < 4; i++)

        return rand();
    }



};

