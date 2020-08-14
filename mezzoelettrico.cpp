#include "mezzoelettrico.h"

MezzoElettrico::MezzoElettrico(std::string _idMezzo, double _potenza, double _prezzo,
            double _capacitaBatteria) : Mezzo(_idMezzo,_potenza,_prezzo), capacitaBatteria(_capacitaBatteria<0?0:_capacitaBatteria) {}

double MezzoElettrico::kBatteria=0.1;

double MezzoElettrico::kPotenzaElettrico=0.3;

double MezzoElettrico::getCapacita() const{ return capacitaBatteria; }

double MezzoElettrico::getReward() const{
    return ((getPotenza()*kPotenzaElettrico)+(getCapacita()*kBatteria));
}
unsigned int MezzoElettrico::getStar() const{
    if(getPrezzo() == 0 || capacitaBatteria == 0) return 0;
    double a=(getPotenza()/10)*(capacitaBatteria/10);
    if(a<=30){
        return 1;
    }
    else if(a>30 && a<=60){
        return 2;
    }
    else if(a>60 && a<=100){
        return 3;
    }
    else if(a>100 && a<=150){
        return 4;
    } else
        return 5;

}
