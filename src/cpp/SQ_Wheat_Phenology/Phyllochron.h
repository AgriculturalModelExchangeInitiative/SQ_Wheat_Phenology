#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include "PhenologyState.h"
#include "PhenologyRate.h"
#include "PhenologyAuxiliary.h"
#include "PhenologyExogenous.h"
using namespace std;
class Phyllochron
{
    private:
        double lincr;
        double ldecr;
        double pdecr;
        double pincr;
        double kl;
        double pTQhf;
        double B;
        double p;
        string choosePhyllUse;
        double areaSL;
        double areaSS;
        double lARmin;
        double lARmax;
        double sowingDensity;
        double lNeff;
    public:
        Phyllochron();
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        double getlincr();
        void setlincr(double _lincr);
        double getldecr();
        void setldecr(double _ldecr);
        double getpdecr();
        void setpdecr(double _pdecr);
        double getpincr();
        void setpincr(double _pincr);
        double getkl();
        void setkl(double _kl);
        double getpTQhf();
        void setpTQhf(double _pTQhf);
        double getB();
        void setB(double _B);
        double getp();
        void setp(double _p);
        string getchoosePhyllUse();
        void setchoosePhyllUse(string _choosePhyllUse);
        double getareaSL();
        void setareaSL(double _areaSL);
        double getareaSS();
        void setareaSS(double _areaSS);
        double getlARmin();
        void setlARmin(double _lARmin);
        double getlARmax();
        void setlARmax(double _lARmax);
        double getsowingDensity();
        void setsowingDensity(double _sowingDensity);
        double getlNeff();
        void setlNeff(double _lNeff);

};