using namespace std;

struct VernalizationProgress
{
double vernaprog;
double minFinalNumber;
vector<string> calendarMoments;
vector<string> calendarDates;
vector<double> calendarCumuls;

};

VernalizationProgress Calculate_VernalizationProgress(double dayLength,double deltaTT,double cumulTT,double leafNumber,vector<string> calendarMoments,vector<string> calendarDates,vector<double> calendarCumuls,double minTvern,double intTvern,double vAI,double vBEE,double minDL,double maxDL,double maxTvern,double pNini,double aMXLFNO,double vernaprog,string currentdate,int isVernalizable,double minFinalNumber);
