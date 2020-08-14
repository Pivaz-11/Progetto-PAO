#ifndef INSERISCIVENDITA_H
#define INSERISCIVENDITA_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QStyle>
#include <QToolBar>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QSpacerItem>
#include <QPushButton>
#include <QMessageBox>
#include "azienda.h"
#include "auto.h"
#include "moto.h"
#include "autoibrida.h"
#include "monopattino.h"
#include "mezzo.h"


class InserisciVendita : public QMainWindow
{
    Q_OBJECT
private:
    Azienda* az;
    //nomi delle calssi dei mezzi
    static QString AUTO;
    static QString MOTO;
    static QString AUTO_IBRIDA;
    static QString MONOPATTINO;

    //riferimenti alle cose nella UI, per prelevarne i dati
    QComboBox *idDipendente;
    QLineEdit *idMezzo;
    QString tipoMezzo; //Aggiornata al cambio valore con il signal
    QDoubleSpinBox *cilindrata;
    QDoubleSpinBox *batteria;
    QDoubleSpinBox *potenza;
    QDoubleSpinBox *prezzo;
    QVBoxLayout *layout62;
    QWidget *stelline;

    std::vector<QString> getIdDipendenti() const; //ritorn un vettore con tutti gli id dei dipendenti ordinato in modo crescente
    void popolaComboDipendenti(QComboBox *comboBox) const;
    static void impostaFont(const std::vector<QLabel*>& labels);
    static QHBoxLayout *layoutStelline(int lights =0);
    static QWidget* creaWidgetStelline(int lights = 0);
    Mezzo* creaMezzo() const; //crea il mezzo sulla base di quell oche l'utente ha selezionato e lo ritorna
    void displayAd() const; //mostra l'avviso di avvenuto salvataggio
    void displayAdWrong() const;//mostra l'avviso di NON avvenuto salvataggio
    void resettaCampi(); //fa il reset dei campi di immissione

public:
    explicit InserisciVendita(Azienda* a, QWidget *parent = nullptr);

signals:
    void goToHomeSignal(); //premuto il pulsante back
    void inseritaNuovaVenditaSignal();
private slots:
    void salvaPressed(); //cliccato il pulsante salva
    void tipoMezzoChanged(const QString &text); //abilita e disabilita cilindrata e batteria a seconda di che mezzo è attivo
    void aggiornaStelline();
};

#endif // INSERISCIVENDITA_H
