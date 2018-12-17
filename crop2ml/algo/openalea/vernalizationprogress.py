import numpy as np 
from copy import copy
from math import *

def vernalizationprogress(DayLength=12.3037621834,
                          DeltaTT=20.3429985012,
                          cumulTT=112.33011041,
                          leafNumber=0.0,
                          calendarMoments=['Sowing'],
                          calendarDates=['21/3/2007'],
                          calendarCumuls=[0.0],
                          MinTvern=0.0,
                          IntTvern=11.0,
                          VAI=0.015,
                          VBEE=0.01,
                          MinDL=8.0,
                          MaxDL=15.0,
                          MaxTvern=23.0,
                          PNini=4.0,
                          AMXLFNO=24.0,
                          Vernaprog=0.551725418738,
                          currentdate='27/3/2007',
                          IsVernalizable=1,
                          MinFinalNumber=5.5):
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
    if (IsVernalizable==1 and Vernaprog < 1):
        TT = DeltaTT
        if (TT >= MinTvern and TT <= IntTvern):
            Vernaprog = Vernaprog + VAI * TT + VBEE
        if (TT > IntTvern):
            maxVernaProg = VAI * IntTvern + VBEE
            DLverna = max(MinDL, min(MaxDL, DayLength))
            Vernaprog += max(0, maxVernaProg * (1 + ((IntTvern - TT) / (MaxTvern - IntTvern)) * ((DLverna - MinDL) / (MaxDL - MinDL))))
        primordno = 2.0 * leafNumber + PNini
        minLeafNumber = MinFinalNumber
        if (Vernaprog >= 1.0 or primordno >= AMXLFNO):
            MinFinalNumber = max(primordno, MinFinalNumber)
            calendarMoments.append("EndVernalisation")
            calendarCumuls.append(cumulTT) 
            calendarDates.append(currentdate)        
            Vernaprog = max(1, Vernaprog)
        else:
            potlfno = AMXLFNO - (AMXLFNO - minLeafNumber) * Vernaprog
            if (primordno >= potlfno):
                MinFinalNumber = max((potlfno + primordno) / 2.0, MinFinalNumber)
                Vernaprog = max(1, Vernaprog)
                calendarMoments.append("EndVernalisation")
                calendarCumuls.append(cumulTT) 
                calendarDates.append(currentdate)
    return  Vernaprog, MinFinalNumber, calendarMoments, calendarDates, calendarCumuls
