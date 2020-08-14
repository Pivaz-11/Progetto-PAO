#ifndef MONOPATTINO_H
#define MONOPATTINO_H
#include "mezzoelettrico.h"

class Monopattino : public MezzoElettrico{
private:
    static double kMonopattino;//costante moltiplicativa del valore della vendita di un monopattino elettrico
public:
    Monopattino(std::string _idMezzo ="", double _potenza =0, double _prezzo = 0.0, double _capacitaBatteria =0);

    virtual double getReward() const override;//ritorna il reward del mezzo a combustione + il prezzo dell'articolo monopattino
    virtual unsigned int getStar() const override; // implementazione specifica del metodo sulle prestazioni di un monopattino elettrico
    ~Monopattino();
};
#endif // MONOPATTINO_H
