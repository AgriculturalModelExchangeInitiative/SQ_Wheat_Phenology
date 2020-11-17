#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include<vector>
# include<string>
#include "PhenologyState.h"
#include "PhenologyRate.h"
#include "PhenologyAuxiliary.h"
using namespace std;
class Updatephase
{
    private:
        int isVernalizable;
        double dse;
        double pFLLAnth;
        double dcd;
        double dgf;
        double degfm;
        double maxDL;
        double sLDL;
        bool ignoreGrainMaturation;
        double pHEADANTH;
        string choosePhyllUse;
        double p;
    public:
        Updatephase();
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a);
        void  Init(PhenologyState& s,PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a);
        int getisVernalizable();
        void setisVernalizable(int _isVernalizable);
        double getdse();
        void setdse(double _dse);
        double getpFLLAnth();
        void setpFLLAnth(double _pFLLAnth);
        double getdcd();
        void setdcd(double _dcd);
        double getdgf();
        void setdgf(double _dgf);
        double getdegfm();
        void setdegfm(double _degfm);
        double getmaxDL();
        void setmaxDL(double _maxDL);
        double getsLDL();
        void setsLDL(double _sLDL);
        bool getignoreGrainMaturation();
        void setignoreGrainMaturation(bool _ignoreGrainMaturation);
        double getpHEADANTH();
        void setpHEADANTH(double _pHEADANTH);
        string getchoosePhyllUse();
        void setchoosePhyllUse(string _choosePhyllUse);
        double getp();
        void setp(double _p);

};