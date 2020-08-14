#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include "mezzo.h"
#include "lista.h"

class Dipendente {
private:
    unsigned int id;
    Lista<Mezzo*> vendite;
    unsigned int stipendio;
    unsigned int sumRating;
    unsigned int nvendite;

public:

    Dipendente(unsigned int _id=0, unsigned int _stipendio =0, unsigned int _sumRating=0, unsigned int _nvendite=0);

    unsigned int getId() const;
    unsigned int getStipendio() const;
    unsigned int getSumRating() const;
    unsigned int getNvendite() const;


    Lista<Mezzo*> getLista() const;

    void addVendita(Mezzo*);

    void rimuoviVendite(); //azzera la lista vendite

    double getReward() const; /*metodo che ritorna lo stipendio accumulato in base alle
                                                        vendite effettuate da un dipendente */ 

    void assegnaRating(); //somma a sumRating i rating dei mezzi venduti, e aggiorna nvendite

    void assegnaReward(); //aggiunge allo stipendio il reward delle vendite e svuota la lista delle vendite, inoltre chiama assegnaRating

    void azzeraStipendio(); //resetta gli attributi di Dipendente stipendio rating ed nvendite

    ~Dipendente();

};

#endif //DIPENDENTE_H
