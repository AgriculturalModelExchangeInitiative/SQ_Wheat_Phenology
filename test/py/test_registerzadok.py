'Test generation'

from registerzadok import *
from math import *
import numpy as np



def test_test_wheat1():
    params= registerzadok(
    slopeTSFLN = 0.9,
    calendarCumuls = [ 0.0, 112.330110409888,157.969706915664, 280.570678654207],
    calendarMoments = ["Sowing","Emergence","EndVernalisation","MainShootPlus1Tiller"],
    phase = 2,
    calendarDates = ["21/3/2007","27/3/2007","30/3/2007","5/4/2007"],
    TSFLN = 2.6,
     )
    hasZadokStageChanged_estimated = params[0]
    hasZadokStageChanged_computed = 0
    assert (hasZadokStageChanged_estimated == hasZadokStageChanged_computed)
    currentZadokStage_estimated = params[1]
    currentZadokStage_computed = "MainShootPlus1Tiller"
    assert (currentZadokStage_estimated == currentZadokStage_computed)
    calendarMoments_estimated = params[2]
    calendarMoments_computed = ["Sowing","Emergence","EndVernalisation","MainShootPlus1Tiller"]
    assert np.all(calendarMoments_estimated == calendarMoments_computed)
    calendarDates_estimated = params[3]
    calendarDates_computed = ["21/3/2007", "27/3/2007", "30/3/2007", "5/4/2007"]
    assert np.all(calendarDates_estimated == calendarDates_computed)
    calendarCumuls_estimated = np.around(params[4], 2)
    calendarCumuls_computed = [ 0.0, 112.33,157.97, 280.57]
    assert np.all(calendarCumuls_estimated == calendarCumuls_computed)