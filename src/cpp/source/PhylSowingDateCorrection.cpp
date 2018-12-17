#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<cmath>
#include "PhylSowingDateCorrection.h"
PhylSowingDateCorrection Calculate_PhylSowingDateCorrection(int sowingDay,double latitude,int sDsa_sh,double rp,int sDws,int sDsa_nh,double p)
{
    double fixPhyll;
    if (latitude < 0)
    {
        if (sowingDay > sDsa_sh)
        {
            fixPhyll = p * (1 - rp * fmin(sowingDay - sDsa_sh, sDws));
        }
        else fixPhyll = p;
    }
    else
    {
        if (sowingDay < sDsa_nh)
        {
            fixPhyll = p * (1 - rp * fmin(sowingDay, sDws));
        }
        else fixPhyll = p;
    }

    return PhylSowingDateCorrection{fixPhyll};
}
