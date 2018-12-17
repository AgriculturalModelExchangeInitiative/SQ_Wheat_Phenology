import numpy as np 
from copy import copy
from math import *

from fibonacci import * 
def shootnumber(canopyShootNumber=288.0,
                leafNumber=0.0,
                sowingDensity=288,
                targetFertileShoot=600.0,
                tilleringProfile=[288],
                leafTillerNumberArray=[1],
                tillerNumber=1):
    """


    CalculateShootNumber Model
    Author: Pierre MARTRE
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA/LEPSE Montpellier
    Abstract: calculate the shoot number and update the related variables if needed

    """
    oldCanopyShootNumber = canopyShootNumber
    emergedLeaves = int(max(1, ceil(leafNumber - 1)))
    shoots = fibonacci(emergedLeaves)
    canopyShootNumber = min(shoots * sowingDensity, targetFertileShoot)
    averageShootNumberPerPlant = canopyShootNumber / sowingDensity       
    if (canopyShootNumber != oldCanopyShootNumber):
        tilleringProfile.append(canopyShootNumber - oldCanopyShootNumber)         
    tillerNumber = len(tilleringProfile)     
    for i in range(len(leafTillerNumberArray),int(ceil(leafNumber))):
        leafTillerNumberArray.append(tillerNumber)
    return  averageShootNumberPerPlant, canopyShootNumber, leafTillerNumberArray, tilleringProfile, tillerNumber
