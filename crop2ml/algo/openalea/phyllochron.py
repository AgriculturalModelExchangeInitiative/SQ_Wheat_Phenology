import numpy as np 
from copy import copy
from math import *

def phyllochron(FixPhyll=5.0,
                leafNumber=0.0,
                Lincr=8.0,
                Ldecr=10.0,
                Pdecr=0.4,
                Pincr=1.5,
                LAI=0.0,
                PTQ=0.0,
                GAI=0.0,
                pastMaxAI=0.0,
                Kl=0.45,
                aPTQ=0.842934,
                PhylPTQ1=20.0,
                P=120.0,
                choosePhyllUse='Default'):
    """


    Phyllochron Model
    Author: Pierre Martre
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: Calculate different types of phyllochron 

    """
    if choosePhyllUse =="Default":
        if (leafNumber < Ldecr): phyllochron = FixPhyll * Pdecr
        elif (leafNumber >= Ldecr and leafNumber < Lincr): phyllochron = FixPhyll
        else: phyllochron = FixPhyll * Pincr
    if choosePhyllUse =="PTQ":
        pastMaxAI1 = pastMaxAI
        GAI = max(pastMaxAI1,GAI)
        pastMaxAI = GAI
        if (GAI > 0.0): phyllochron = PhylPTQ1 * ((GAI * Kl) / (1 - exp(-Kl * GAI))) / (PTQ + aPTQ)
        else: phyllochron = PhylPTQ1
    if choosePhyllUse == "Test":
        if (leafNumber < Ldecr): phyllochron = P * Pdecr
        elif (leafNumber >= Ldecr and leafNumber < Lincr): phyllochron = P
        else: phyllochron = P * Pincr
    return  phyllochron, pastMaxAI
