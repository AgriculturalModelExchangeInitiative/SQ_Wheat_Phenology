'Test generation'

from updatephase import *
from math import *
import numpy as np



def test_test_wheat1():
    params= updatephase(
    phase = 1,
    switchMaize = 0,
    hasLastPrimordiumAppeared = 0,
    choosePhyllUse = "Default",
     )
    finalLeafNumber_estimated = round(params[0], 2)
    finalLeafNumber_computed = 8.80
    assert (finalLeafNumber_estimated == finalLeafNumber_computed)
    phase_estimated = round(params[1], 1)
    phase_computed = 2
    assert (phase_estimated == phase_computed)
    hasLastPrimordiumAppeared_estimated = params[2]
    hasLastPrimordiumAppeared_computed = 1
    assert (hasLastPrimordiumAppeared_estimated == hasLastPrimordiumAppeared_computed)