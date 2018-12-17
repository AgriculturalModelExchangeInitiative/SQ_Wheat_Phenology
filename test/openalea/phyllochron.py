import numpy as np 
from copy import copy
from math import *

def phyllochron(fixPhyll=5.0,
                leafNumber=0.0,
                lincr=8.0,
                ldecr=10.0,
                pdecr=0.4,
                pincr=1.5,
                ptq=0.0,
                gai=0.0,
                pastMaxAI=0.0,
                kl=0.45,
                aPTQ=0.842934,
                phylPTQ1=20.0,
                p=120.0,
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
        if (leafNumber < ldecr): phyllochron = fixPhyll * pdecr
        elif (leafNumber >= ldecr and leafNumber < lincr): phyllochron = fixPhyll
        else: phyllochron = fixPhyll * pincr
    if choosePhyllUse =="PTQ":
        pastMaxAI1 = pastMaxAI
        gai = max(pastMaxAI1,gai)
        pastMaxAI = gai
        if (gai > 0.0): phyllochron = phylPTQ1 * ((gai * kl) / (1 - exp(-kl * gai))) / (ptq + aPTQ)
        else: phyllochron = phylPTQ1      
    if choosePhyllUse == "Test":
        if (leafNumber < ldecr): phyllochron = p * pdecr
        elif (leafNumber >= ldecr and leafNumber < lincr): phyllochron = p
        else: phyllochron = p * pincr
    return  phyllochron, pastMaxAI
