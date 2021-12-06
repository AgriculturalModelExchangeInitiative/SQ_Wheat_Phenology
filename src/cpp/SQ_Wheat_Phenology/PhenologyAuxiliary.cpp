#include "PhenologyAuxiliary.h"

PhenologyAuxiliary::PhenologyAuxiliary() { }

string PhenologyAuxiliary::getcurrentdate() {return this-> currentdate; }
double PhenologyAuxiliary::getcumulTT() {return this-> cumulTT; }
double PhenologyAuxiliary::getdayLength() {return this-> dayLength; }
double PhenologyAuxiliary::getdeltaTT() {return this-> deltaTT; }
double PhenologyAuxiliary::getgAI() {return this-> gAI; }
double PhenologyAuxiliary::getpAR() {return this-> pAR; }
double PhenologyAuxiliary::getgrainCumulTT() {return this-> grainCumulTT; }
double PhenologyAuxiliary::getfixPhyll() {return this-> fixPhyll; }
double PhenologyAuxiliary::getcumulTTFromZC_39() {return this-> cumulTTFromZC_39; }
double PhenologyAuxiliary::getcumulTTFromZC_91() {return this-> cumulTTFromZC_91; }
double PhenologyAuxiliary::getcumulTTFromZC_65() {return this-> cumulTTFromZC_65; }

void PhenologyAuxiliary::setcurrentdate(string _currentdate) { this->currentdate = _currentdate; }
void PhenologyAuxiliary::setcumulTT(double _cumulTT) { this->cumulTT = _cumulTT; }
void PhenologyAuxiliary::setdayLength(double _dayLength) { this->dayLength = _dayLength; }
void PhenologyAuxiliary::setdeltaTT(double _deltaTT) { this->deltaTT = _deltaTT; }
void PhenologyAuxiliary::setgAI(double _gAI) { this->gAI = _gAI; }
void PhenologyAuxiliary::setpAR(double _pAR) { this->pAR = _pAR; }
void PhenologyAuxiliary::setgrainCumulTT(double _grainCumulTT) { this->grainCumulTT = _grainCumulTT; }
void PhenologyAuxiliary::setfixPhyll(double _fixPhyll) { this->fixPhyll = _fixPhyll; }
void PhenologyAuxiliary::setcumulTTFromZC_39(double _cumulTTFromZC_39) { this->cumulTTFromZC_39 = _cumulTTFromZC_39; }
void PhenologyAuxiliary::setcumulTTFromZC_91(double _cumulTTFromZC_91) { this->cumulTTFromZC_91 = _cumulTTFromZC_91; }
void PhenologyAuxiliary::setcumulTTFromZC_65(double _cumulTTFromZC_65) { this->cumulTTFromZC_65 = _cumulTTFromZC_65; }