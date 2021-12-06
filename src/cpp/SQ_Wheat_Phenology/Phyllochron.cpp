#ifndef _PHYLLOCHRON_
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
#include "Phyllochron.h"
using namespace std;

Phyllochron::Phyllochron() { }
double Phyllochron::getlincr() {return this-> lincr; }
double Phyllochron::getldecr() {return this-> ldecr; }
double Phyllochron::getpdecr() {return this-> pdecr; }
double Phyllochron::getpincr() {return this-> pincr; }
double Phyllochron::getkl() {return this-> kl; }
double Phyllochron::getpTQhf() {return this-> pTQhf; }
double Phyllochron::getB() {return this-> B; }
double Phyllochron::getp() {return this-> p; }
string Phyllochron::getchoosePhyllUse() {return this-> choosePhyllUse; }
double Phyllochron::getareaSL() {return this-> areaSL; }
double Phyllochron::getareaSS() {return this-> areaSS; }
double Phyllochron::getlARmin() {return this-> lARmin; }
double Phyllochron::getlARmax() {return this-> lARmax; }
double Phyllochron::getsowingDensity() {return this-> sowingDensity; }
double Phyllochron::getlNeff() {return this-> lNeff; }
void Phyllochron::setlincr(double _lincr) { this->lincr = _lincr; }
void Phyllochron::setldecr(double _ldecr) { this->ldecr = _ldecr; }
void Phyllochron::setpdecr(double _pdecr) { this->pdecr = _pdecr; }
void Phyllochron::setpincr(double _pincr) { this->pincr = _pincr; }
void Phyllochron::setkl(double _kl) { this->kl = _kl; }
void Phyllochron::setpTQhf(double _pTQhf) { this->pTQhf = _pTQhf; }
void Phyllochron::setB(double _B) { this->B = _B; }
void Phyllochron::setp(double _p) { this->p = _p; }
void Phyllochron::setchoosePhyllUse(string _choosePhyllUse) { this->choosePhyllUse = _choosePhyllUse; }
void Phyllochron::setareaSL(double _areaSL) { this->areaSL = _areaSL; }
void Phyllochron::setareaSS(double _areaSS) { this->areaSS = _areaSS; }
void Phyllochron::setlARmin(double _lARmin) { this->lARmin = _lARmin; }
void Phyllochron::setlARmax(double _lARmax) { this->lARmax = _lARmax; }
void Phyllochron::setsowingDensity(double _sowingDensity) { this->sowingDensity = _sowingDensity; }
void Phyllochron::setlNeff(double _lNeff) { this->lNeff = _lNeff; }
void Phyllochron::Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex)
{
    //- Name: Phyllochron -Version: 1.0, -Time step: 1
    //- Description:
    //            * Title: Phyllochron Model
    //            * Author: Pierre Martre
    //            * Reference: Modeling development phase in the 
    //                Wheat Simulation Model SiriusQuality.
    //                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    //            * Institution: INRA Montpellier
    //            * Abstract: Calculate different types of phyllochron 
    //- inputs:
    //            * name: fixPhyll
    //                          ** description : Sowing date corrected Phyllochron
    //                          ** inputtype : variable
    //                          ** variablecategory : auxiliary
    //                          ** datatype : DOUBLE
    //                          ** default : 5.0
    //                          ** min : 0.0
    //                          ** max : 10000.0
    //                          ** unit : °C d leaf-1
    //                          ** uri : some url
    //            * name: leafNumber
    //                          ** description : Actual number of phytomers
    //                          ** inputtype : variable
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 25.0
    //                          ** unit : leaf
    //                          ** uri : some url
    //            * name: lincr
    //                          ** description : Leaf number above which the phyllochron is increased by Pincr
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** default : 8.0
    //                          ** min : 0.0
    //                          ** max : 30.0
    //                          ** unit : leaf
    //                          ** uri : some url
    //            * name: ldecr
    //                          ** description : Leaf number up to which the phyllochron is decreased by Pdecr
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 100.0
    //                          ** unit : leaf
    //                          ** uri : some url
    //            * name: pdecr
    //                          ** description : Factor decreasing the phyllochron for leaf number less than Ldecr
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** default : 0.4
    //                          ** min : 0.0
    //                          ** max : 10.0
    //                          ** unit : -
    //                          ** uri : some url
    //            * name: pincr
    //                          ** description : Factor increasing the phyllochron for leaf number higher than Lincr
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** default : 1.5
    //                          ** min : 0.0
    //                          ** max : 10.0
    //                          ** unit : -
    //                          ** uri : some url
    //            * name: ptq
    //                          ** description : Photothermal quotient 
    //                          ** inputtype : variable
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 10000.0
    //                          ** unit : MJ °C-1 d-1 m-2)
    //                          ** uri : some url
    //            * name: gAImean
    //                          ** description : Green Area Index
    //                          ** inputtype : variable
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 10000.0
    //                          ** unit : m2 m-2
    //                          ** uri : some url
    //            * name: kl
    //                          ** description : Exctinction Coefficient
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** default : 0.45
    //                          ** min : 0.0
    //                          ** max : 50.0
    //                          ** unit : -
    //                          ** uri : some url
    //            * name: pTQhf
    //                          ** description : Slope to intercept ratio for Phyllochron  parametrization with PhotoThermal Quotient
    //                          ** inputtype : parameter
    //                          ** parametercategory : genotypic
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : °C d leaf-1
    //                          ** uri : some url
    //            * name: B
    //                          ** description : Phyllochron at PTQ equal 1
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** default : 20.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : °C d leaf-1
    //                          ** uri : some url
    //            * name: p
    //                          ** description : Phyllochron (Varietal parameter)
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** default : 120.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : °C d leaf-1
    //                          ** uri : some url
    //            * name: choosePhyllUse
    //                          ** description : Switch to choose the type of phyllochron calculation to be used
    //                          ** inputtype : parameter
    //                          ** parametercategory : species
    //                          ** datatype : STRING
    //                          ** default : Default
    //                          ** min : 
    //                          ** max : 
    //                          ** unit : -
    //                          ** uri : some url
    //            * name: areaSL
    //                          ** description :  Area Leaf
    //                          ** inputtype : parameter
    //                          ** parametercategory : genotypic
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : cm2
    //                          ** uri : some url
    //            * name: areaSS
    //                          ** description : Area Sheath
    //                          ** inputtype : parameter
    //                          ** parametercategory : genotypic
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : cm2
    //                          ** uri : some url
    //            * name: lARmin
    //                          ** description : LAR minimum
    //                          ** inputtype : parameter
    //                          ** parametercategory : genotypic
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : leaf-1 °C
    //                          ** uri : some url
    //            * name: lARmax
    //                          ** description : LAR maximum
    //                          ** inputtype : parameter
    //                          ** parametercategory : genotypic
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : leaf-1 °C
    //                          ** uri : some url
    //            * name: sowingDensity
    //                          ** description : Sowing Density
    //                          ** inputtype : parameter
    //                          ** parametercategory : genotypic
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : plant m-2
    //                          ** uri : some url
    //            * name: lNeff
    //                          ** description : Leaf Number efficace
    //                          ** inputtype : parameter
    //                          ** parametercategory : genotypic
    //                          ** datatype : DOUBLE
    //                          ** default : 0.0
    //                          ** min : 0.0
    //                          ** max : 1000.0
    //                          ** unit : leaf
    //                          ** uri : some url
    //- outputs:
    //            * name: phyllochron
    //                          ** description :  the rate of leaf appearance 
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 1000
    //                          ** unit :  °C d leaf-1
    //                          ** uri : some url
    double fixPhyll = a.getfixPhyll();
    double leafNumber = s.getleafNumber();
    double ptq = s.getptq();
    double gAImean = s.getgAImean();
    double phyllochron;
    double gaiLim;
    double LAR;
    phyllochron = 0.0;
    LAR = 0.0;
    gaiLim = lNeff * ((areaSL + areaSS) / 10000.0) * sowingDensity;
    if (choosePhyllUse == "Default")
    {
        if (leafNumber < ldecr)
        {
            phyllochron = fixPhyll * pdecr;
        }
        else if ( leafNumber >= ldecr && leafNumber < lincr)
        {
            phyllochron = fixPhyll;
        }
        else
        {
            phyllochron = fixPhyll * pincr;
        }
    }
    if (choosePhyllUse == "PTQ")
    {
        if (gAImean > gaiLim)
        {
            LAR = (lARmin + ((lARmax - lARmin) * ptq / (pTQhf + ptq))) / (B * gAImean);
        }
        else
        {
            LAR = (lARmin + ((lARmax - lARmin) * ptq / (pTQhf + ptq))) / (B * gaiLim);
        }
        phyllochron = 1.0 / LAR;
    }
    if (choosePhyllUse == "Test")
    {
        if (leafNumber < ldecr)
        {
            phyllochron = p * pdecr;
        }
        else if ( leafNumber >= ldecr && leafNumber < lincr)
        {
            phyllochron = p;
        }
        else
        {
            phyllochron = p * pincr;
        }
    }
    s.setphyllochron(phyllochron);
}
#endif