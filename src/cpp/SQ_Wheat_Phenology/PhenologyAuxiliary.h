#ifndef _PhenologyAuxiliary_
#define _PhenologyAuxiliary_
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include<vector>
# include<string>
using namespace std;
class PhenologyAuxiliary
{
    private:
        string currentdate;
        double cumulTT;
        double dayLength;
        double deltaTT;
        double gAI;
        double pAR;
        double grainCumulTT;
        double fixPhyll;
        double cumulTTFromZC_39;
        double cumulTTFromZC_91;
        double cumulTTFromZC_65;
    public:
        PhenologyAuxiliary();
        string getcurrentdate();
        void setcurrentdate(string _currentdate);
        double getcumulTT();
        void setcumulTT(double _cumulTT);
        double getdayLength();
        void setdayLength(double _dayLength);
        double getdeltaTT();
        void setdeltaTT(double _deltaTT);
        double getgAI();
        void setgAI(double _gAI);
        double getpAR();
        void setpAR(double _pAR);
        double getgrainCumulTT();
        void setgrainCumulTT(double _grainCumulTT);
        double getfixPhyll();
        void setfixPhyll(double _fixPhyll);
        double getcumulTTFromZC_39();
        void setcumulTTFromZC_39(double _cumulTTFromZC_39);
        double getcumulTTFromZC_91();
        void setcumulTTFromZC_91(double _cumulTTFromZC_91);
        double getcumulTTFromZC_65();
        void setcumulTTFromZC_65(double _cumulTTFromZC_65);

};
#endif