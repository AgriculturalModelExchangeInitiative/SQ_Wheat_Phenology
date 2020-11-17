#include <iostream>
#include <vector>
#include "CumulFROM.h"
#include<math.h>
#include<time.h>
#include<ctime>
#include "IsMomentRegistredZC_39.h"
#include "LeafNumberModule.h"
#include "RegisterZadok.h"
#include "UpdatePhase.h"
#include "UpdateLeafFlag.h"
#include "updateCalendar.h"
#include "ShootNumber.h"
#include "VernalizationProgress.h"
#include "PhyllochronModule.h"
#include "PhylSowingDateCorrection.h"

using namespace std;

void test_CumulFROM()
{
    vector<string> calendarMoments {"Sowing", "Emergence", "FloralInitiation", "FlagLeafLiguleJustVisible", "Heading", "Anthesis"};
    vector<double> calendarCumuls {0.0, 112.330110409888, 354.582294511779, 741.510096671757, 853.999637026622, 954.59002776961};
    double cumulTT = 972.970888983105;
    int switchMaize = 0;
    double cumulTTFromZC_39 ;
    double cumulTTFromZC_65 ;
    double cumulTTFromZC_91;
    cumulTTFromZC_39 = Calculate_Cumulfrom(cumulTT, calendarMoments, calendarCumuls,switchMaize ).cumulTTFromZC_39;
    cumulTTFromZC_65 = Calculate_Cumulfrom(cumulTT, calendarMoments, calendarCumuls,switchMaize ).cumulTTFromZC_65;
    cumulTTFromZC_91 = Calculate_Cumulfrom(cumulTT, calendarMoments, calendarCumuls,switchMaize ).cumulTTFromZC_91;

    cout <<"cumulTTFromZC_39     "<<cumulTTFromZC_39<< endl;
    cout <<"cumulTTFromZC_65     "<<cumulTTFromZC_65<< endl;
    cout <<"cumulTTFromZC_91     "<<cumulTTFromZC_91<< endl;
    cout<<"cumulTTFromZC_39_est != cumulTTFromZC_39_calc??  "<< bool((round(cumulTTFromZC_39 * pow(10, 2))) / pow(10, 2)-231.46 < 0.01) <<endl ;
    cout<<"cumulTTFromZC_65_est != cumulTTFromZC_65_calc??  "<< bool((round(cumulTTFromZC_65 * pow(10, 2))) / pow(10, 2)-18.38 < 0.01) <<endl ;
    cout<<"cumulTTFromZC_91_est != cumulTTFromZC_91_calc??  "<< bool((round(cumulTTFromZC_91 * pow(10, 2))) / pow(10, 2)-0 < 0.01) <<endl ;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

}

void test_IsMomentRegistredZC_39()
{
    vector<string> calendarMoments{"Sowing", "Emergence", "FloralInitiation", "FlagLeafLiguleJustVisible", "Heading", "Anthesis"};
    int isMomentRegistredZC_39;
    isMomentRegistredZC_39 = Calculate_IsMomentRegistredZC_39(calendarMoments).isMomentRegistredZC_39;
    cout <<"IsmomentRegistredZC_39    "<<isMomentRegistredZC_39<< endl;

    cout<<"isMomentRegistredZC_39_est != isMomentRegistredZC_39_calc??  "<< bool(isMomentRegistredZC_39-1 == 0)<<endl ;
    cout<<"----------------------------------------------------------------------------------------"<<endl;


}
void test_LeafNumberModule()
{
    double deltaTT = 23.5895677277199;
    double phyllochron = 91.2;
    int hasFlagLeafLiguleAppeared = 0 ;
    int switchMaize = 0;
    double atip = 10;
    double leaf_tip_emerg = 10 ;
    double k_bl = 1.412 ;
    double nlim = 6.617;
    double leafNumber = 5.147163833893262;
    double cumulTTPhenoMaizeAtEmergence = 300;
    double cumulTT = 402.042720581446;
    double phase =3 ;
    double Ntip;

    cout<<"--------------------------------------------test leafNumber------------------------------"<<endl;

    leafNumber = Calculate_LeafNumber(deltaTT,phyllochron, hasFlagLeafLiguleAppeared, switchMaize, atip, leaf_tip_emerg, k_bl, nlim, leafNumber, cumulTTPhenoMaizeAtEmergence, cumulTT, phase).leafNumber;
    Ntip = Calculate_LeafNumber(deltaTT,phyllochron, hasFlagLeafLiguleAppeared, switchMaize, atip, leaf_tip_emerg, k_bl, nlim, leafNumber, cumulTTPhenoMaizeAtEmergence, cumulTT, phase).ntip;
    cout <<"leafNumber    "<<leafNumber<< endl;
    cout <<"Ntip    "<<Ntip<< endl;

    cout<<"leafNumber_est != leafNumber_calc??  "<< bool((round(leafNumber * pow(10, 2))) / pow(10, 2)-5.41 < pow(10, 2)) <<endl ;
    cout<<"Ntip _est != Ntip _calc??  "<< bool((round(Ntip  * pow(10, 2))) / pow(10, 2)-0 < pow(10, 2)) <<endl ;

}


void test_RegisterZadok()
{

    double cumulTT = 354.582294511779;
    double phase = 2;
    double leafNumber = 4.8854219661087575;
    vector<string> calendarMoments{"Sowing","Emergence","EndVernalisation","MainShootPlus1Tiller"};
    vector<string>calendarDates{"21/3/2007","27/3/2007","30/3/2007","5/4/2007"};
    vector<double> calendarCumuls{0.0, 112.33,157.97, 280.57};
    double cumulTTFromZC_65 = 0;
    double der = 300.0;
    double slopeTSFLN = 0.9;
    double intTSFLN = 2.6;
    double finalLeafNumber=8.797582013199484;
    string currentZadokStage="MainShootPlus1Tiller";
    string currentdate = "9/4/2007";
    int hasZadokStageChanged=0;
    cout<< "---------------------------- test RegisterZadok----------------------"<<endl;

    RegisterZadok res = Calculate_RegisterZadok(cumulTT,phase,leafNumber, calendarMoments,calendarDates,calendarCumuls,cumulTTFromZC_65,currentdate,der,slopeTSFLN, intTSFLN,finalLeafNumber,currentZadokStage,hasZadokStageChanged);
    calendarMoments = res.calendarMoments;
    calendarDates = res.calendarDates;
    calendarCumuls = res.calendarCumuls;
    hasZadokStageChanged = res.hasZadokStageChanged;
    currentZadokStage = res.currentZadokStage;

    cout<<"calendarMoments    calendarCumuls      calendarDates"<<endl;
    for (int i=0; i<calendarMoments.size(); i++)
    {
        cout<<calendarMoments[i]<<"   "<<calendarCumuls[i]<<"  "<<calendarDates[i]<<endl;
    }
    cout<<"hasZadokStageChanged  "<<hasZadokStageChanged<<endl;
    cout<<"currentZadokStage  "<<currentZadokStage<<endl;
}

void test_UpdatePhase()
{
    double cumulTT = 354.582294511779, leafNumber =  4.620511621863958,
           cumulTTFromZC_39 = 0, gai = 0.3255196285135,
           grainCumulTT = 0, dayLength = 12.7433275303389, vernaprog =  1.0532526829571554,
           minFinalNumber = 6.879410413987549, fixPhyll = 91.2,Dse = 105,pFLLAnth = 2.22,
           dcd = 100,Dgf = 450, degfm = 0, maxDL = 15,sLDL = 0.85, pHEADANTH = 1,
           p = 120,phase = 1,cumulTTFromZC_91 = 0, phyllochron = 91.2, finalLeafNumber;

    int IsVernalizable = 1,hasLastPrimordiumAppeared = 0,switchMaize = 0, isMomentRegistredZC_39 = 0;
    bool ignoreGrainMaturation = false;
    string choosePhyllUse = "Default";

    cout<< "---------------------------- test updatePhase----------------------"<<endl;

    UpdatePhase res= Calculate_UpdatePhase(cumulTT, leafNumber, cumulTTFromZC_39,isMomentRegistredZC_39, gai, grainCumulTT, dayLength, vernaprog,
                                           minFinalNumber, fixPhyll,IsVernalizable, Dse, pFLLAnth,
                                           dcd, Dgf, degfm, maxDL, sLDL, ignoreGrainMaturation,
                                           pHEADANTH,switchMaize,choosePhyllUse, p, phase,
                                           cumulTTFromZC_91, phyllochron,hasLastPrimordiumAppeared);

    finalLeafNumber = res.finalLeafNumber;
    hasLastPrimordiumAppeared = res.hasLastPrimordiumAppeared;
    phase = res.phase;
    cout<<"finalLeafNumber  "<<finalLeafNumber<<endl;
    cout<<"hasLastPrimordiumAppeared  "<<hasLastPrimordiumAppeared<<endl;
    cout<<"phase  "<<phase<<endl;
}


void test_updateLeafFlag()
{

    double cumulTT = 741.510096671757,  phase = 3, leafNumber = 8.919453833361189, finalLeafNumber = 8.797582013199484;
    int hasFlagLeafLiguleAppeared = 0;
    string currentdate = "29/4/2007";
    vector<string> calendarMoments{"Sowing", "Emergence", "EndVernalisation", "MainShootPlus1Tiller", "FloralInitiation", "MainShootPlus2Tiller", "TerminalSpikelet", "PseudoStemErection", "MainShootPlus3Tiller", "1stNodeDetectable", "2ndNodeDetectable", "FlagLeafJustVisible"};
    vector<string>calendarDates{"21/3/2007", "27/3/2007", "30/3/2007", "5/4/2007", "9/4/2007", "10/4/2007", "11/4/2007", "12/4/2007", "14/4/2007", "15/4/2007", "19/4/2007", "24/4/2007"};
    vector<double> calendarCumuls{0.0, 112.330110409888, 157.969706915664, 280.570678654207, 354.582294511779, 378.453152853726, 402.042720581446, 424.98704708663, 467.23305195298, 487.544313430698, 560.665248444002, 646.389617338974};


    cout<< "---------------------------- test updateLeafFlag----------------------"<<endl;

    UpdateLeafFlag res = Calculate_UpdateLeafFlag(cumulTT,leafNumber,calendarMoments, calendarDates, calendarCumuls, currentdate, finalLeafNumber, hasFlagLeafLiguleAppeared, phase);
    calendarMoments = res.calendarMoments;
    calendarCumuls = res.calendarCumuls;
    calendarDates =  res.calendarDates;
    hasFlagLeafLiguleAppeared = res.hasFlagLeafLiguleAppeared;

    cout<<"calendarMoments    calendarCumuls      calendarDates"<<endl;
    for (int i=0; i<calendarMoments.size(); i++)
    {
        cout<<calendarMoments[i]<<"   "<<calendarCumuls[i]<<"  "<<calendarDates[i]<<endl;
    }
    cout<<"hasFlagLeafLiguleAppeared "<<hasFlagLeafLiguleAppeared<<endl;
}


void test_updateCalendar()
{
    string currentdate = "27/3/2007";

    double cumulTT = 112.330110409888,  phase = 1;
    vector<double>calendarCumuls{0.0};
    vector<string>calendarDates{"21/03/2007"};
    vector<string>calendarMoments{"Sowing"};

    cout<< "---------------------------- test updateCalendar----------------------"<<endl;

    UpdateCalendar res = Calculate_UpdateCalendar( cumulTT,calendarMoments, calendarDates,calendarCumuls,currentdate, phase);
    calendarMoments = res.calendarMoments;
    calendarCumuls = res.calendarCumuls;
    calendarDates =  res.calendarDates;

    cout<<"calendarMoments    calendarCumuls      calendarDates"<<endl;
    for (int i=0; i<calendarMoments.size(); i++)
    {
        cout<<calendarMoments[i]<<"   "<<calendarCumuls[i]<<"  "<<calendarDates[i]<<endl;
    }

}

void test_ShootNumber()
{
    int sowingDensity=288, tillerNumber= 1;
    double leafNumber= 3.34348137255,TargetFertileShoot=600.0, canopyShootNumber=288.0, averageShootNumberPerPlant;

    vector<int>leafTillerNumberArray{1,1,1};
    vector<double>tilleringProfile{288.0};

    cout<< "---------------------------- test shootNumber----------------------"<<endl;
    ShootNumber res = Calculate_ShootNumber(canopyShootNumber,leafNumber,sowingDensity,
                       TargetFertileShoot, tilleringProfile,leafTillerNumberArray, tillerNumber);
    averageShootNumberPerPlant = res.averageShootNumberPerPlant;
    canopyShootNumber = res.canopyShootNumber;
    tillerNumber = res.tillerNumber;
    leafTillerNumberArray = res.leafTillerNumberArray;
    tilleringProfile = res.tilleringProfile;
    cout<<"leafTillerNumberArray"<<endl;
    for (int i=0; i<leafTillerNumberArray.size(); i++)
    {
        cout<<leafTillerNumberArray[i]<<endl;
    }
    cout<<"tilleringProfile"<<endl;
    for (int i=0; i<tilleringProfile.size(); i++)
    {
        cout<<tilleringProfile[i]<<endl;
    }
     cout<<"averageShootNumberPerPlant "<<averageShootNumberPerPlant<<endl;
     cout<<"canopyShootNumber "<<canopyShootNumber<<endl;
     cout<<"tillerNumber "<<tillerNumber<<endl;


}

void test_VernalizationProgress()
{
    double dayLength = 12.3037621834005,deltaTT = 20.3429985011972,  cumulTT =  112.330110409888,leafNumber = 0,minTvern = 0.0,
        intTvern =  11.0, vAI =  0.015,vBEE = 0.01, minDL = 8.0,maxDL = 15.0,
        maxTvern =  23.0,pNini = 4.0, aMXLFNO = 24.0, vernaprog =  0.5517254187376879,minFinalNumber = 5.5;

    int isVernalizable =1;
    string currentdate = "27/3/2007";
    vector<string> calendarMoments{"Sowing"};
    vector<string> calendarDates{"21/03/2007"};
    vector<double>calendarCumuls{0.0};

    cout<< "---------------------------- test vernalizationProgress---------------------"<<endl;
    VernalizationProgress res = Calculate_VernalizationProgress(dayLength,deltaTT, cumulTT, leafNumber,calendarMoments,calendarDates,calendarCumuls,minTvern,intTvern,vAI, vBEE, minDL,maxDL,maxTvern, pNini, aMXLFNO, vernaprog, currentdate, isVernalizable, minFinalNumber);
    vernaprog = res.vernaprog;
    minFinalNumber = res.minFinalNumber;

    calendarMoments = res.calendarMoments;
    calendarCumuls = res.calendarCumuls;
    calendarDates =  res.calendarDates;

    cout<<"calendarMoments    calendarCumuls      calendarDates"<<endl;
    for (int i=0; i<calendarMoments.size(); i++)
    {
        cout<<calendarMoments[i]<<"   "<<calendarCumuls[i]<<"  "<<calendarDates[i]<<endl;
    }

    cout<<"vernaprog "<<vernaprog<<endl;
    cout<<"minFinalNumber "<<minFinalNumber<<endl;



}

void test_PhyllochronModule()
{
    double fixPhyll = 91.2,leafNumber = 0,lincr = 8,ldecr = 3,pdecr = 0.4,pincr = 1.25, ptq = 0,gai = 0.279874189539498,pastMaxAI = 0,
        kl = 0.45, aPTQ = 0.842934,phylPTQ1 = 20, p = 120, phyllochron;
    string choosePhyllUse = "Default";

    cout<< "---------------------------- test PhyllochronModule----------------------"<<endl;
    Phyllochron res = Calculate_Phyllochron(fixPhyll,leafNumber,lincr,ldecr,pdecr,pincr, ptq, gai, pastMaxAI,kl, aPTQ, phylPTQ1, p,choosePhyllUse);
    pastMaxAI = res.pastMaxAI;
    phyllochron = res.phyllochron;
    cout<<"pastMaxAI "<<pastMaxAI<<endl;
    cout<<"phyllochron "<<phyllochron<<endl;
}

void test_PhylSowingDateCorrection()
{
    int sowingDay = 80,sDws = 90, sDsa_sh = 151, sDsa_nh = 200;
    double latitude = 33.069,  rp = 0.003, p = 120, fixPhyll;

    cout<< "---------------------------- test PhylSowingDateCorrection----------------------"<<endl;
    PhylSowingDateCorrection res = Calculate_PhylSowingDateCorrection(sowingDay,latitude,sDsa_sh,rp,sDws,sDsa_nh,p);
    fixPhyll = res.fixPhyll;
    cout<<"fixPhyll "<<fixPhyll<<endl;

}

int main()
{
    test_CumulFROM();
    test_IsMomentRegistredZC_39();
    test_LeafNumberModule();
    test_PhyllochronModule();
    test_PhylSowingDateCorrection();
    test_RegisterZadok();
    test_UpdatePhase();
    test_updateLeafFlag();
    test_updateCalendar();
    test_ShootNumber();
    test_VernalizationProgress();

    return 0;
}
