#ifndef _VERNALIZATIONPROGRESS_
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <array>
#include <map>
#include <tuple>
#include "Vernalizationprogress.h"
using namespace std;

Vernalizationprogress::Vernalizationprogress() { }
double Vernalizationprogress::getminTvern() {return this-> minTvern; }
double Vernalizationprogress::getintTvern() {return this-> intTvern; }
double Vernalizationprogress::getvAI() {return this-> vAI; }
double Vernalizationprogress::getvBEE() {return this-> vBEE; }
double Vernalizationprogress::getminDL() {return this-> minDL; }
double Vernalizationprogress::getmaxDL() {return this-> maxDL; }
double Vernalizationprogress::getmaxTvern() {return this-> maxTvern; }
double Vernalizationprogress::getpNini() {return this-> pNini; }
double Vernalizationprogress::getaMXLFNO() {return this-> aMXLFNO; }
int Vernalizationprogress::getisVernalizable() {return this-> isVernalizable; }
void Vernalizationprogress::setminTvern(double _minTvern) { this->minTvern = _minTvern; }
void Vernalizationprogress::setintTvern(double _intTvern) { this->intTvern = _intTvern; }
void Vernalizationprogress::setvAI(double _vAI) { this->vAI = _vAI; }
void Vernalizationprogress::setvBEE(double _vBEE) { this->vBEE = _vBEE; }
void Vernalizationprogress::setminDL(double _minDL) { this->minDL = _minDL; }
void Vernalizationprogress::setmaxDL(double _maxDL) { this->maxDL = _maxDL; }
void Vernalizationprogress::setmaxTvern(double _maxTvern) { this->maxTvern = _maxTvern; }
void Vernalizationprogress::setpNini(double _pNini) { this->pNini = _pNini; }
void Vernalizationprogress::setaMXLFNO(double _aMXLFNO) { this->aMXLFNO = _aMXLFNO; }
void Vernalizationprogress::setisVernalizable(int _isVernalizable) { this->isVernalizable = _isVernalizable; }
void Vernalizationprogress::Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex)
{
    //- Name: VernalizationProgress -Version: 1.0, -Time step: 1
    //- Description:
    //            * Title: VernalizationProgress Model
    //            * Author: Pierre MARTRE
    //            * Reference: Modeling development phase in the 
    //                Wheat Simulation Model SiriusQuality.
    //                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    //            * Institution: INRA Montpellier
    //            * Abstract: Calculate progress (VernaProg) towards vernalization, but there 
    //        			is no vernalization below minTvern 
    //        			and above maxTvern . The maximum value of VernaProg is 1.
    //        			Progress towards full vernalization is a linear function of shoot 
    //        			temperature (soil temperature until leaf # reach MaxLeafSoil and then
    //        			 canopy temperature)
    //    	
    //- inputs:
    //            * name: dayLength
    //                          ** description : day length
    //                          ** variablecategory : auxiliary
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** default : 12.3037621834005
    //                          ** unit : mm2 m-2
    //                          ** inputtype : variable
    //            * name: deltaTT
    //                          ** description : difference cumul TT between j and j-1 day 
    //                          ** variablecategory : auxiliary
    //                          ** inputtype : variable
    //                          ** datatype : DOUBLE
    //                          ** min : -20
    //                          ** max : 100
    //                          ** default : 20.3429985011972
    //                          ** unit : °C d
    //            * name: cumulTT
    //                          ** description : cumul thermal times at currentdate
    //                          ** variablecategory : auxiliary
    //                          ** datatype : DOUBLE
    //                          ** min : -200
    //                          ** max : 10000
    //                          ** default : 112.330110409888
    //                          ** unit : °C d
    //                          ** inputtype : variable
    //            * name: leafNumber_t1
    //                          ** description : Actual number of phytomers
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 25
    //                          ** default : 0
    //                          ** unit : leaf
    //                          ** inputtype : variable
    //            * name: calendarMoments_t1
    //                          ** description : List containing appearance of each stage
    //                          ** variablecategory : state
    //                          ** datatype : STRINGLIST
    //                          ** default : ['Sowing']
    //                          ** unit : 
    //                          ** inputtype : variable
    //            * name: calendarDates_t1
    //                          ** description : List containing  the dates of the wheat developmental phases
    //                          ** variablecategory : state
    //                          ** datatype : DATELIST
    //                          ** default : ['2007/3/21']
    //                          ** unit : 
    //                          ** inputtype : variable
    //            * name: calendarCumuls_t1
    //                          ** description : list containing for each stage occured its cumulated thermal times
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLELIST
    //                          ** default : [0.0]
    //                          ** unit : 
    //                          ** inputtype : variable
    //            * name: minTvern
    //                          ** description : Minimum temperature for vernalization to occur
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : -20
    //                          ** max : 60
    //                          ** default : 0.0
    //                          ** unit : °C
    //                          ** inputtype : parameter
    //            * name: intTvern
    //                          ** description : Intermediate temperature for vernalization to occur
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : -20
    //                          ** max : 60
    //                          ** default :  11.0
    //                          ** unit : °C
    //                          ** inputtype : parameter
    //            * name: vAI
    //                          ** description : Response of vernalization rate to temperature
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 1
    //                          ** default :  0.015
    //                          ** unit : d-1 °C-1
    //                          ** inputtype : parameter
    //            * name: vBEE
    //                          ** description : Vernalization rate at 0°C
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 1
    //                          ** default : 0.01
    //                          ** unit : d-1
    //                          ** inputtype : parameter
    //            * name: minDL
    //                          ** description : Threshold daylength below which it does influence vernalization rate
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 12
    //                          ** max : 24
    //                          ** default : 8.0
    //                          ** unit : h
    //                          ** inputtype : parameter
    //            * name: maxDL
    //                          ** description : Saturating photoperiod above which final leaf number is not influenced by daylength
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 24
    //                          ** default : 15.0
    //                          ** unit : h
    //                          ** inputtype : parameter
    //            * name: maxTvern
    //                          ** description : Maximum temperature for vernalization to occur
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : -20
    //                          ** max : 60
    //                          ** default :  23.0
    //                          ** unit : °C
    //                          ** inputtype : parameter
    //            * name: pNini
    //                          ** description : Number of primorida in the apex at emergence
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 24
    //                          ** default : 4.0
    //                          ** unit : primordia
    //                          ** inputtype : parameter
    //            * name: aMXLFNO
    //                          ** description : Absolute maximum leaf number
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 25
    //                          ** default : 24.0
    //                          ** unit : leaf
    //                          ** inputtype : parameter
    //            * name: vernaprog_t1
    //                          ** description : progression on a 0  to 1 scale of the vernalization
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 1
    //                          ** default :  0.5517254187376879
    //                          ** unit : 
    //                          ** inputtype : variable
    //            * name: currentdate
    //                          ** description : current date 
    //                          ** variablecategory : auxiliary
    //                          ** datatype : DATE
    //                          ** default : 2007/3/27
    //                          ** inputtype : variable
    //                          ** unit : 
    //            * name: isVernalizable
    //                          ** description : true if the plant is vernalizable
    //                          ** parametercategory : species
    //                          ** datatype : INT
    //                          ** min : 0
    //                          ** max : 1
    //                          ** default : 1
    //                          ** unit : 
    //                          ** inputtype : parameter
    //            * name: minFinalNumber_t1
    //                          ** description : minimum final leaf number
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 25
    //                          ** default : 5.5
    //                          ** unit : leaf
    //                          ** inputtype : variable
    //                          ** variablecategory : state
    //- outputs:
    //            * name: vernaprog
    //                          ** description : progression on a 0  to 1 scale of the vernalization
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** unit : 
    //            * name: minFinalNumber
    //                          ** description : minimum final leaf number
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** unit : leaf
    //            * name: calendarMoments
    //                          ** description : List containing appearance of each stage
    //                          ** variablecategory : state
    //                          ** datatype : STRINGLIST
    //                          ** unit : 
    //            * name: calendarDates
    //                          ** description : List containing  the dates of the wheat developmental phases
    //                          ** variablecategory : state
    //                          ** datatype : DATELIST
    //                          ** unit : 
    //            * name: calendarCumuls
    //                          ** description : list containing for each stage occured its cumulated thermal times
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLELIST
    //                          ** unit : 
    double dayLength = a.getdayLength();
    double deltaTT = a.getdeltaTT();
    double cumulTT = a.getcumulTT();
    double leafNumber_t1 = s1.getleafNumber();
    vector<string> calendarMoments_t1 = s1.getcalendarMoments();
    vector<string> calendarDates_t1 = s1.getcalendarDates();
    vector<double> calendarCumuls_t1 = s1.getcalendarCumuls();
    double vernaprog_t1 = s1.getvernaprog();
    string currentdate = a.getcurrentdate();
    double minFinalNumber_t1 = s1.getminFinalNumber();
    double vernaprog;
    double minFinalNumber;
    vector<string> calendarMoments;
    vector<string> calendarDates;
    vector<double> calendarCumuls;
    double maxVernaProg;
    double dLverna;
    double primordno;
    double minLeafNumber;
    double potlfno;
    double tt;
    calendarMoments = calendarMoments_t1;
    calendarCumuls = calendarCumuls_t1;
    calendarDates = calendarDates_t1;
    minFinalNumber = minFinalNumber_t1;
    vernaprog = vernaprog_t1;
    if (isVernalizable == 1 && vernaprog_t1 < 1.0)
    {
        tt = deltaTT;
        if (tt >= minTvern && tt <= intTvern)
        {
            vernaprog = vernaprog_t1 + (vAI * tt) + vBEE;
        }
        else
        {
            vernaprog = vernaprog_t1;
        }
        if (tt > intTvern)
        {
            maxVernaProg = vAI * intTvern + vBEE;
            dLverna = max(minDL, min(maxDL, dayLength));
            vernaprog = vernaprog + max(0.0, maxVernaProg * (1.0 + ((intTvern - tt) / (maxTvern - intTvern) * ((dLverna - minDL) / (maxDL - minDL)))));
        }
        primordno = 2.0 * leafNumber_t1 + pNini;
        minLeafNumber = minFinalNumber_t1;
        if (vernaprog >= 1.0 || primordno >= aMXLFNO)
        {
            minFinalNumber = max(primordno, minFinalNumber_t1);
            calendarMoments.push_back("EndVernalisation");
            calendarCumuls.push_back(cumulTT);
            calendarDates.push_back(currentdate);
            vernaprog = max(1.0, vernaprog);
        }
        else
        {
            potlfno = aMXLFNO - ((aMXLFNO - minLeafNumber) * vernaprog);
            if (primordno >= potlfno)
            {
                minFinalNumber = max((potlfno + primordno) / 2.0, minFinalNumber_t1);
                vernaprog = max(1.0, vernaprog);
                calendarMoments.push_back("EndVernalisation");
                calendarCumuls.push_back(cumulTT);
                calendarDates.push_back(currentdate);
            }
        }
    }
    s.setvernaprog(vernaprog);
    s.setminFinalNumber(minFinalNumber);
    s.setcalendarMoments(calendarMoments);
    s.setcalendarDates(calendarDates);
    s.setcalendarCumuls(calendarCumuls);
}
#endif