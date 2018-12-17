#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<cmath>
#include "PhyllochronModule.h"
using namespace std;
Phyllochron Calculate_Phyllochron(double fixPhyll,double leafNumber,double lincr,double ldecr,double pdecr,double pincr,double ptq,double gai,double pastMaxAI,double kl,double aPTQ,double phylPTQ1,double p, string choosePhyllUse)
{
    double phyllochron;
    if (choosePhyllUse == "Default")
    {
        if (leafNumber < ldecr)
            phyllochron = fixPhyll * pdecr;
        else if (leafNumber >= ldecr && leafNumber < lincr)
            phyllochron = fixPhyll;
        else
            phyllochron = fixPhyll * pincr;
    }
    if (choosePhyllUse == "PTQ")
    {
        gai = fmax(pastMaxAI, gai);
        pastMaxAI = gai;
        if (gai > 0.0)
            phyllochron = phylPTQ1 * ((gai * kl) / (1 - exp(-kl * gai))) / (ptq + aPTQ);
        else
            phyllochron = phylPTQ1;
    }
    if (choosePhyllUse == "Test")
    {
        if (leafNumber < ldecr)
            phyllochron = p * pdecr;
        else if (leafNumber >= ldecr && leafNumber < lincr)
            phyllochron = p;
        else
            phyllochron = p * pincr;
    }
    return Phyllochron{phyllochron, pastMaxAI};
}





