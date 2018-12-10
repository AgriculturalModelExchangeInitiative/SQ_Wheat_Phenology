import numpy as np 
from copy import copy
from math import *

def ismomentregistredzc_39(calendarMoments=['Sowing']):
    """


    IsMomentRegistredZC39 Model
    Author: Pierre Martre
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: if FlagLeafLiguleJustVisible is already Registred 

    """
    isMomentRegistredZC_39 = 1 if "FlagLeafLiguleJustVisible" in calendarMoments else 0
    return  isMomentRegistredZC_39
