#include "azienda.h"


void Azienda::aggiungiVendita(unsigned int _id, Mezzo* m){
    Lista<Dipendente*>::Iterator it = dipendenti.begin();
    while(it != dipendenti.end()){
        if((*it)->getId() == _id){
            (*it)->addVendita(m);
            return;
        }
        ++it;
    }
}
Azienda::Azienda(){
    // QUESTO E' UN DATABASE DI ESEMPIO:
    dipendenti.insertBack(new Dipendente(1, 300, 10, 3));
    dipendenti.insertBack(new Dipendente(2, 3750, 50, 12));
    dipendenti.insertBack(new Dipendente(3, 1200, 14, 4));
    dipendenti.insertBack(new Dipendente(5, 656, 18, 6));
    dipendenti.insertBack(new Dipendente(9, 300, 10, 3));
    dipendenti.insertBack(new Dipendente(10, 3750, 50, 12));
    dipendenti.insertBack(new Dipendente(22, 1200, 14, 4));
    dipendenti.insertBack(new Dipendente(34, 656, 18, 6));
    dipendenti.insertBack(new Dipendente(35, 1200, 14, 4));
    dipendenti.insertBack(new Dipendente(55, 656, 18, 6));
    dipendenti.insertBack(new Dipendente(56, 300, 10, 3));
    dipendenti.insertBack(new Dipendente(57, 3750, 50, 12));
    dipendenti.insertBack(new Dipendente(58, 1200, 14, 4));
    dipendenti.insertBack(new Dipendente(59, 656, 18, 6));
    dipendenti.insertBack(new Dipendente(69, 300, 4, 1));
    dipendenti.insertBack(new Dipendente(99, 2350, 20, 5));
    dipendenti.insertBack(new Dipendente(70, 2350, 14, 3));
    aggiungiVendita(69, new Moto("blun7", 35, 7500, 500));
    aggiungiVendita(2, new AutoIbrida("sw1n6o", 97, 18000, 1400, 10));
}

void Azienda::salvaStipendi(){
    Lista<Dipendente*>::Iterator it = dipendenti.begin();
    while(it != dipendenti.end()){
        (*it)->assegnaReward();
        ++it;
    }
}

Azienda::~Azienda()
{
    Lista<Dipendente*>::Iterator it=dipendenti.begin();
    while(it != dipendenti.end()){
        delete (*it);
        ++it;
    }
}

void Azienda::azzeraStipendi()
{
    Lista<Dipendente*>::Iterator it=dipendenti.begin();
    while(it != dipendenti.end()){
        (*it)->azzeraStipendio();
        ++it;
    }
}

Lista<Dipendente *> Azienda::getDipendenti() const{ return dipendenti;}
