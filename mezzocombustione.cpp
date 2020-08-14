#include "mezzocombustione.h"


MezzoCombustione::MezzoCombustione(std::string _idMezzo, double _potenza, double _prezzo, double _cilindrata) : Mezzo(_idMezzo,_potenza,_prezzo), cilindrata(_cilindrata<0?0:_cilindrata) {}

double MezzoCombustione::kPotenzaCombustione=0.2;

double MezzoCombustione::kCilindrata=0.2;

double MezzoCombustione::getCilindrata() const{ return cilindrata; }

double MezzoCombustione::getReward() const{
    return (getCilindrata()*kCilindrata)+(getPotenza()*kPotenzaCombustione);
}
unsigned int MezzoCombustione::getStar() const{
    if(cilindrata==0 || getPotenza() == 0) return 0;
    double a=cilindrata/getPotenza();
    if(a>=25){
        return 1;
    }
    else if(a<25 && a>=20){
        return 2;
    }
    else if(a<20 && a>=15){
        return 3;
    }
    else if(a<15 && a>=10){
        return 4;
    }
    else
        return 5;

}
