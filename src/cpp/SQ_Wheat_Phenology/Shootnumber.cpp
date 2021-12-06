#ifndef _SHOOTNUMBER_
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
#include "Shootnumber.h"
using namespace std;

Shootnumber::Shootnumber() { }
double Shootnumber::getsowingDensity() {return this-> sowingDensity; }
double Shootnumber::gettargetFertileShoot() {return this-> targetFertileShoot; }
void Shootnumber::setsowingDensity(double _sowingDensity) { this->sowingDensity = _sowingDensity; }
void Shootnumber::settargetFertileShoot(double _targetFertileShoot) { this->targetFertileShoot = _targetFertileShoot; }
void Shootnumber::Calculate_Model(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex)
{
    //- Name: ShootNumber -Version: 1.0, -Time step: 1
    //- Description:
    //            * Title: CalculateShootNumber Model
    //            * Author: Pierre MARTRE
    //            * Reference: Modeling development phase in the 
    //                Wheat Simulation Model SiriusQuality.
    //                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    //            * Institution: INRA/LEPSE Montpellier
    //            * Abstract: calculate the shoot number and update the related variables if needed
    //- inputs:
    //            * name: canopyShootNumber_t1
    //                          ** description : shoot number for the whole canopy
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** default : 288.0
    //                          ** unit : shoot m-2
    //                          ** inputtype : variable
    //            * name: leafNumber
    //                          ** description : Leaf number 
    //                          ** variablecategory : state
    //                          ** inputtype : variable
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** default : 3.34
    //                          ** unit : leaf
    //            * name: sowingDensity
    //                          ** description : number of plant /m²
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 500
    //                          ** default : 288.0
    //                          ** unit : plant m-2
    //                          ** inputtype : parameter
    //            * name: targetFertileShoot
    //                          ** description : max value of shoot number for the canopy
    //                          ** parametercategory : species
    //                          ** datatype : DOUBLE
    //                          ** min : 280
    //                          ** max : 1000
    //                          ** default : 600.0
    //                          ** unit : shoot
    //                          ** inputtype : variable
    //            * name: tilleringProfile_t1
    //                          ** description :  store the amount of new tiller created at each time a new tiller appears
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLELIST
    //                          ** default : [288.0]
    //                          ** unit : 
    //                          ** inputtype : variable
    //            * name: leafTillerNumberArray_t1
    //                          ** description : store the number of tiller for each leaf layer
    //                          ** variablecategory : state
    //                          ** datatype : INTLIST
    //                          ** unit : leaf
    //                          ** default : [1, 1, 1]
    //                          ** inputtype : variable
    //            * name: numberTillerCohort_t1
    //                          ** description :  Number of tiller which appears
    //                          ** variablecategory : state
    //                          ** datatype : INT
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** default : 1
    //                          ** unit : 
    //                          ** inputtype : variable
    //- outputs:
    //            * name: averageShootNumberPerPlant
    //                          ** description : average shoot number per plant in the canopy
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** unit : shoot m-2
    //            * name: canopyShootNumber
    //                          ** description : shoot number for the whole canopy
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** unit : shoot m-2
    //            * name: leafTillerNumberArray
    //                          ** description : store the number of tiller for each leaf layer
    //                          ** variablecategory : state
    //                          ** datatype : INTLIST
    //                          ** unit : leaf
    //            * name: tilleringProfile
    //                          ** description :  store the amount of new tiller created at each time a new tiller appears
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLELIST
    //                          ** unit : dimensionless
    //            * name: numberTillerCohort
    //                          ** description : Number of tiller which appears
    //                          ** variablecategory : state
    //                          ** datatype : INT
    //                          ** min : 0
    //                          ** max : 10000
    //                          ** unit : dimensionless
    double canopyShootNumber_t1 = s1.getcanopyShootNumber();
    double leafNumber = s.getleafNumber();
    vector<double> tilleringProfile_t1 = s1.gettilleringProfile();
    vector<int> leafTillerNumberArray_t1 = s1.getleafTillerNumberArray();
    int numberTillerCohort_t1 = s1.getnumberTillerCohort();
    double averageShootNumberPerPlant;
    double canopyShootNumber;
    vector<int> leafTillerNumberArray;
    vector<double> tilleringProfile;
    int numberTillerCohort;
    int emergedLeaves;
    int shoots;
    int i;
    vector<int> lNumberArray_rate;
    emergedLeaves = max(1, (int) ceil(leafNumber - 1.0));
    shoots = fibonacci(emergedLeaves);
    canopyShootNumber = min(shoots * sowingDensity, targetFertileShoot);
    averageShootNumberPerPlant = canopyShootNumber / sowingDensity;
    if (canopyShootNumber != canopyShootNumber_t1)
    {
        tilleringProfile = tilleringProfile_t1;
        tilleringProfile.push_back(canopyShootNumber - canopyShootNumber_t1);
    }
    numberTillerCohort = tilleringProfile.size();
    for (i=leafTillerNumberArray_t1.size() ; i!=(int) ceil(leafNumber) ; i+=1)
    {
        lNumberArray_rate.push_back(numberTillerCohort);
    }
    leafTillerNumberArray = leafTillerNumberArray_t1;
    leafTillerNumberArray.reserve(leafTillerNumberArray.size() + distance(lNumberArray_rate.begin(),lNumberArray_rate.end()));
    leafTillerNumberArray.insert(leafTillerNumberArray.end(),lNumberArray_rate.begin(),lNumberArray_rate.end());
    s.setaverageShootNumberPerPlant(averageShootNumberPerPlant);
    s.setcanopyShootNumber(canopyShootNumber);
    s.setleafTillerNumberArray(leafTillerNumberArray);
    s.settilleringProfile(tilleringProfile);
    s.setnumberTillerCohort(numberTillerCohort);
}
int Shootnumber:: fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
void Shootnumber::Init(PhenologyState& s, PhenologyState& s1, PhenologyRate& r, PhenologyAuxiliary& a, PhenologyExogenous& ex)
{
    double canopyShootNumber_t1;
    double leafNumber;
    vector<double> tilleringProfile_t1;
    vector<int> leafTillerNumberArray_t1;
    int numberTillerCohort_t1;
    double averageShootNumberPerPlant;
    double canopyShootNumber;
    vector<int> leafTillerNumberArray;
    vector<double> tilleringProfile;
    int numberTillerCohort;
    canopyShootNumber = sowingDensity;
    averageShootNumberPerPlant = 1.0;
    tilleringProfile.push_back(sowingDensity);
    numberTillerCohort = 1;
    leafTillerNumberArray = vector<int>{};
    s.setaverageShootNumberPerPlant(averageShootNumberPerPlant);
    s.setcanopyShootNumber(canopyShootNumber);
    s.setleafTillerNumberArray(leafTillerNumberArray);
    s.settilleringProfile(tilleringProfile);
    s.setnumberTillerCohort(numberTillerCohort);
}
#endif