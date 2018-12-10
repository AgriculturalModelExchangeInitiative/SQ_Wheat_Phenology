'Test generation'

from updatecalendar import *
from math import *
import numpy as np



def test_test_wheat1():
    params= updatecalendar(
    phase = 1,
    cumulTT =  112.330110409888,
    calendarDates = ["21/3/2007"],
    calendarCumuls = [0.0],
    calendarMoments = ["Sowing"],
     )
    calendarMoments_estimated = params[0]
    calendarMoments_computed = ["Sowing", "Emergence"]
    assert np.all(calendarMoments_estimated == calendarMoments_computed)
    calendarDates_estimated = params[1]
    calendarDates_computed = ["21/3/2007", "27/3/2007"]
    assert np.all(calendarDates_estimated == calendarDates_computed)
    calendarCumuls_estimated = np.around(params[2], 2)
    calendarCumuls_computed = [ 0.0 ,112.33]
    assert np.all(calendarCumuls_estimated == calendarCumuls_computed)