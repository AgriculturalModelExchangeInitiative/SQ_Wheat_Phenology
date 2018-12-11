#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<time.h>
#include "UpdateLeafFlag.h"
using namespace std;

UpdateLeafFlag calculate_UpdateLeafFlag(double cumulTT,double leafNumber, vector<string> calendarMoments,vector<time_t> calendarDates,vector<double> calendarCumuls,time_t currentdate,double FinalLeafNumber,int HasFlagLeafLiguleAppeared,double phase)
{

if (phase >= 1 && phase< 4)
{
    if (leafNumber > 0)
    {
        if (HasFlagLeafLiguleAppeared == 0 && (FinalLeafNumber > 0 && leafNumber >= FinalLeafNumber))
        {
            HasFlagLeafLiguleAppeared = 1;
            size_t pos = find(calendarMoments.begin(), calendarMoments.end(),"FlagLeafLiguleJustVisible" ) - calendarMoments.begin();


            if  (pos>=calendarMoments.size())
            {
                calendarMoments.push_back("FlagLeafLiguleJustVisible");
                calendarCumuls.push_back(cumulTT);
                calendarDates.push_back(currentdate);
            }
        }
    }
    else
        HasFlagLeafLiguleAppeared = 0;
}
return UpdateLeafFlag {HasFlagLeafLiguleAppeared, calendarMoments,calendarDates,calendarCumuls};
}



