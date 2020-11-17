#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include<vector>
# include<string>
#include "PhenologyState.h"
#include "PhenologyRate.h"
#include "PhenologyAuxiliary.h"
using namespace std;
class Ptq
{
    private:
        double tTWindowForPTQ;
        double kl;
    public:
        Ptq();
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a);
        void  Init(PhenologyState& s,PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a);
        double gettTWindowForPTQ();
        void settTWindowForPTQ(double _tTWindowForPTQ);
        double getkl();
        void setkl(double _kl);

};