#include "moto.h"

Moto::Moto(std::string _idMezzo, double _potenza, double _prezzo,
             double _cilindrata) :Mezzo (_idMezzo,_potenza,_prezzo), MezzoCombustione (_idMezzo,_potenza,_prezzo,_cilindrata) {}

double Moto::kMoto=0.4;

double Moto::getReward() const {
        return (MezzoCombustione::getReward() + getPrezzo()*kMoto);
}

unsigned int Moto::getStar() const{
    if(getCilindrata() ==0 || getPotenza() == 0) return 0;
    double a=getCilindrata()/getPotenza();
    if(a>=20){
        return 1;
    }
    else if(a<20 && a>=15){
        return 2;
    }
    else if(a<15 && a>=10){
        return 3;
    }
    else if(a<10 && a>=5){
        return 4;
    }
    else
        return 5;

}
Moto::~Moto() {}
