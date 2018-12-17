import numpy as np 
from copy import copy
from math import *

def vernalizationprogress(dayLength=12.3037621834,
                          deltaTT=20.3429985012,
                          cumulTT=112.33011041,
                          leafNumber=0.0,
                          calendarMoments=['Sowing'],
                          calendarDates=['21/3/2007'],
                          calendarCumuls=[0.0],
                          minTvern=0.0,
                          intTvern=11.0,
                          vAI=0.015,
                          vBEE=0.01,
                          minDL=8.0,
                          maxDL=15.0,
                          maxTvern=23.0,
                          pNini=4.0,
                          aMXLFNO=24.0,
                          vernaprog=0.551725418738,
                          currentdate='27/3/2007',
                          isVernalizable=1,
                          minFinalNumber=5.5):
    """


    VernalizationProgress Model
    Author: Pierre MARTRE
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: Calculate progress (VernaProg) towards vernalization, but there 
        			is no vernalization below minTvern 
        			and above maxTvern . The maximum value of VernaProg is 1.
        			Progress towards full vernalization is a linear function of shoot 
        			temperature (soil temperature until leaf # reach MaxLeafSoil and then
        			 canopy temperature)
    	

    """
    if (isVernalizable==1 and vernaprog < 1):
        tt = deltaTT       
        if (tt >= minTvern and tt <= intTvern):
            vernaprog = vernaprog + vAI * tt + vBEE      
        if (tt > intTvern):
            maxVernaProg = vAI * intTvern + vBEE
            dLverna = max(minDL, min(maxDL, dayLength))
            vernaprog += max(0, maxVernaProg * (1 + ((intTvern - tt) / (maxTvern - intTvern)) * ((dLverna - minDL) / (maxDL - minDL))))      
        primordno = 2.0 * leafNumber + pNini     
        minLeafNumber = minFinalNumber
        if (vernaprog >= 1.0 or primordno >= aMXLFNO):      
            minFinalNumber = max(primordno, minFinalNumber)
            calendarMoments.append("EndVernalisation")
            calendarCumuls.append(cumulTT) 
            calendarDates.append(currentdate)        
            vernaprog = max(1, vernaprog)      
        else:    
            potlfno = aMXLFNO - (aMXLFNO - minLeafNumber) * vernaprog
            if (primordno >= potlfno):    
                minFinalNumber = max((potlfno + primordno) / 2.0, minFinalNumber)
                vernaprog = max(1, vernaprog)
                calendarMoments.append("EndVernalisation")
                calendarCumuls.append(cumulTT) 
                calendarDates.append(currentdate)
    return  vernaprog, minFinalNumber, calendarMoments, calendarDates, calendarCumuls
