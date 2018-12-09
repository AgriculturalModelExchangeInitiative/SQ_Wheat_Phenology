
if (IsVernalizable==1 && Vernaprog < 1)
{
	double TT = DeltaTT; // other sirius versions use previous temperature value

	if (TT >= MinTvern && TT <= IntTvern)
	{
		Vernaprog = Vernaprog + VAI * TT + VBEE;
	}

	if (TT > IntTvern)
	{
		double maxVernaProg = VAI * IntTvern + VBEE;
		double DLverna = Math.max(MinDL, Math.min(MaxDL, DayLength));
		Vernaprog += Math.max(0, maxVernaProg * (1 + ((IntTvern - TT) / (MaxTvern - IntTvern)) * ((DLverna - MinDL) / (MaxDL - MinDL))));
	}
			
	double primordno = 2.0 * leafNumber + PNini;
	double minLeafNumber = MinFinalNumber;
	if (Vernaprog >= 1.0 || primordno >= AMXLFNO)
	{
		MinFinalNumber = Math.max(primordno, MinFinalNumber);
		calendarMoments.add("EndVernalisation");
        calendarCumuls.add(cumulTT) ;
        calendarDates.add(currentdate);  

	}
	else
	{
		double potlfno = AMXLFNO - (AMXLFNO - minLeafNumber) * Vernaprog;
		if (primordno >= potlfno)
		{
			MinFinalNumber = Math.max((potlfno + primordno) / 2.0, MinFinalNumber);	
			calendarMoments.add("EndVernalisation");
        	calendarCumuls.add(cumulTT);
        	calendarDates.add(currentdate);  					
			Vernaprog = Math.max(1, Vernaprog);
		}

	}
}
