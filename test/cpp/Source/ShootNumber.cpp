#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<time.h>
#include "Fibonacci.h"
#include "ShootNumber.h"

using namespace std;
ShootNumber calculate_ShootNumber(double CanopyShootNumber,double leafNumber,int SowingDensity,double TargetFertileShoot,vector<double> tilleringProfile,vector<int> leafTillerNumberArray,int TillerNumber)
{

double AverageShootNumberPerPlant;
double OldCanopyShootNumber = CanopyShootNumber;
int EmergedLeaves = (int)fmax(1, ceil(leafNumber - 1));
int Shoots = calculate_Fibonacci(EmergedLeaves).value;

CanopyShootNumber = fmin(Shoots * SowingDensity, TargetFertileShoot);
AverageShootNumberPerPlant = CanopyShootNumber / SowingDensity;

if (CanopyShootNumber != OldCanopyShootNumber)
{
	tilleringProfile.push_back(CanopyShootNumber - OldCanopyShootNumber);
}

TillerNumber = tilleringProfile.size();

for (int i = leafTillerNumberArray.size(); i < ceil(leafNumber); i++)
{
	leafTillerNumberArray.push_back(TillerNumber);
}
return ShootNumber{AverageShootNumberPerPlant, CanopyShootNumber,leafTillerNumberArray,tilleringProfile,TillerNumber};
}
