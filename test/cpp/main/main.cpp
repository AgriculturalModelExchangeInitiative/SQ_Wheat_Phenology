#include <iostream>
#include <vector>
#include "CumulFROM.h"
#include<math.h>
#include<time.h>
#include "Is_FlagLeafLiguleJustVisible_Registred.h"
#include "LeafNumberModule.h"
#include "RegisterZadok.h"

using namespace std;

void test_CumulFROM()
{
    vector<string> calendarMoments {"Sowing", "Emergence", "FloralInitiation", "FlagLeafLiguleJustVisible", "Heading", "Anthesis"};
    vector<double> calendarCumuls {0.0, 112.330110409888, 354.582294511779, 741.510096671757, 853.999637026622, 954.59002776961};
    double cumulTT = 972.970888983105;
    int SwitchMaize = 0;
    double cumulTTFromZC_39 ;
    double cumulTTFromZC_65 ;
    double cumulTTFromZC_91;
    cumulTTFromZC_39 = calculate_Cumulfrom(cumulTT, calendarMoments, calendarCumuls,SwitchMaize ).cumulTTFromZC_39;
    cumulTTFromZC_65 = calculate_Cumulfrom(cumulTT, calendarMoments, calendarCumuls,SwitchMaize ).cumulTTFromZC_65;
    cumulTTFromZC_91 = calculate_Cumulfrom(cumulTT, calendarMoments, calendarCumuls,SwitchMaize ).cumulTTFromZC_91;

    cout <<"cumulTTFromZC_39     "<<cumulTTFromZC_39<< endl;
    cout <<"cumulTTFromZC_65     "<<cumulTTFromZC_65<< endl;
    cout <<"cumulTTFromZC_91     "<<cumulTTFromZC_91<< endl;
    cout<<"cumulTTFromZC_39_est != cumulTTFromZC_39_calc??  "<< bool((round(cumulTTFromZC_39 * pow(10, 2))) / pow(10, 2)-231.46 < 0.01) <<endl ;
    cout<<"cumulTTFromZC_65_est != cumulTTFromZC_65_calc??  "<< bool((round(cumulTTFromZC_65 * pow(10, 2))) / pow(10, 2)-18.38 < 0.01) <<endl ;
    cout<<"cumulTTFromZC_91_est != cumulTTFromZC_91_calc??  "<< bool((round(cumulTTFromZC_91 * pow(10, 2))) / pow(10, 2)-0 < 0.01) <<endl ;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

}

void test_IsFlagLeafLiguleJustVisible_Registred()
{
    vector<string> calendarMoments{"Sowing", "Emergence", "FloralInitiation", "FlagLeafLiguleJustVisible", "Heading", "Anthesis"};
    int isMomentRegistredZC_39;
    isMomentRegistredZC_39 = calculate_IsMomentRegistredZC_39(calendarMoments).isMomentRegistredZC_39;
    cout <<"IsmomentRegistredZC_39    "<<isMomentRegistredZC_39<< endl;

    cout<<"isMomentRegistredZC_39_est != isMomentRegistredZC_39_calc??  "<< bool(isMomentRegistredZC_39-1 == 0)<<endl ;
    cout<<"----------------------------------------------------------------------------------------"<<endl;


}
void test_LeafNumberModule()
{
  double DeltaTT = 23.5895677277199;
  double phyllochron = 91.2;
  int HasFlagLeafLiguleAppeared = 0 ;
  int SwitchMaize = 0;
  double atip = 10;
  double Leaf_tip_emerg = 10 ;
  double k_bl = 1.412 ;
  double Nlim = 6.617;
  double leafNumber = 5.147163833893262;
  double cumulTTPhenoMaizeAtEmergence = 300;
  double cumulTT = 402.042720581446;
  double phase =3 ;
  double Ntip;
  leafNumber = calculate_LeafNumber(DeltaTT,phyllochron, HasFlagLeafLiguleAppeared, SwitchMaize, atip, Leaf_tip_emerg, k_bl, Nlim, leafNumber, cumulTTPhenoMaizeAtEmergence, cumulTT, phase).leafNumber;
  Ntip = calculate_LeafNumber(DeltaTT,phyllochron, HasFlagLeafLiguleAppeared, SwitchMaize, atip, Leaf_tip_emerg, k_bl, Nlim, leafNumber, cumulTTPhenoMaizeAtEmergence, cumulTT, phase).Ntip;
  cout <<"leafNumber    "<<leafNumber<< endl;
  cout <<"Ntip    "<<Ntip<< endl;

  cout<<"leafNumber_est != leafNumber_calc??  "<< bool((round(leafNumber * pow(10, 2))) / pow(10, 2)-5.41 < pow(10, 2)) <<endl ;
  cout<<"Ntip _est != Ntip _calc??  "<< bool((round(Ntip  * pow(10, 2))) / pow(10, 2)-0 < pow(10, 2)) <<endl ;
  cout<<"----------------------------------------------------------------------------------------"<<endl;

}


int main()
{
    test_CumulFROM();
    test_IsFlagLeafLiguleJustVisible_Registred();
    test_LeafNumberModule();

    return 0;
}
