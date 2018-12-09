
double OldCanopyShootNumber = CanopyShootNumber;
int EmergedLeaves = (int)Math.Max(1, Math.Ceiling(leafNumber - 1));
int Shoots = fibonacci(EmergedLeaves);

CanopyShootNumber = Math.Min(Shoots * SowingDensity, TargetFertileShoot);
AverageShootNumberPerPlant = CanopyShootNumber / SowingDensity;

if (CanopyShootNumber != OldCanopyShootNumber)
{
	tilleringProfile.Add(CanopyShootNumber - OldCanopyShootNumber);
}
		
TillerNumber = tilleringProfile.Count;
		
for (int i = leafTillerNumberArray.Count; i < Math.Ceiling(leafNumber); i++)
{
	leafTillerNumberArray.Add(TillerNumber);
}
