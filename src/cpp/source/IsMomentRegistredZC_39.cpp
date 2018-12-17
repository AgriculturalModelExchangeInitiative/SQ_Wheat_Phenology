#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include "IsMomentRegistredZC_39.h"

using namespace std;
IsMomentRegistredZC_39 Calculate_IsMomentRegistredZC_39(vector<string> calendarMoments){

int isMomentRegistredZC_39;
size_t posFlag = find(calendarMoments.begin(), calendarMoments.end(),"FlagLeafLiguleJustVisible" ) - calendarMoments.begin();

if (posFlag<calendarMoments.size())
{
   isMomentRegistredZC_39 = 1 ;
}
else
    isMomentRegistredZC_39 = 0;
return IsMomentRegistredZC_39{isMomentRegistredZC_39};
}

