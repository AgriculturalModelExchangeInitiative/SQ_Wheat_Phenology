

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
		double DLverna = fmax(MinDL, fmin(MaxDL, DayLength));
		Vernaprog += fmax(0, maxVernaProg * (1 + ((IntTvern - TT) / (MaxTvern - IntTvern)) * ((DLverna - MinDL) / (MaxDL - MinDL))));
	}

	double primordno = 2.0 * leafNumber + PNini;
	double minLeafNumber = MinFinalNumber;
	if (Vernaprog >= 1.0 || primordno >= AMXLFNO)
	{
		MinFinalNumber = fmax(primordno, MinFinalNumber);
		calendarMoments.push_back("EndVernalisation");
        calendarCumuls.push_back(cumulTT) ;
        calendarDates.push_back(currentdate);

	}
	else
	{
		double potlfno = AMXLFNO - (AMXLFNO - minLeafNumber) * Vernaprog;
		if (primordno >= potlfno)
		{
			MinFinalNumber = fmax((potlfno + primordno) / 2.0, MinFinalNumber);
			calendarMoments.push_back("EndVernalisation");
        	calendarCumuls.push_back(cumulTT);
        	calendarDates.push_back(currentdate);
			Vernaprog = fmax(1, Vernaprog);
		}

	}
}
