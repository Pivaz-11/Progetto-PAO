#include "autoibrida.h"

AutoIbrida::AutoIbrida(std::string _idMezzo, double _potenza, double _prezzo,
                       double _cilindrata, double _capacitaBatteria): Mezzo (_idMezzo,_potenza,_prezzo),
                       MezzoCombustione(_idMezzo, _potenza, _prezzo, _cilindrata),
                       MezzoElettrico(_idMezzo, _potenza, _prezzo, _capacitaBatteria){}

double AutoIbrida::kAutoIbrida=0.5;

double AutoIbrida::getReward() const{
    return (MezzoElettrico::getReward() + MezzoCombustione::getReward() + getPrezzo()*kAutoIbrida);
}
unsigned int AutoIbrida::getStar() const{
    return (MezzoCombustione::getStar()+MezzoElettrico::getStar())/2;
}

AutoIbrida::~AutoIbrida() {}
