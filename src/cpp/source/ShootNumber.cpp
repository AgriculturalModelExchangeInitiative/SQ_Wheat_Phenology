#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<time.h>
#include "Fibonacci.h"
#include "ShootNumber.h"

using namespace std;
ShootNumber Calculate_ShootNumber(double canopyShootNumber,double leafNumber,int sowingDensity,double targetFertileShoot,vector<double> tilleringProfile,vector<int> leafTillerNumberArray,int tillerNumber)
{
    double averageShootNumberPerPlant;
    double oldCanopyShootNumber;
    int emergedLeaves,shoots;
    oldCanopyShootNumber= canopyShootNumber;
    emergedLeaves = (int)fmax(1, ceil(leafNumber - 1));
    shoots = Calculate_Fibonacci(emergedLeaves).value;
    canopyShootNumber = fmin(shoots * sowingDensity, targetFertileShoot);
    averageShootNumberPerPlant = canopyShootNumber / sowingDensity;
    if (canopyShootNumber != oldCanopyShootNumber)
    {
        tilleringProfile.push_back(canopyShootNumber - oldCanopyShootNumber);
    }
    tillerNumber = tilleringProfile.size();
    for (int i = leafTillerNumberArray.size(); i < ceil(leafNumber); i++)
    {
        leafTillerNumberArray.push_back(tillerNumber);
    }
    return ShootNumber{averageShootNumberPerPlant, canopyShootNumber,leafTillerNumberArray,tilleringProfile,tillerNumber};
}
