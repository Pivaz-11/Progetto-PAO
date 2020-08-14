#include "monopattino.h"

Monopattino::Monopattino(std::string _idMezzo, double _potenza, double _prezzo,
            double _capacitaBatteria) :Mezzo (_idMezzo,_potenza,_prezzo), MezzoElettrico(_idMezzo,_potenza,_prezzo,_capacitaBatteria) {}

double Monopattino::kMonopattino=0.35;

double Monopattino::getReward() const {
    return (MezzoElettrico::getReward() + getPrezzo()*kMonopattino);
}

unsigned int Monopattino::getStar() const{
    if(getPotenza() == 0|| getCapacita() == 0) return 0;
    double a=getPotenza()*getCapacita()/2;
    if(a<=1){
        return 1;
    }
    else if(a>1 && a<=3){
        return 2;
    }
    else if(a>3 && a<=4.5){
        return 3;
    }
    else if(a>4.5 && a<=7){
        return 4;
    } else
        return 5;

}
Monopattino::~Monopattino() {}
