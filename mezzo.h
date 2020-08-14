#ifndef MEZZO_H
#define MEZZO_H
#include<iostream>
#include<string>

class Mezzo { //classe base astratta con metodo getReward() const virtuale puro;
private:
    std::string idMezzo; // Identificativo del mezzo
    double potenza; // Potenza del mezzo espressa in CV
    double prezzo; // Prezzo di mercato del mezzo
public:

    Mezzo(std::string _idMezzo ="", double _potenza =0, double _prezzo =0.0);

    std::string getIdMezzo () const;

    double getPotenza() const;

    double getPrezzo() const;

    virtual double getReward() const =0; /* metodo virtuale che restituirà
                                            il bonus ricavato dalla vendita di
                                            un particolare mezzo */
    virtual unsigned int getStar() const =0; /*metodo virtuale che restituità un intero corrispondente alla
                                      valutazione di un particolare mezzo
                                      sulla base delle prestazioni offerte */
    virtual ~Mezzo() =0; //distruttore virtuale puro

} ;

#endif // MEZZO_H
