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
class Ptq
{
    private:
        double tTWindowForPTQ;
        double kl;
    public:
        Ptq();
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        void  Init(PhenologyState& s,PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        double gettTWindowForPTQ();
        void settTWindowForPTQ(double _tTWindowForPTQ);
        double getkl();
        void setkl(double _kl);

};