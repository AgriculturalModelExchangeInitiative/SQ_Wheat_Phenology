#include<vector>
#include<string>
using namespace std;
struct RegisterZadok
{
 int hasZadokStageChanged;
 string currentZadokStage;
 vector<string>calendarMoments;
 vector<time_t> calendarDates;
  vector<double> calendarCumuls;
};
RegisterZadok CalculateRegisterZadok(double cumulTT,double phase,double leafNumber,vector<string> calendarMoments,vector<time_t> calendarDates,vector<double> calendarCumuls,double cumulTTFromZC_65,time_t currentdate,double Der,double slopeTSFLN,double TSFLN,double intTSFLN,double FinalLeafNumber,string currentZadokStage,int hasZadokStageChanged);
