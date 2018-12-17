#include<time.h>
using namespace std;
struct UpdateLeafFlag
{
int hasFlagLeafLiguleAppeared;
vector<string> calendarMoments;
vector<string> calendarDates;
vector<double> calendarCumuls;
};
UpdateLeafFlag Calculate_UpdateLeafFlag(double cumulTT,double leafNumber, vector<string> calendarMoments,vector<string> calendarDates,vector<double> calendarCumuls,string currentdate,double finalLeafNumber,int hasFlagLeafLiguleAppeared,double phase);
