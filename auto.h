#ifndef AUTO_H
#define AUTO_H
#include "mezzocombustione.h"

class Auto : public MezzoCombustione {
private:
    static double kAuto; //costante moltiplicativa del valore della vendita di un'auto a combustione
public:

    Auto(std::string _idMezzo=0, double _potenza=0, double _prezzo=0.0, double _cilindrata =0);

    virtual double getReward() const override; //ritorna il reward del mezzo a combustione + il prezzo dell'articolo auto

    ~Auto();
};
#endif // AUTO_H
