'Test generation'

from vernalizationprogress import *
from math import *
import numpy as np



def test_test_wheat1():
    params= vernalizationprogress(
    cumulTT =  112.330110409888,
    isVernalizable = 1,
     )
    vernaprog_estimated = round(params[0], 2)
    vernaprog_computed = 0.64
    assert (vernaprog_estimated == vernaprog_computed)
    minFinalNumber_estimated = round(params[1], 2)
    minFinalNumber_computed = 5.5
    assert (minFinalNumber_estimated == minFinalNumber_computed)
    calendarMoments_estimated = params[2]
    calendarMoments_computed = ["Sowing"]
    assert np.all(calendarMoments_estimated == calendarMoments_computed)
    calendarDates_estimated = params[3]
    calendarDates_computed = ["21/3/2007"]
    assert np.all(calendarDates_estimated == calendarDates_computed)
    calendarCumuls_estimated = np.around(params[4], 2)
    calendarCumuls_computed = [0.0]
    assert np.all(calendarCumuls_estimated == calendarCumuls_computed)