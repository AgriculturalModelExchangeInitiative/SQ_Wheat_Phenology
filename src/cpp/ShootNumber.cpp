
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
