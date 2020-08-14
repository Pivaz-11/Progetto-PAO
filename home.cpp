#include "home.h"

Home::Home(QWidget *parent) : QMainWindow(parent)
{
    //toolbar inutile ma karinaaaa con scritto benvenuto
        QToolBar *toolBar = addToolBar("main toolbar");
        toolBar->setMovable(false);
        QHBoxLayout *toolbarLayout = new QHBoxLayout();
        QLabel *titoloToolbar = new QLabel("Benvenuto!");
        QFont font = titoloToolbar->font();
        font.setPointSize(15);
        font.setBold(true);
        titoloToolbar->setFont(font);
        titoloToolbar->setAlignment(Qt::AlignCenter);
        toolbarLayout->addWidget(titoloToolbar, Qt::AlignCenter);
        toolbarLayout->setMargin(3);
        QWidget *tmp = new QWidget();
        tmp->setContentsMargins(0,0,0,0);
        tmp->setLayout(toolbarLayout);
        tmp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        toolBar->addWidget(tmp);
    //elementi grafici
        QWidget *mainWidget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();
        layout->setAlignment(Qt::AlignCenter);
        layout->setSpacing(10);
        QPushButton *aggiungiVenditaButton = new QPushButton("Aggiungi una vendita");
        QPushButton *calcolaStipendiButton = new QPushButton("Calcola gli stipendi");
        QPushButton *mostraVenditeButton = new QPushButton("Mostrami le nuove vendite");
        aggiungiVenditaButton->setMinimumSize(250, 30);
        calcolaStipendiButton->setMinimumSize(250, 30);
        mostraVenditeButton->setMinimumSize(250, 30);
    //connessioni onPressed dei buttons
        //connect(aggiungiVenditaButton, SIGNAL(clicked()), this, SLOT(aggiungiVenditaButtonSlot()));
        connect(aggiungiVenditaButton, SIGNAL(clicked()), this, SIGNAL(aggiungiVenditaButtonSignal()));
        connect(calcolaStipendiButton, SIGNAL(clicked()), this, SIGNAL(calcolaStipendiButtonSignal()));
        connect(mostraVenditeButton, SIGNAL(clicked()), this, SIGNAL(mostraVenditeButtonSignal()));
    //posizionamento elementi grafici
        layout->addWidget(aggiungiVenditaButton);
        layout->addWidget(calcolaStipendiButton);
        layout->addWidget(mostraVenditeButton);
        mainWidget->setLayout(layout);
        setCentralWidget(mainWidget);

}

