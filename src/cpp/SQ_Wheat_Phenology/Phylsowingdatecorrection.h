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
class Phylsowingdatecorrection
{
    private:
        int sowingDay;
        double latitude;
        double sDsa_sh;
        double rp;
        int sDws;
        double sDsa_nh;
        double p;
    public:
        Phylsowingdatecorrection();
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        int getsowingDay();
        void setsowingDay(int _sowingDay);
        double getlatitude();
        void setlatitude(double _latitude);
        double getsDsa_sh();
        void setsDsa_sh(double _sDsa_sh);
        double getrp();
        void setrp(double _rp);
        int getsDws();
        void setsDws(int _sDws);
        double getsDsa_nh();
        void setsDsa_nh(double _sDsa_nh);
        double getp();
        void setp(double _p);

};