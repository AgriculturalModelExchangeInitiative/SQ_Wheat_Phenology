#include "Phyllochron.h"
#include "Phylsowingdatecorrection.h"
#include "Shootnumber.h"
#include "Updateleafflag.h"
#include "Updatephase.h"
#include "Leafnumber.h"
#include "Vernalizationprogress.h"
#include "Ismomentregistredzc_39.h"
#include "Cumulttfrom.h"
#include "Updatecalendar.h"
#include "Registerzadok.h"
#include "Ptq.h"
#include "Gaimean.h"
using namespace std;

class PhenologyComponent
{
    private:
        double aMXLFNO;
        double pNini;
        double sDsa_sh;
        double latitude;
        double kl;
        double lincr;
        double ldecr;
        double pincr;
        double pTQhf;
        double B;
        double areaSL;
        double areaSS;
        double lARmin;
        double sowingDensity;
        double lARmax;
        double lNeff;
        double rp;
        double p;
        double pdecr;
        double maxTvern;
        double tTWindowForPTQ;
        double vBEE;
        int isVernalizable;
        double minTvern;
        double intTvern;
        double vAI;
        double maxDL;
        string choosePhyllUse;
        double minDL;
        double pFLLAnth;
        double dcd;
        double dgf;
        double degfm;
        bool ignoreGrainMaturation;
        double pHEADANTH;
        double sLDL;
        int sowingDay;
        string sowingDate;
        int sDws;
        double sDsa_nh;
        double der;
        double targetFertileShoot;
        double dse;
        double slopeTSFLN;
        double intTSFLN;
    public:
        PhenologyComponent();
        PhenologyComponent(const PhenologyComponent& copy);
        void  Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        void  Init(PhenologyState& s,PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex);
        double getaMXLFNO();
        void setaMXLFNO(double _aMXLFNO);
        double getpNini();
        void setpNini(double _pNini);
        double getsDsa_sh();
        void setsDsa_sh(double _sDsa_sh);
        double getlatitude();
        void setlatitude(double _latitude);
        double getkl();
        void setkl(double _kl);
        double getlincr();
        void setlincr(double _lincr);
        double getldecr();
        void setldecr(double _ldecr);
        double getpincr();
        void setpincr(double _pincr);
        double getpTQhf();
        void setpTQhf(double _pTQhf);
        double getB();
        void setB(double _B);
        double getareaSL();
        void setareaSL(double _areaSL);
        double getareaSS();
        void setareaSS(double _areaSS);
        double getlARmin();
        void setlARmin(double _lARmin);
        double getsowingDensity();
        void setsowingDensity(double _sowingDensity);
        double getlARmax();
        void setlARmax(double _lARmax);
        double getlNeff();
        void setlNeff(double _lNeff);
        double getrp();
        void setrp(double _rp);
        double getp();
        void setp(double _p);
        double getpdecr();
        void setpdecr(double _pdecr);
        double getmaxTvern();
        void setmaxTvern(double _maxTvern);
        double gettTWindowForPTQ();
        void settTWindowForPTQ(double _tTWindowForPTQ);
        double getvBEE();
        void setvBEE(double _vBEE);
        int getisVernalizable();
        void setisVernalizable(int _isVernalizable);
        double getminTvern();
        void setminTvern(double _minTvern);
        double getintTvern();
        void setintTvern(double _intTvern);
        double getvAI();
        void setvAI(double _vAI);
        double getmaxDL();
        void setmaxDL(double _maxDL);
        string getchoosePhyllUse();
        void setchoosePhyllUse(string _choosePhyllUse);
        double getminDL();
        void setminDL(double _minDL);
        double getpFLLAnth();
        void setpFLLAnth(double _pFLLAnth);
        double getdcd();
        void setdcd(double _dcd);
        double getdgf();
        void setdgf(double _dgf);
        double getdegfm();
        void setdegfm(double _degfm);
        bool getignoreGrainMaturation();
        void setignoreGrainMaturation(bool _ignoreGrainMaturation);
        double getpHEADANTH();
        void setpHEADANTH(double _pHEADANTH);
        double getsLDL();
        void setsLDL(double _sLDL);
        int getsowingDay();
        void setsowingDay(int _sowingDay);
        string getsowingDate();
        void setsowingDate(string _sowingDate);
        int getsDws();
        void setsDws(int _sDws);
        double getsDsa_nh();
        void setsDsa_nh(double _sDsa_nh);
        double getder();
        void setder(double _der);
        double gettargetFertileShoot();
        void settargetFertileShoot(double _targetFertileShoot);
        double getdse();
        void setdse(double _dse);
        double getslopeTSFLN();
        void setslopeTSFLN(double _slopeTSFLN);
        double getintTSFLN();
        void setintTSFLN(double _intTSFLN);

        Phyllochron _Phyllochron;
        Phylsowingdatecorrection _Phylsowingdatecorrection;
        Shootnumber _Shootnumber;
        Updateleafflag _Updateleafflag;
        Updatephase _Updatephase;
        Leafnumber _Leafnumber;
        Vernalizationprogress _Vernalizationprogress;
        Ismomentregistredzc_39 _Ismomentregistredzc_39;
        Cumulttfrom _Cumulttfrom;
        Updatecalendar _Updatecalendar;
        Registerzadok _Registerzadok;
        Ptq _Ptq;
        Gaimean _Gaimean;

};