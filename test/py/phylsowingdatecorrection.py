import numpy as np 
from copy import copy
from math import *

def phylsowingdatecorrection(SowingDay=1,
                             Latitude=0.0,
                             SDsa_sh=1,
                             Rp=0.0,
                             SDws=1,
                             SDsa_nh=1,
                             P=120.0):
    """


    PhylSowingDateCorrection Model
    Author: Loic Manceau
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: Correction of the Phyllochron Varietal parameter according to sowing date 

    """
    if (Latitude < 0):
        if (SowingDay > SDsa_sh):
            FixPhyll = P * (1 - Rp * min(SowingDay - SDsa_sh, SDws))
        else: FixPhyll = P
    else:
        if (SowingDay < SDsa_nh):
            FixPhyll = P * (1 - Rp * min(SowingDay, SDws))
        else: FixPhyll = P
    return  FixPhyll
