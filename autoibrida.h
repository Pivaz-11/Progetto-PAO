#ifndef AUTOIBRIDA_H
#define AUTOIBRIDA_H
#include "mezzoelettrico.h"
#include "mezzocombustione.h"


class AutoIbrida : public MezzoCombustione, public MezzoElettrico
{
private:
    static double kAutoIbrida;// costante moltiplicativa del valore della vendita di un'auto ibrida
public:
    AutoIbrida(std::string _idMezzo="", double _potenza=0, double _prezzo= 0.0, double _cilindrata=0, double _capacitaBatteria=0);
    virtual double getReward() const override; //ritorna il reward dato dal reward del mezzo a combustione+mezzoelettrico+prezzo
    virtual unsigned int getStar() const override;
    ~AutoIbrida();
};

#endif // AUTOIBRIDA_H
