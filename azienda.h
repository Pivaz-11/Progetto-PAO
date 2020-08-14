#ifndef AZIENDA_H
#define AZIENDA_H
#include "dipendente.h"
#include "moto.h"
#include "autoibrida.h"

class Azienda {
private:
    Lista<Dipendente*> dipendenti;

public:
    Azienda();
    void aggiungiVendita(unsigned int _id, Mezzo* m); //aggiunge al dipendente con id == _id il mezzo m venduto
    void salvaStipendi(); //salva gli stipendi dei dipendenti rimuovendo le nuove vendite
    ~Azienda();
    void azzeraStipendi();// resetta gli attributi dei dipendenti dell'azienda
    Lista<Dipendente*> getDipendenti() const;
};
#endif //AZIENDA_H
