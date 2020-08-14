#ifndef MOTO_H
#define MOTO_H
#include "mezzocombustione.h"

class Moto : public MezzoCombustione {
private:
    static double kMoto; // costante moltiplicativa del valore della vendita di una moto
public:
    Moto(std::string _idMezzo="", double _potenza =0, double _prezzo = 0.0, double _cilindrata=0);

    virtual double getReward() const override; //ritorna il reward del mezzo a combustione + il prezzo dell'articolo moto
    virtual unsigned int getStar() const override; // implementazione specifica del metodo sulle prestazioni di una moto
    ~Moto();
};
#endif // MOTO_H
