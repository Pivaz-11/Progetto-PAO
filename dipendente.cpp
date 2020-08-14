#include "dipendente.h"

unsigned int Dipendente::getSumRating() const
{
    return sumRating;
}

unsigned int Dipendente::getNvendite() const
{
    return nvendite;
}

Dipendente::Dipendente(unsigned int _id, unsigned int _stipendio, unsigned int _sumRating, unsigned int _nvendite) :id(_id), stipendio(_stipendio), sumRating(_sumRating), nvendite(_nvendite){}


unsigned int Dipendente::getId() const {return id;}

unsigned int Dipendente::getStipendio() const {return stipendio; }

Lista<Mezzo*> Dipendente::getLista() const { return vendite;}

void Dipendente::addVendita(Mezzo* m){ vendite.insertBack(m); }

void Dipendente::rimuoviVendite() {
    for(Lista<Mezzo*>::Iterator i = vendite.begin(); i!=vendite.end(); ++i){
        delete (*i);
    }
    vendite.flush();
}

double Dipendente::getReward() const {
    double totale=0;
    for(Lista<Mezzo*>::Iterator i = vendite.begin(); i!=vendite.end(); ++i){
        totale+=(*i)->getReward();
    }
    return totale;
}
void Dipendente::assegnaRating() {
    for(Lista<Mezzo*>::Iterator i = vendite.begin(); i!=vendite.end(); ++i){
        sumRating+=(*i)->getStar();
        nvendite++;
    }
}
void Dipendente::assegnaReward()
{
    stipendio += getReward();
    assegnaRating();
    rimuoviVendite();
}

Dipendente::~Dipendente() {
    Lista<Mezzo*>::Iterator it=vendite.begin();
    while(it != vendite.end()){
        delete (*it);
        ++it;
    }
}

void Dipendente::azzeraStipendio(){
    stipendio=0;
    sumRating=0;
    nvendite=0;

}
