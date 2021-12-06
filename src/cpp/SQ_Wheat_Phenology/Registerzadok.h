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
class Registerzadok
{
    private:
        double der;
        double slopeTSFLN;
        double intTSFLN;
        string sowingDate;
    public:
        Registerzadok();
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        void  Init(PhenologyState& s,PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        double getder();
        void setder(double _der);
        double getslopeTSFLN();
        void setslopeTSFLN(double _slopeTSFLN);
        double getintTSFLN();
        void setintTSFLN(double _intTSFLN);
        string getsowingDate();
        void setsowingDate(string _sowingDate);

};