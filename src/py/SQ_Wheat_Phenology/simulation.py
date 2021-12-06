from . import PhenologyComponent
import pandas as pd
import os

def simulation(datafile, vardata, params, init):
    rep = os.path.dirname(datafile)
    out = os.path.join(rep, 'output.csv')
    df = pd.read_csv(datafile, sep = ";")

    # inputs values
    t_currentdate = df[vardata.loc[vardata["Variables"]=="currentdate","Data columns"].iloc[0]].to_list()
    t_cumulTT = df[vardata.loc[vardata["Variables"]=="cumulTT","Data columns"].iloc[0]].to_list()
    t_ptq = df[vardata.loc[vardata["Variables"]=="ptq","Data columns"].iloc[0]].to_list()
    t_dayLength = df[vardata.loc[vardata["Variables"]=="dayLength","Data columns"].iloc[0]].to_list()
    t_deltaTT = df[vardata.loc[vardata["Variables"]=="deltaTT","Data columns"].iloc[0]].to_list()
    t_gAI = df[vardata.loc[vardata["Variables"]=="gAI","Data columns"].iloc[0]].to_list()
    t_pAR = df[vardata.loc[vardata["Variables"]=="pAR","Data columns"].iloc[0]].to_list()
    t_grainCumulTT = df[vardata.loc[vardata["Variables"]=="grainCumulTT","Data columns"].iloc[0]].to_list()
    t_currentZadokStage = df[vardata.loc[vardata["Variables"]=="currentZadokStage","Data columns"].iloc[0]].to_list()
    t_hasFlagLeafLiguleAppeared = df[vardata.loc[vardata["Variables"]=="hasFlagLeafLiguleAppeared","Data columns"].iloc[0]].to_list()

    #parameters
    aMXLFNO = params.loc[params["name"]=="aMXLFNO", "value"].iloc[0]
    pNini = params.loc[params["name"]=="pNini", "value"].iloc[0]
    sDsa_sh = params.loc[params["name"]=="sDsa_sh", "value"].iloc[0]
    latitude = params.loc[params["name"]=="latitude", "value"].iloc[0]
    kl = params.loc[params["name"]=="kl", "value"].iloc[0]
    lincr = params.loc[params["name"]=="lincr", "value"].iloc[0]
    ldecr = params.loc[params["name"]=="ldecr", "value"].iloc[0]
    pincr = params.loc[params["name"]=="pincr", "value"].iloc[0]
    pTQhf = params.loc[params["name"]=="pTQhf", "value"].iloc[0]
    B = params.loc[params["name"]=="B", "value"].iloc[0]
    areaSL = params.loc[params["name"]=="areaSL", "value"].iloc[0]
    areaSS = params.loc[params["name"]=="areaSS", "value"].iloc[0]
    lARmin = params.loc[params["name"]=="lARmin", "value"].iloc[0]
    sowingDensity = params.loc[params["name"]=="sowingDensity", "value"].iloc[0]
    lARmax = params.loc[params["name"]=="lARmax", "value"].iloc[0]
    lNeff = params.loc[params["name"]=="lNeff", "value"].iloc[0]
    rp = params.loc[params["name"]=="rp", "value"].iloc[0]
    p = params.loc[params["name"]=="p", "value"].iloc[0]
    pdecr = params.loc[params["name"]=="pdecr", "value"].iloc[0]
    maxTvern = params.loc[params["name"]=="maxTvern", "value"].iloc[0]
    tTWindowForPTQ = params.loc[params["name"]=="tTWindowForPTQ", "value"].iloc[0]
    vBEE = params.loc[params["name"]=="vBEE", "value"].iloc[0]
    isVernalizable = params.loc[params["name"]=="isVernalizable", "value"].iloc[0]
    minTvern = params.loc[params["name"]=="minTvern", "value"].iloc[0]
    intTvern = params.loc[params["name"]=="intTvern", "value"].iloc[0]
    vAI = params.loc[params["name"]=="vAI", "value"].iloc[0]
    maxDL = params.loc[params["name"]=="maxDL", "value"].iloc[0]
    choosePhyllUse = params.loc[params["name"]=="choosePhyllUse", "value"].iloc[0]
    minDL = params.loc[params["name"]=="minDL", "value"].iloc[0]
    pFLLAnth = params.loc[params["name"]=="pFLLAnth", "value"].iloc[0]
    dcd = params.loc[params["name"]=="dcd", "value"].iloc[0]
    dgf = params.loc[params["name"]=="dgf", "value"].iloc[0]
    degfm = params.loc[params["name"]=="degfm", "value"].iloc[0]
    ignoreGrainMaturation = params.loc[params["name"]=="ignoreGrainMaturation", "value"].iloc[0]
    pHEADANTH = params.loc[params["name"]=="pHEADANTH", "value"].iloc[0]
    sLDL = params.loc[params["name"]=="sLDL", "value"].iloc[0]
    sowingDay = params.loc[params["name"]=="sowingDay", "value"].iloc[0]
    sowingDate = params.loc[params["name"]=="sowingDate", "value"].iloc[0]
    sDws = params.loc[params["name"]=="sDws", "value"].iloc[0]
    sDsa_nh = params.loc[params["name"]=="sDsa_nh", "value"].iloc[0]
    der = params.loc[params["name"]=="der", "value"].iloc[0]
    targetFertileShoot = params.loc[params["name"]=="targetFertileShoot", "value"].iloc[0]
    dse = params.loc[params["name"]=="dse", "value"].iloc[0]
    slopeTSFLN = params.loc[params["name"]=="slopeTSFLN", "value"].iloc[0]
    intTSFLN = params.loc[params["name"]=="intTSFLN", "value"].iloc[0]

    #initialization
    phyllochron_t1 = init.loc[init["name"]=="phyllochron_t1", "value"].iloc[0]
    minFinalNumber_t1 = init.loc[init["name"]=="minFinalNumber_t1", "value"].iloc[0]
    calendarDates_t1 = init.loc[init["name"]=="calendarDates_t1", "value"].iloc[0]
    calendarMoments_t1 = init.loc[init["name"]=="calendarMoments_t1", "value"].iloc[0]
    leafNumber_t1 = init.loc[init["name"]=="leafNumber_t1", "value"].iloc[0]
    pastMaxAI_t1 = init.loc[init["name"]=="pastMaxAI_t1", "value"].iloc[0]
    listGAITTWindowForPTQ_t1 = init.loc[init["name"]=="listGAITTWindowForPTQ_t1", "value"].iloc[0]
    listPARTTWindowForPTQ_t1 = init.loc[init["name"]=="listPARTTWindowForPTQ_t1", "value"].iloc[0]
    listTTShootWindowForPTQ1_t1 = init.loc[init["name"]=="listTTShootWindowForPTQ1_t1", "value"].iloc[0]
    listTTShootWindowForPTQ_t1 = init.loc[init["name"]=="listTTShootWindowForPTQ_t1", "value"].iloc[0]
    calendarCumuls_t1 = init.loc[init["name"]=="calendarCumuls_t1", "value"].iloc[0]
    vernaprog_t1 = init.loc[init["name"]=="vernaprog_t1", "value"].iloc[0]
    hasLastPrimordiumAppeared_t1 = init.loc[init["name"]=="hasLastPrimordiumAppeared_t1", "value"].iloc[0]
    phase_t1 = init.loc[init["name"]=="phase_t1", "value"].iloc[0]
    finalLeafNumber_t1 = init.loc[init["name"]=="finalLeafNumber_t1", "value"].iloc[0]
    hasZadokStageChanged_t1 = init.loc[init["name"]=="hasZadokStageChanged_t1", "value"].iloc[0]
    hasFlagLeafLiguleAppeared_t1 = init.loc[init["name"]=="hasFlagLeafLiguleAppeared_t1", "value"].iloc[0]
    tilleringProfile_t1 = init.loc[init["name"]=="tilleringProfile_t1", "value"].iloc[0]
    leafTillerNumberArray_t1 = init.loc[init["name"]=="leafTillerNumberArray_t1", "value"].iloc[0]
    canopyShootNumber_t1 = init.loc[init["name"]=="canopyShootNumber_t1", "value"].iloc[0]

    #outputs
    output_names = ["currentZadokStage","hasZadokStageChanged","hasFlagLeafLiguleAppeared","listPARTTWindowForPTQ","hasLastPrimordiumAppeared","listTTShootWindowForPTQ","listTTShootWindowForPTQ1","ptq","calendarMoments","canopyShootNumber","calendarDates","leafTillerNumberArray","vernaprog","phyllochron","leafNumber","numberTillerCohort","tilleringProfile","averageShootNumberPerPlant","minFinalNumber","finalLeafNumber","phase","listGAITTWindowForPTQ","calendarCumuls","gAImean","pastMaxAI"]

    df_out = pd.DataFrame(columns = output_names)
    for i in range(0,len(df.index)-1):
        currentdate = t_currentdate[i]
        cumulTT = t_cumulTT[i]
        ptq = t_ptq[i]
        dayLength = t_dayLength[i]
        deltaTT = t_deltaTT[i]
        gAI = t_gAI[i]
        pAR = t_pAR[i]
        grainCumulTT = t_grainCumulTT[i]
        currentZadokStage = t_currentZadokStage[i]
        hasFlagLeafLiguleAppeared = t_hasFlagLeafLiguleAppeared[i]
        currentZadokStage,hasZadokStageChanged,hasFlagLeafLiguleAppeared,listPARTTWindowForPTQ,hasLastPrimordiumAppeared,listTTShootWindowForPTQ,listTTShootWindowForPTQ1,ptq,calendarMoments,canopyShootNumber,calendarDates,leafTillerNumberArray,vernaprog,phyllochron,leafNumber,numberTillerCohort,tilleringProfile,averageShootNumberPerPlant,minFinalNumber,finalLeafNumber,phase,listGAITTWindowForPTQ,calendarCumuls,gAImean,pastMaxAI= PhenologyComponent.model_phenology(phyllochron_t1,minFinalNumber_t1,aMXLFNO,currentdate,cumulTT,pNini,sDsa_sh,latitude,kl,calendarDates_t1,calendarMoments_t1,lincr,ldecr,pincr,ptq,pTQhf,B,areaSL,areaSS,lARmin,sowingDensity,lARmax,lNeff,rp,p,pdecr,leafNumber_t1,maxTvern,dayLength,deltaTT,pastMaxAI_t1,tTWindowForPTQ,listGAITTWindowForPTQ_t1,gAI,pAR,listPARTTWindowForPTQ_t1,listTTShootWindowForPTQ1_t1,listTTShootWindowForPTQ_t1,vBEE,calendarCumuls_t1,isVernalizable,vernaprog_t1,minTvern,intTvern,vAI,maxDL,choosePhyllUse,minDL,hasLastPrimordiumAppeared_t1,phase_t1,pFLLAnth,dcd,dgf,degfm,ignoreGrainMaturation,pHEADANTH,finalLeafNumber_t1,sLDL,grainCumulTT,sowingDay,hasZadokStageChanged_t1,currentZadokStage,sowingDate,sDws,sDsa_nh,hasFlagLeafLiguleAppeared,der,hasFlagLeafLiguleAppeared_t1,tilleringProfile_t1,targetFertileShoot,leafTillerNumberArray_t1,dse,slopeTSFLN,intTSFLN,canopyShootNumber_t1)

        phyllochron_t1 = phyllochron
        minFinalNumber_t1 = minFinalNumber
        calendarDates_t1 = calendarDates
        calendarMoments_t1 = calendarMoments
        leafNumber_t1 = leafNumber
        pastMaxAI_t1 = pastMaxAI
        listGAITTWindowForPTQ_t1 = listGAITTWindowForPTQ
        listPARTTWindowForPTQ_t1 = listPARTTWindowForPTQ
        listTTShootWindowForPTQ1_t1 = listTTShootWindowForPTQ1
        listTTShootWindowForPTQ_t1 = listTTShootWindowForPTQ
        calendarCumuls_t1 = calendarCumuls
        vernaprog_t1 = vernaprog
        hasLastPrimordiumAppeared_t1 = hasLastPrimordiumAppeared
        phase_t1 = phase
        finalLeafNumber_t1 = finalLeafNumber
        hasZadokStageChanged_t1 = hasZadokStageChanged
        hasFlagLeafLiguleAppeared_t1 = hasFlagLeafLiguleAppeared
        tilleringProfile_t1 = tilleringProfile
        leafTillerNumberArray_t1 = leafTillerNumberArray
        canopyShootNumber_t1 = canopyShootNumber
        df_out.loc[i] = [currentZadokStage,hasZadokStageChanged,hasFlagLeafLiguleAppeared,listPARTTWindowForPTQ,hasLastPrimordiumAppeared,listTTShootWindowForPTQ,listTTShootWindowForPTQ1,ptq,calendarMoments,canopyShootNumber,calendarDates,leafTillerNumberArray,vernaprog,phyllochron,leafNumber,numberTillerCohort,tilleringProfile,averageShootNumberPerPlant,minFinalNumber,finalLeafNumber,phase,listGAITTWindowForPTQ,calendarCumuls,gAImean,pastMaxAI]
    df_out.insert(0, 'date', pd.to_datetime(df.year*10000 + df.month*100 + df.day, format='%Y%m%d'), True)
    df_out.set_index("date", inplace=True)
    df_out.to_csv(out, sep=";")
    return df_out