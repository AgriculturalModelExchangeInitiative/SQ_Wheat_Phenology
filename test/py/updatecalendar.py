import numpy as np 
from copy import copy
from math import *

def updatecalendar(cumulTT=741.510096672,
                   calendarMoments=['Sowing'],
                   calendarDates=['21/3/2007'],
                   calendarCumuls=[0.0],
                   currentdate='27/3/2007',
                   phase=1):
    """


    Calendar Model
    Author: Pierre Martre
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: Lists containing for each stage the date it occurs as well as a copy of all types of cumulated thermal times 

    """
    if (phase >= 1 and phase < 2) and ("Emergence" not in calendarMoments ):
        calendarMoments.append("Emergence")
        calendarCumuls.append(cumulTT)
        calendarDates.append(currentdate)
    elif (phase >= 2 and phase < 3)  and ("FloralInitiation" not in calendarMoments ):
        calendarMoments.append("FloralInitiation") 
        calendarCumuls.append(cumulTT)
        calendarDates.append(currentdate)
    elif (phase >= 3 and phase < 4)  and ("Heading" not in calendarMoments ):
        calendarMoments.append("Heading")
        calendarCumuls.append(cumulTT)
        calendarDates.append(currentdate)
    elif (phase == 4)  and ("Anthesis" not in calendarMoments ):
        calendarMoments.append("Anthesis")
        calendarCumuls.append(cumulTT)
        calendarDates.append(currentdate)
    elif (phase == 4.5)  and ("EndCellDivision" not in calendarMoments ):
        calendarMoments.append("EndCellDivision")
        calendarCumuls.append(cumulTT)
        calendarDates.append(currentdate)
    elif (phase >= 5 and phase < 6) and ("EndGrainFilling" not in calendarMoments ):
        calendarMoments.append("EndGrainFilling")
        calendarCumuls.append(cumulTT)
        calendarDates.append(currentdate)
    elif (phase >= 6 and phase < 7)  and ("Maturity" not in calendarMoments ):
        calendarMoments.append("Maturity")
        calendarCumuls.append(cumulTT)
        calendarDates.append(currentdate)
    return  calendarMoments, calendarDates, calendarCumuls
