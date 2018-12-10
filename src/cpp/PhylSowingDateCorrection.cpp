
if (Latitude < 0)
{
	if (SowingDay > SDsa_sh)
	{
		FixPhyll = P * (1 - Rp * fmin(SowingDay - SDsa_sh, SDws));
	}
	else FixPhyll = P;
}
else
{
	if (SowingDay < SDsa_nh)
	{
		FixPhyll = P * (1 - Rp * fmin(SowingDay, SDws));
	}
	else FixPhyll = P;
}
