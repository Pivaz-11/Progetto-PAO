#include "auto.h"

Auto::Auto(std::string _idMezzo, double _potenza, double _prezzo,
             double _cilindrata) : Mezzo (_idMezzo,_potenza,_prezzo),
            MezzoCombustione (_idMezzo,_potenza,_prezzo,_cilindrata) {}

double Auto::kAuto=0.2;

double Auto::getReward() const{
    return (MezzoCombustione::getReward() + getPrezzo()*kAuto);
}

Auto::~Auto() {}
