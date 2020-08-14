#ifndef MEZZOCOMBUSTIONE_H
#define MEZZOCOMBUSTIONE_H
#include "mezzo.h"
class MezzoCombustione : virtual public Mezzo {
private:
    double cilindrata; // Cilindrata del un motore di un mezzo a combustione espressa in cm^3
    static double kPotenzaCombustione; // costante moltiplicativa del valore della vendita sulla base della potenza del mezzo a combustione
    static double kCilindrata; /* costante moltiplicativa del valore della vendita sulla base della cilindrata di un mezzo
                                        combustione*/
public:

    MezzoCombustione(std::string _idMezzo ="", double _potenza =0, double _prezzo=0.0, double _cilindrata=0);

    double getCilindrata() const;

    virtual double getReward() const override; // implementazione metodo virtuale
    virtual unsigned int getStar() const override; // implementazione metodo virtuale utile che sarà poi utilizzata da auto ed auto ibrida

};
#endif // MEZZOCOMBUSTIONE_H
