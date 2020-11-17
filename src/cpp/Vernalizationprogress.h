#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include<vector>
# include<string>
#include "PhenologyState.h"
#include "PhenologyRate.h"
#include "PhenologyAuxiliary.h"
using namespace std;
class Vernalizationprogress
{
    private:
        double minTvern;
        double intTvern;
        double vAI;
        double vBEE;
        double minDL;
        double maxDL;
        double maxTvern;
        double pNini;
        double aMXLFNO;
        int isVernalizable;
    public:
        Vernalizationprogress();
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a);
        void  Init(PhenologyState& s,PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a);
        double getminTvern();
        void setminTvern(double _minTvern);
        double getintTvern();
        void setintTvern(double _intTvern);
        double getvAI();
        void setvAI(double _vAI);
        double getvBEE();
        void setvBEE(double _vBEE);
        double getminDL();
        void setminDL(double _minDL);
        double getmaxDL();
        void setmaxDL(double _maxDL);
        double getmaxTvern();
        void setmaxTvern(double _maxTvern);
        double getpNini();
        void setpNini(double _pNini);
        double getaMXLFNO();
        void setaMXLFNO(double _aMXLFNO);
        int getisVernalizable();
        void setisVernalizable(int _isVernalizable);

};