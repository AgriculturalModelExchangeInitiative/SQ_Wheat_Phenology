'Test generation'

from updateleafflag import *
from math import *
import numpy as np



def test_test_wheat1():
    params= updateleafflag(
    phase = 3,
    calendarDates = ["21/3/2007", "27/3/2007", "30/3/2007", "5/4/2007", "9/4/2007", "10/4/2007", "11/4/2007", "12/4/2007", "14/4/2007", "15/4/2007", "19/4/2007", "24/4/2007"],
    calendarCumuls = [0.0, 112.330110409888, 157.969706915664, 280.570678654207, 354.582294511779, 378.453152853726, 402.042720581446, 424.98704708663, 467.23305195298, 487.544313430698, 560.665248444002, 646.389617338974],
    calendarMoments = ["Sowing", "Emergence", "EndVernalisation", "MainShootPlus1Tiller", "FloralInitiation", "MainShootPlus2Tiller", "TerminalSpikelet", "PseudoStemErection", "MainShootPlus3Tiller", "1stNodeDetectable", "2ndNodeDetectable", "FlagLeafJustVisible"],
    hasFlagLeafLiguleAppeared = 0,
     )
    hasFlagLeafLiguleAppeared_estimated = params[0]
    hasFlagLeafLiguleAppeared_computed = 1
    assert (hasFlagLeafLiguleAppeared_estimated == hasFlagLeafLiguleAppeared_computed)
    calendarMoments_estimated = params[1]
    calendarMoments_computed = ["Sowing", "Emergence", "EndVernalisation", "MainShootPlus1Tiller", "FloralInitiation", "MainShootPlus2Tiller", "TerminalSpikelet", "PseudoStemErection", "MainShootPlus3Tiller", "1stNodeDetectable", "2ndNodeDetectable", "FlagLeafJustVisible", "FlagLeafLiguleJustVisible"]
    assert np.all(calendarMoments_estimated == calendarMoments_computed)
    calendarDates_estimated = params[2]
    calendarDates_computed = ["21/3/2007", "27/3/2007", "30/3/2007", "5/4/2007", "9/4/2007", "10/4/2007", "11/4/2007", "12/4/2007", "14/4/2007", "15/4/2007", "19/4/2007", "24/4/2007", "29/4/2007"]
    assert np.all(calendarDates_estimated == calendarDates_computed)
    calendarCumuls_estimated = np.around(params[3], 2)
    calendarCumuls_computed = [0.0, 112.33, 157.97, 280.57, 354.58, 378.45, 402.04, 424.99, 467.23, 487.54, 560.67, 646.39, 741.51]
    assert np.all(calendarCumuls_estimated == calendarCumuls_computed)