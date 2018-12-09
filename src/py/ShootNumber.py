OldCanopyShootNumber = CanopyShootNumber
EmergedLeaves = int(max(1, ceil(leafNumber - 1)))

Shoots = fibonacci(EmergedLeaves)

CanopyShootNumber = min(Shoots * SowingDensity, TargetFertileShoot)
AverageShootNumberPerPlant = CanopyShootNumber / SowingDensity
 
        
if (CanopyShootNumber != OldCanopyShootNumber):
    diff = CanopyShootNumber - OldCanopyShootNumber
    tilleringProfile.append(diff)
           
TillerNumber = len(tilleringProfile)
        
for i in range(len(leafTillerNumberArray),int(ceil(leafNumber))):
    leafTillerNumberArray.append(TillerNumber)
    



