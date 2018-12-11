#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<cmath>
#include "PhyllochronModule.h"

using namespace std;
Phyllochron calculate_Phyllochron(double FixPhyll,double leafNumber,double Lincr,double Ldecr,double Pdecr,double Pincr,double LAI,double PTQ,double GAI,double pastMaxAI,double Kl,double aPTQ,double PhylPTQ1,double P,std::string choosePhyllUse)
{

double phyllochron;

if (choosePhyllUse =="Default")
{
	if (leafNumber < Ldecr) phyllochron = FixPhyll * Pdecr;
	else if (leafNumber >= Ldecr && leafNumber < Lincr) phyllochron = FixPhyll;
	else phyllochron = FixPhyll * Pincr;
}

if (choosePhyllUse =="PTQ")
{
    GAI = fmax(pastMaxAI,GAI);
    pastMaxAI = GAI;
    if (GAI > 0.0) phyllochron = PhylPTQ1 * ((GAI * Kl) / (1 - exp(-Kl * GAI))) / (PTQ + aPTQ);
    else phyllochron = PhylPTQ1;

}
if (choosePhyllUse == "Test")
{
    if (leafNumber < Ldecr) phyllochron = P * Pdecr;
    else if (leafNumber >= Ldecr && leafNumber < Lincr)  phyllochron = P;
    else phyllochron = P * Pincr;
}

return Phyllochron{phyllochron, pastMaxAI};
}





