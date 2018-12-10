'Test generation'

from ismomentregistredzc_39 import *
from math import *
import numpy as np



def test_test_wheat1():
    params= ismomentregistredzc_39(
    calendarMoments = ["Sowing", "Emergence", "FloralInitiation", "FlagLeafLiguleJustVisible", "Heading", "Anthesis"],
     )
    isMomentRegistredZC_39_estimated = params
    isMomentRegistredZC_39_computed = 1
    assert (isMomentRegistredZC_39_estimated == isMomentRegistredZC_39_computed)