#ifndef _PhenologyState_
#define _PhenologyState_
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include<vector>
# include<string>
using namespace std;
class PhenologyState
{
    private:
        double ptq;
        string currentZadokStage;
        int hasFlagLeafLiguleAppeared;
        int hasZadokStageChanged;
        vector<double> listPARTTWindowForPTQ;
        int hasLastPrimordiumAppeared;
        vector<double> listTTShootWindowForPTQ;
        vector<double> listTTShootWindowForPTQ1;
        vector<string> calendarMoments;
        double canopyShootNumber;
        vector<string> calendarDates;
        vector<int> leafTillerNumberArray;
        double vernaprog;
        double phyllochron;
        double leafNumber;
        int numberTillerCohort;
        vector<double> tilleringProfile;
        double averageShootNumberPerPlant;
        double minFinalNumber;
        double finalLeafNumber;
        double phase;
        vector<double> listGAITTWindowForPTQ;
        vector<double> calendarCumuls;
        double gAImean;
        double pastMaxAI;
        int isMomentRegistredZC_39;
    public:
        PhenologyState();
        double getptq();
        void setptq(double _ptq);
        string getcurrentZadokStage();
        void setcurrentZadokStage(string _currentZadokStage);
        int gethasFlagLeafLiguleAppeared();
        void sethasFlagLeafLiguleAppeared(int _hasFlagLeafLiguleAppeared);
        int gethasZadokStageChanged();
        void sethasZadokStageChanged(int _hasZadokStageChanged);
        vector<double>& getlistPARTTWindowForPTQ();
        void setlistPARTTWindowForPTQ(vector<double>& _listPARTTWindowForPTQ);
        int gethasLastPrimordiumAppeared();
        void sethasLastPrimordiumAppeared(int _hasLastPrimordiumAppeared);
        vector<double>& getlistTTShootWindowForPTQ();
        void setlistTTShootWindowForPTQ(vector<double>& _listTTShootWindowForPTQ);
        vector<double>& getlistTTShootWindowForPTQ1();
        void setlistTTShootWindowForPTQ1(vector<double>& _listTTShootWindowForPTQ1);
        vector<string>& getcalendarMoments();
        void setcalendarMoments(vector<string>& _calendarMoments);
        double getcanopyShootNumber();
        void setcanopyShootNumber(double _canopyShootNumber);
        vector<string>& getcalendarDates();
        void setcalendarDates(vector<string>& _calendarDates);
        vector<int>& getleafTillerNumberArray();
        void setleafTillerNumberArray(vector<int>& _leafTillerNumberArray);
        double getvernaprog();
        void setvernaprog(double _vernaprog);
        double getphyllochron();
        void setphyllochron(double _phyllochron);
        double getleafNumber();
        void setleafNumber(double _leafNumber);
        int getnumberTillerCohort();
        void setnumberTillerCohort(int _numberTillerCohort);
        vector<double>& gettilleringProfile();
        void settilleringProfile(vector<double>& _tilleringProfile);
        double getaverageShootNumberPerPlant();
        void setaverageShootNumberPerPlant(double _averageShootNumberPerPlant);
        double getminFinalNumber();
        void setminFinalNumber(double _minFinalNumber);
        double getfinalLeafNumber();
        void setfinalLeafNumber(double _finalLeafNumber);
        double getphase();
        void setphase(double _phase);
        vector<double>& getlistGAITTWindowForPTQ();
        void setlistGAITTWindowForPTQ(vector<double>& _listGAITTWindowForPTQ);
        vector<double>& getcalendarCumuls();
        void setcalendarCumuls(vector<double>& _calendarCumuls);
        double getgAImean();
        void setgAImean(double _gAImean);
        double getpastMaxAI();
        void setpastMaxAI(double _pastMaxAI);
        int getisMomentRegistredZC_39();
        void setisMomentRegistredZC_39(int _isMomentRegistredZC_39);

};
#endif