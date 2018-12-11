using namespace std;

struct VernalizationProgress
{
double Vernaprog;
double MinFinalNumber;
vector<string> calendarMoments;
vector<time_t> calendarDates;
vector<double> calendarCumuls;

};

VernalizationProgress calculate_VernalizationProgress(double DayLength,double DeltaTT,double cumulTT,double leafNumber,vector<string> calendarMoments,vector<time_t> calendarDates,vector<double> calendarCumuls,double MinTvern,double IntTvern,double VAI,double VBEE,double MinDL,double MaxDL,double MaxTvern,double PNini,double AMXLFNO,double Vernaprog,time_t currentdate,int IsVernalizable,double MinFinalNumber)
;
