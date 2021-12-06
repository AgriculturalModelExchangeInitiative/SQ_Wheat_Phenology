#include "PhenologyState.h"
PhenologyState::PhenologyState() { }

double PhenologyState::getptq() {return this-> ptq; }
string PhenologyState::getcurrentZadokStage() {return this-> currentZadokStage; }
int PhenologyState::gethasFlagLeafLiguleAppeared() {return this-> hasFlagLeafLiguleAppeared; }
int PhenologyState::gethasZadokStageChanged() {return this-> hasZadokStageChanged; }
vector<double>& PhenologyState::getlistPARTTWindowForPTQ() {return this-> listPARTTWindowForPTQ; }
int PhenologyState::gethasLastPrimordiumAppeared() {return this-> hasLastPrimordiumAppeared; }
vector<double>& PhenologyState::getlistTTShootWindowForPTQ() {return this-> listTTShootWindowForPTQ; }
vector<double>& PhenologyState::getlistTTShootWindowForPTQ1() {return this-> listTTShootWindowForPTQ1; }
vector<string>& PhenologyState::getcalendarMoments() {return this-> calendarMoments; }
double PhenologyState::getcanopyShootNumber() {return this-> canopyShootNumber; }
vector<string>& PhenologyState::getcalendarDates() {return this-> calendarDates; }
vector<int>& PhenologyState::getleafTillerNumberArray() {return this-> leafTillerNumberArray; }
double PhenologyState::getvernaprog() {return this-> vernaprog; }
double PhenologyState::getphyllochron() {return this-> phyllochron; }
double PhenologyState::getleafNumber() {return this-> leafNumber; }
int PhenologyState::getnumberTillerCohort() {return this-> numberTillerCohort; }
vector<double>& PhenologyState::gettilleringProfile() {return this-> tilleringProfile; }
double PhenologyState::getaverageShootNumberPerPlant() {return this-> averageShootNumberPerPlant; }
double PhenologyState::getminFinalNumber() {return this-> minFinalNumber; }
double PhenologyState::getfinalLeafNumber() {return this-> finalLeafNumber; }
double PhenologyState::getphase() {return this-> phase; }
vector<double>& PhenologyState::getlistGAITTWindowForPTQ() {return this-> listGAITTWindowForPTQ; }
vector<double>& PhenologyState::getcalendarCumuls() {return this-> calendarCumuls; }
double PhenologyState::getgAImean() {return this-> gAImean; }
double PhenologyState::getpastMaxAI() {return this-> pastMaxAI; }
int PhenologyState::getisMomentRegistredZC_39() {return this-> isMomentRegistredZC_39; }

void PhenologyState::setptq(double _ptq) { this->ptq = _ptq; }
void PhenologyState::setcurrentZadokStage(string _currentZadokStage) { this->currentZadokStage = _currentZadokStage; }
void PhenologyState::sethasFlagLeafLiguleAppeared(int _hasFlagLeafLiguleAppeared) { this->hasFlagLeafLiguleAppeared = _hasFlagLeafLiguleAppeared; }
void PhenologyState::sethasZadokStageChanged(int _hasZadokStageChanged) { this->hasZadokStageChanged = _hasZadokStageChanged; }
void PhenologyState::setlistPARTTWindowForPTQ(vector<double> _listPARTTWindowForPTQ){
    this->listPARTTWindowForPTQ = _listPARTTWindowForPTQ;
}
void PhenologyState::sethasLastPrimordiumAppeared(int _hasLastPrimordiumAppeared) { this->hasLastPrimordiumAppeared = _hasLastPrimordiumAppeared; }
void PhenologyState::setlistTTShootWindowForPTQ(vector<double> _listTTShootWindowForPTQ){
    this->listTTShootWindowForPTQ = _listTTShootWindowForPTQ;
}
void PhenologyState::setlistTTShootWindowForPTQ1(vector<double> _listTTShootWindowForPTQ1){
    this->listTTShootWindowForPTQ1 = _listTTShootWindowForPTQ1;
}
void PhenologyState::setcalendarMoments(vector<string> _calendarMoments){
    this->calendarMoments = _calendarMoments;
}
void PhenologyState::setcanopyShootNumber(double _canopyShootNumber) { this->canopyShootNumber = _canopyShootNumber; }
void PhenologyState::setcalendarDates(vector<string> _calendarDates){
    this->calendarDates = _calendarDates;
}
void PhenologyState::setleafTillerNumberArray(vector<int> _leafTillerNumberArray){
    this->leafTillerNumberArray = _leafTillerNumberArray;
}
void PhenologyState::setvernaprog(double _vernaprog) { this->vernaprog = _vernaprog; }
void PhenologyState::setphyllochron(double _phyllochron) { this->phyllochron = _phyllochron; }
void PhenologyState::setleafNumber(double _leafNumber) { this->leafNumber = _leafNumber; }
void PhenologyState::setnumberTillerCohort(int _numberTillerCohort) { this->numberTillerCohort = _numberTillerCohort; }
void PhenologyState::settilleringProfile(vector<double> _tilleringProfile){
    this->tilleringProfile = _tilleringProfile;
}
void PhenologyState::setaverageShootNumberPerPlant(double _averageShootNumberPerPlant) { this->averageShootNumberPerPlant = _averageShootNumberPerPlant; }
void PhenologyState::setminFinalNumber(double _minFinalNumber) { this->minFinalNumber = _minFinalNumber; }
void PhenologyState::setfinalLeafNumber(double _finalLeafNumber) { this->finalLeafNumber = _finalLeafNumber; }
void PhenologyState::setphase(double _phase) { this->phase = _phase; }
void PhenologyState::setlistGAITTWindowForPTQ(vector<double> _listGAITTWindowForPTQ){
    this->listGAITTWindowForPTQ = _listGAITTWindowForPTQ;
}
void PhenologyState::setcalendarCumuls(vector<double> _calendarCumuls){
    this->calendarCumuls = _calendarCumuls;
}
void PhenologyState::setgAImean(double _gAImean) { this->gAImean = _gAImean; }
void PhenologyState::setpastMaxAI(double _pastMaxAI) { this->pastMaxAI = _pastMaxAI; }
void PhenologyState::setisMomentRegistredZC_39(int _isMomentRegistredZC_39) { this->isMomentRegistredZC_39 = _isMomentRegistredZC_39; }