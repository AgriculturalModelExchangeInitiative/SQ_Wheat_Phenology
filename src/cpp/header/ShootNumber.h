#include<vector>
using namespace std;
struct ShootNumber
{
double averageShootNumberPerPlant;
double canopyShootNumber;
vector<int> leafTillerNumberArray;
vector<double> tilleringProfile;
int tillerNumber;
};

ShootNumber Calculate_ShootNumber(double canopyShootNumber,double leafNumber,int sowingDensity,double targetFertileShoot,vector<double> tilleringProfile,vector<int> leafTillerNumberArray,int tillerNumber)
;
