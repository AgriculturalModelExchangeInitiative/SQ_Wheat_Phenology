'Test generation'

from shootnumber import *
from math import *
import numpy as np



def test_test_wheat1():
    params= shootnumber(
    SowingDensity = 288.0,
    TargetFertileShoot = 600.0,
    CanopyShootNumber = 288.0,
    tilleringProfile = [288.0],
    leafNumber = 3.34348137255,
    leafTillerNumberArray = [1, 1, 1],
     )
    AverageShootNumberPerPlant_estimated = round(params[0], 2)
    AverageShootNumberPerPlant_computed = 2
    assert (AverageShootNumberPerPlant_estimated == AverageShootNumberPerPlant_computed)
    CanopyShootNumber_estimated = round(params[1], 1)
    CanopyShootNumber_computed = 576
    assert (CanopyShootNumber_estimated == CanopyShootNumber_computed)
    leafTillerNumberArray_estimated = params[2]
    leafTillerNumberArray_computed = [1, 1, 1, 2]
    assert np.all(leafTillerNumberArray_estimated == leafTillerNumberArray_computed)
    tilleringProfile_estimated = np.around(params[3], 2)
    tilleringProfile_computed = [288.0, 288.0]
    assert np.all(tilleringProfile_estimated == tilleringProfile_computed)
    TillerNumber_estimated = params[4]
    TillerNumber_computed = 2
    assert (TillerNumber_estimated == TillerNumber_computed)