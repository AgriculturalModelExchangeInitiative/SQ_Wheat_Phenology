#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<cmath>
#include "PhylSowingDateCorrection.h"

PhylSowingDateCorrection calculate_PhylSowingDateCorrection(int SowingDay,double Latitude,int SDsa_sh,double Rp,int SDws,int SDsa_nh,double P)
{

double FixPhyll;
if (Latitude < 0)
{
	if (SowingDay > SDsa_sh)
	{
		FixPhyll = P * (1 - Rp * fmin(SowingDay - SDsa_sh, SDws));
	}
	else FixPhyll = P;
}
else
{
	if (SowingDay < SDsa_nh)
	{
		FixPhyll = P * (1 - Rp * fmin(SowingDay, SDws));
	}
	else FixPhyll = P;
}
return PhylSowingDateCorrection{FixPhyll};
}
