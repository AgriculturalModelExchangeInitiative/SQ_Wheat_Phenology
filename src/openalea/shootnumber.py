import numpy as np 
from copy import copy
from math import *

from fibonacci import * 
def shootnumber(CanopyShootNumber=288.0,
                leafNumber=0.0,
                SowingDensity=288,
                TargetFertileShoot=600.0,
                tilleringProfile=[288],
                leafTillerNumberArray=[1],
                TillerNumber=1):
    """


    CalculateShootNumber Model
    Author: Pierre MARTRE
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA/LEPSE Montpellier
    Abstract: calculate the shoot number and update the related variables if needed

    """
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
    return  AverageShootNumberPerPlant, CanopyShootNumber, leafTillerNumberArray, tilleringProfile, TillerNumber
