#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include "CumulFROM.h"

using namespace std;
CumulTTFrom calculate_Cumulfrom(double cumulTT, vector<string> calendarMoments, vector<double> calendarCumuls, int SwitchMaize){

double cumulTTFromZC_65 = 0;
double cumulTTFromZC_39 = 0;
double cumulTTFromZC_91 =0;

size_t posAnthesis = std::find(calendarMoments.begin(), calendarMoments.end(), "Anthesis")- calendarMoments.begin() ;

if(posAnthesis<calendarMoments.size()){
    if (SwitchMaize==0)
        cumulTTFromZC_65 = cumulTT - calendarCumuls[posAnthesis];
}
size_t posFlag = find(calendarMoments.begin(), calendarMoments.end(), "FlagLeafLiguleJustVisible")-calendarMoments.begin();

if(posFlag<calendarMoments.size()){
    if (SwitchMaize==0)
        cumulTTFromZC_39 = cumulTT - calendarCumuls[posFlag];
}
size_t posFill= find(calendarMoments.begin(), calendarMoments.end(), "EndGrainFilling")-calendarMoments.begin();

if(posFill<calendarMoments.size()){
    if (SwitchMaize==0)
        cumulTTFromZC_91 = cumulTT - calendarCumuls[posFill];
}

return CumulTTFrom{cumulTTFromZC_65,cumulTTFromZC_39,cumulTTFromZC_91};


}

