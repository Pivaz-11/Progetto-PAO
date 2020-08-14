#include "mezzo.h"

Mezzo::Mezzo(std::string _idMezzo, double _potenza, double _prezzo) : idMezzo(_idMezzo), potenza(_potenza<0?0:_potenza), prezzo(_prezzo<0?0:_prezzo) {}

std::string Mezzo::getIdMezzo() const { return idMezzo; }

double Mezzo::getPotenza() const { return potenza; }

double Mezzo::getPrezzo() const { return prezzo; }

Mezzo::~Mezzo() {}
