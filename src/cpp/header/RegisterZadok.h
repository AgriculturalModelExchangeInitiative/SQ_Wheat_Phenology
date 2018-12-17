#include<vector>
#include<string>
using namespace std;
struct RegisterZadok
{
 int hasZadokStageChanged;
 string currentZadokStage;
 vector<string>calendarMoments;
 vector<string> calendarDates;
  vector<double> calendarCumuls;
};
RegisterZadok Calculate_RegisterZadok(double cumulTT,double phase,double leafNumber,vector<string> calendarMoments,vector<string> calendarDates,vector<double> calendarCumuls,double cumulTTFromZC_65,string currentdate,double der,double slopeTSFLN,double intTSFLN,double finalLeafNumber,string currentZadokStage,int hasZadokStageChanged);
