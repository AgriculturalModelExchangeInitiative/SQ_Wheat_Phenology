#include<vector>
using namespace std;
struct ShootNumber
{
double AverageShootNumberPerPlant;
double CanopyShootNumber;
vector<int> leafTillerNumberArray;
vector<double> tilleringProfile;
int TillerNumber;
};

ShootNumber calculate_ShootNumber(double CanopyShootNumber,double leafNumber,int SowingDensity,double TargetFertileShoot,vector<double> tilleringProfile,vector<int> leafTillerNumberArray,int TillerNumber)
;
