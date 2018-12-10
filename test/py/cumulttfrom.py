import numpy as np 
from copy import copy
from math import *

def cumulttfrom(calendarMoments=['Sowing'],
                calendarCumuls=[0.0],
                SwitchMaize=0,
                cumulTT=8.0):
    """


    CumulTTFrom Model
    Author: Pierre Martre
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: Calculate CumulTT 

    """
    cumulTTFromZC_65 = 0
    cumulTTFromZC_39 = 0
    cumulTTFromZC_91 = 0
    if "Anthesis" in calendarMoments:
        if (SwitchMaize == 0): cumulTTFromZC_65 = cumulTT-calendarCumuls[calendarMoments.index("Anthesis")]
    if "FlagLeafLiguleJustVisible" in calendarMoments:
        if (SwitchMaize == 0): cumulTTFromZC_39 = cumulTT-calendarCumuls[calendarMoments.index("FlagLeafLiguleJustVisible")]
    if "EndGrainFilling"in calendarMoments:
        if (SwitchMaize == 0): cumulTTFromZC_91 = cumulTT-calendarCumuls[calendarMoments.index("FlagLeafLiguleJustVisible")]
    return  cumulTTFromZC_65, cumulTTFromZC_39, cumulTTFromZC_91
