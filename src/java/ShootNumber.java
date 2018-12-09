
double OldCanopyShootNumber = CanopyShootNumber;
int EmergedLeaves = (int)Math.max(1, Math.ceil(leafNumber - 1));
int Shoots = fibonacci(EmergedLeaves);

CanopyShootNumber = Math.min(Shoots * SowingDensity, TargetFertileShoot);
AverageShootNumberPerPlant = CanopyShootNumber / SowingDensity;

if (CanopyShootNumber != OldCanopyShootNumber)
{
	tilleringProfile.add(CanopyShootNumber - OldCanopyShootNumber);
}
		
TillerNumber = tilleringProfile.size();
		
for (int i = leafTillerNumberArray.size(); i < Math.ceil(leafNumber); i++)
{
	leafTillerNumberArray.add(TillerNumber);
}
