#include<time.h>
using namespace std;
struct UpdateLeafFlag
{
int HasFlagLeafLiguleAppeared;
vector<string> calendarMoments;
vector<time_t> calendarDates;
vector<double> calendarCumuls;
};

UpdateLeafFlag calculate_UpdateLeafFlag(double cumulTT,double leafNumber, vector<string> calendarMoments,vector<time_t> calendarDates,vector<double> calendarCumuls,time_t currentdate,double FinalLeafNumber,int HasFlagLeafLiguleAppeared,double phase)
;
