#include<time.h>
using namespace std;

struct UpdateCalendar
{
vector<string> calendarMoments;
vector<time_t> calendarDates;
vector<double> calendarCumuls;
};

UpdateCalendar calculate_UpdateCalendar(double cumulTT,vector<string> calendarMoments,vector<time_t> calendarDates,vector<double> calendarCumuls,time_t currentdate,int phase)
;
