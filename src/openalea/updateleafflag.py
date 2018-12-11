import numpy as np 
from copy import copy
from math import *

def updateleafflag(cumulTT=741.510096672,
                   leafNumber=8.91945383336,
                   calendarMoments=['Sowing'],
                   calendarDates=['21/3/2007'],
                   calendarCumuls=[0.0],
                   currentdate='29/4/2007',
                   FinalLeafNumber=8.7975820132,
                   HasFlagLeafLiguleAppeared=1,
                   phase=1.0):
    """


    UpdateLeafFlag Model
    Author: Pierre MARTRE
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: tells if flag leaf has appeared and update the calendar if so
    	

    """
    if (phase >= 1 and phase< 4):
        if (leafNumber > 0):
            if (HasFlagLeafLiguleAppeared == 0 and (FinalLeafNumber > 0 and leafNumber >= FinalLeafNumber)):
                HasFlagLeafLiguleAppeared = 1
                if  "FlagLeafLiguleJustVisible" not in calendarMoments:
                    calendarMoments.append("FlagLeafLiguleJustVisible")
                    calendarCumuls.append(cumulTT)
                    calendarDates.append(currentdate)
        else:
            HasFlagLeafLiguleAppeared = 0
    return  HasFlagLeafLiguleAppeared, calendarMoments, calendarDates, calendarCumuls
