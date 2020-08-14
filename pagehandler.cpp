#include "pagehandler.h"

void PageHandler::mostraHomeSlot(){stackedWidget->setCurrentIndex(0);}

void PageHandler::mostraInserisciVenditaSlot(){stackedWidget->setCurrentIndex(1);}

void PageHandler::mostraCalcolaStipendiSlot(){stackedWidget->setCurrentIndex(2);}

void PageHandler::mostraMostraVenditeSlot(){stackedWidget->setCurrentIndex(3);}

PageHandler::PageHandler(QWidget *parent)
    : QWidget(parent), stackedWidget(new QStackedWidget()), az(Azienda())
{
    //gestori base
        QVBoxLayout *layout= new QVBoxLayout();
        layout->setMargin(0); //sennò tutta l'applicazione era rientrata di qualche pixel
    //schermate
        QMainWindow *home = new Home();
        QMainWindow *inserisciVendita = new InserisciVendita(&az);
        QMainWindow *calcolaStipendi = new CalcolaStipendi(&az);
        QMainWindow *mostraVendite = new MostraVendite(&az);
    //connects
        //home
            connect(home, SIGNAL(aggiungiVenditaButtonSignal()), this, SLOT(mostraInserisciVenditaSlot()));
            connect(home, SIGNAL(calcolaStipendiButtonSignal()), this, SLOT(mostraCalcolaStipendiSlot()));
            connect(home, SIGNAL(mostraVenditeButtonSignal()), this, SLOT(mostraMostraVenditeSlot()));

        //inserisciVendita
            connect(inserisciVendita, SIGNAL(goToHomeSignal()), this, SLOT(mostraHomeSlot()));
        //calcolaStipendi
            connect(calcolaStipendi, SIGNAL(goToHomeSignal()), this, SLOT(mostraHomeSlot()));
        //mostraVendite
            connect(mostraVendite, SIGNAL(goToHomeSignal()), this, SLOT(mostraHomeSlot()));
        //inserisciVendita a mostraVendite
            connect(inserisciVendita, SIGNAL(inseritaNuovaVenditaSignal()), mostraVendite, SLOT(aggiornaVista()));
        //mostraVendite a calcolastipendi
            connect(mostraVendite, SIGNAL(salvaPressedSignal()), calcolaStipendi, SLOT(ricaricaSlot()));
    //aggiunta a stackedWidget
        stackedWidget->addWidget(home);
        stackedWidget->addWidget(inserisciVendita);
        stackedWidget->addWidget(calcolaStipendi);
        stackedWidget->addWidget(mostraVendite);
    //completamento gestori base
        layout->addWidget(stackedWidget);
        setLayout(layout);
}

PageHandler::~PageHandler()
{
    delete stackedWidget;
}

