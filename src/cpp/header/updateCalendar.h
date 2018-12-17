#include<time.h>
using namespace std;

struct UpdateCalendar
{
vector<string> calendarMoments;
vector<string> calendarDates;
vector<double> calendarCumuls;
};

UpdateCalendar Calculate_UpdateCalendar(double cumulTT,vector<string> calendarMoments,vector<string> calendarDates,vector<double> calendarCumuls,string currentdate,int phase)
;
