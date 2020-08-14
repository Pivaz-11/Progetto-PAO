#ifndef MEZZOELETTRICO_H
#define MEZZOELETTRICO_H
#include "mezzo.h"

class MezzoElettrico : virtual public Mezzo{
private:
    double capacitaBatteria; //durata della batteria del motore elettrico espressa in kwh
    static double kPotenzaElettrico; //costante moltiplicativa del valore della vendita sulla base della potenza del mezzo elettrico
    static double kBatteria; //costante moltiplicativa del valore della vendita sulla base della potenza della batteria del motore elettrico
public:
    MezzoElettrico(std::string _idMezzo="", double _potenza =0, double _prezzo = 0.0, double _capacitaBatteria=0);

    double getCapacita() const;

    virtual double getReward() const override; // implementazione metodo virtuale
    virtual unsigned int getStar() const override; // implementazione metodo virtuale
};
#endif // MEZZOELETTRICO_H
