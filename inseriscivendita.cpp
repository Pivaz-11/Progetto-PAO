#include "inseriscivendita.h"

QString InserisciVendita::AUTO = "Auto";
QString InserisciVendita::MOTO = "Moto";
QString InserisciVendita::AUTO_IBRIDA = "Auto Ibrida";
QString InserisciVendita::MONOPATTINO = "Monopattino";

void InserisciVendita::impostaFont(const std::vector<QLabel *>& labels)
{
    if(labels.size()<1) return;
    QFont font = labels[0]->font();
    font.setPointSize(15);
    font.setBold(true);
    for(unsigned int a = 0; a < labels.size(); a++){
        labels[a]->setFont(font);
    }
}

std::vector<QString> InserisciVendita::getIdDipendenti() const
{
    Lista<Dipendente*> lista = az->getDipendenti();
    std::vector<QString> ris;
    std::vector<unsigned int> risTemp;
    for(Lista<Dipendente*>::Iterator it = lista.begin(); it != lista.end(); ++it){
        risTemp.push_back((*it)->getId());
    }
    std::sort(risTemp.begin(), risTemp.end());
    for(std::vector<unsigned int>::iterator it = risTemp.begin(); it != risTemp.end(); ++it){
        ris.push_back(QString::number(*it));
    }
    return ris;
}

void InserisciVendita::popolaComboDipendenti(QComboBox *comboBox) const
{
    std::vector<QString> id(getIdDipendenti());
    for(unsigned int a = 0; a< id.size(); a++)
        comboBox->addItem(id[a]);
}

QHBoxLayout * InserisciVendita::layoutStelline(int lights){
    QHBoxLayout *layout = new QHBoxLayout();
    QLabel *image1;
    QPixmap image1px(":/resources/starLight.png");
    for(int a = 0; a<lights; a++){
        image1 = new QLabel();
        image1px = image1px.scaledToHeight(30);
        image1->setPixmap(image1px);
        layout->addWidget(image1);
    }
    QPixmap image2px(":/resources/starDark.png");
    for(int a = 0; a< 5-lights; a++){
        image1 = new QLabel();
        image2px = image2px.scaledToHeight(30);
        image1->setPixmap(image2px);
        layout->addWidget(image1);
    }
    return layout;
}

QWidget *InserisciVendita::creaWidgetStelline(int lights){
    QWidget *ris = new QWidget();
    ris->setLayout(layoutStelline(lights));
    return ris;
}

Mezzo *InserisciVendita::creaMezzo() const
{
    if(tipoMezzo == AUTO){
        return new Auto(idMezzo->text().toStdString(), potenza->value(), prezzo->value(),cilindrata->value());
    }
    if(tipoMezzo == MOTO){
        return new Moto(idMezzo->text().toStdString(), potenza->value(), prezzo->value(),cilindrata->value());
    }
    if(tipoMezzo == AUTO_IBRIDA){
        return new AutoIbrida(idMezzo->text().toStdString(), potenza->value(), prezzo->value(), cilindrata->value(), batteria->value());
    }
    if(tipoMezzo == MONOPATTINO){
        return new Monopattino(idMezzo->text().toStdString(), potenza->value(), prezzo->value(), batteria->value());
    }
    return nullptr;
}

void InserisciVendita::displayAd() const
{
    QMessageBox msgb(QMessageBox::Information,"Salvato", "La vendita è stata salvata", QMessageBox::Ok,const_cast<InserisciVendita*>(this)); //qmessagebox non accetta this, perhè la funzione è marcata const, quinid devo rimuovere il const
    msgb.exec();
}

void InserisciVendita::displayAdWrong() const
{
    QMessageBox msgb(QMessageBox::Information,"Errore", "La vendita non è stata salvata, inserisci almeno l'ID del mezzo", QMessageBox::Ok,const_cast<InserisciVendita*>(this)); //qmessagebox non accetta this, perhè la funzione è marcata const, quinid devo rimuovere il const
    msgb.exec();
}

void InserisciVendita::resettaCampi()
{
    idMezzo->setText("");
    cilindrata->setValue(0);
    batteria->setValue(0);
    potenza->setValue(0);
    prezzo->setValue(0);
    layout62->removeWidget(stelline); //tolgo dal layout la gestione di stelline, ma non fa il delete
    delete stelline;
    stelline = creaWidgetStelline(0);
    layout62->insertWidget(1,stelline);
}

InserisciVendita::InserisciVendita(Azienda* a, QWidget *parent) : QMainWindow(parent), az(a), tipoMezzo("Auto")
{
    //toolbar
        QToolBar *toolBar = addToolBar("main toolbar");
        QIcon backIcon = QApplication::style()->standardIcon(QStyle::SP_ArrowLeft);
        toolBar->setMovable(false);
        QAction *back= toolBar->addAction(backIcon, "Home");
        connect(back, SIGNAL(triggered()), this, SIGNAL(goToHomeSignal()));
    //layout verticale
        QVBoxLayout *vLayout = new QVBoxLayout();
        QWidget *widgetGestore = new QWidget();
        widgetGestore->setLayout(vLayout);
        setCentralWidget(widgetGestore);
    //layout griglia
        QGridLayout *mainLayout = new QGridLayout();
        mainLayout->setSpacing(0);
        QWidget *mainWidget = new QWidget();
        mainWidget->setLayout(mainLayout);
        mainLayout->setColumnStretch(0,5);
        mainLayout->setColumnStretch(1,1);
        mainLayout->setColumnStretch(2,5);
        vLayout->addWidget(mainWidget);

    //spacers
        int SPACERS_HEIGHT = 10;
        int SPACERS_WIDTH = 10;
        mainLayout->setRowMinimumHeight(1,SPACERS_HEIGHT);
        mainLayout->setRowMinimumHeight(3,SPACERS_HEIGHT);
        mainLayout->setRowMinimumHeight(5,SPACERS_HEIGHT);
        mainLayout->setColumnMinimumWidth(1,SPACERS_WIDTH);
    //vector dove metto le labels per sistemarle
        std::vector<QLabel*> labels;

    //comboBox idDipendente
        QWidget *w00 = new QWidget();
        QVBoxLayout *l00 = new QVBoxLayout();
        w00->setLayout(l00);
        QLabel *idDipendenteLabel = new QLabel("ID dipendente:");
        labels.push_back(idDipendenteLabel);
        l00->addWidget(idDipendenteLabel);
        l00->setAlignment(idDipendenteLabel, Qt::AlignCenter);
        idDipendente = new QComboBox();
        l00->addWidget(idDipendente);
        popolaComboDipendenti(idDipendente);
        l00->addStretch();
        mainLayout->addWidget(w00, 0, 0);

    //combobox tipoMezzo
        QWidget *w20 = new QWidget();
        QVBoxLayout *l20 = new QVBoxLayout();
        w20->setLayout(l20);
        QLabel *tipoMezzoLabel = new QLabel("Tipo mezzo:");
        labels.push_back(tipoMezzoLabel);
        l20->addWidget(tipoMezzoLabel);
        l20->setAlignment(tipoMezzoLabel, Qt::AlignCenter);
        QComboBox *tipoMezzo = new QComboBox();
        l20->addWidget(tipoMezzo);
        tipoMezzo->setInsertPolicy(QComboBox::InsertAlphabetically);
        tipoMezzo->addItem(AUTO);
        tipoMezzo->addItem(MOTO);
        tipoMezzo->addItem(AUTO_IBRIDA);
        tipoMezzo->addItem(MONOPATTINO);
        l20->addStretch();
        mainLayout->addWidget(w20, 2, 0);
        connect(tipoMezzo, SIGNAL(currentTextChanged(const QString &)), this, SLOT(tipoMezzoChanged(const QString &)));

     //text idMezzo
        QWidget *w02 = new QWidget();
        QVBoxLayout *l02 = new QVBoxLayout();
        w02->setLayout(l02);
        QLabel *idMezzoLabel = new QLabel("ID mezzo:");
        labels.push_back(idMezzoLabel);
        l02->addWidget(idMezzoLabel);
        l02->setAlignment(idMezzoLabel, Qt::AlignCenter);
        idMezzo = new QLineEdit();
        l02->addWidget(idMezzo);
        idMezzo->setMaxLength(20);
        l02->addStretch();
        mainLayout->addWidget(w02, 0,2);

    //text cilindrata
        QWidget *w22 = new QWidget();
        QVBoxLayout *l22= new QVBoxLayout();
        w22->setLayout(l22);
        QLabel *cilindrataLabel = new QLabel("Cilindrata [cm3]:");
        labels.push_back(cilindrataLabel);
        l22->addWidget(cilindrataLabel);
        l22->setAlignment(cilindrataLabel, Qt::AlignCenter);
        cilindrata = new QDoubleSpinBox();
        cilindrata->setSingleStep(200);
        cilindrata->setMaximum(10000);
        l22->addWidget(cilindrata);
        l22->addStretch();
        mainLayout->addWidget(w22,2,2);

    //text batteria
        QWidget *w42 = new QWidget();
        QVBoxLayout *l42 = new QVBoxLayout();
        w42->setLayout(l42);
        QLabel *batteriaLabel = new QLabel("Batteria: [Ah]");
        labels.push_back(batteriaLabel);
        l42->addWidget(batteriaLabel);
        l42->setAlignment(batteriaLabel, Qt::AlignCenter);
        batteria = new QDoubleSpinBox();
        batteria->setEnabled(false);
        batteria->setSingleStep(1);
        batteria->setMaximum(1000);
        l42->addWidget(batteria);
        l42->addStretch();
        mainLayout->addWidget(w42, 4, 2);



    //text potenza
        QWidget *w40 = new QWidget();
        QVBoxLayout *l40 = new QVBoxLayout();
        w40->setLayout(l40);
        QLabel *potenzaLabel = new QLabel("Potenza: [kW]");
        labels.push_back(potenzaLabel);
        l40->addWidget(potenzaLabel);
        l40->setAlignment(potenzaLabel, Qt::AlignCenter);
        potenza = new QDoubleSpinBox();
        potenza->setSingleStep(10);
        potenza->setMaximum(1000);
        l40->addWidget(potenza);
        l40->addStretch();
        mainLayout->addWidget(w40,4,0);

    //spinbox prezzo
        QWidget *w60 = new QWidget(0);
        QVBoxLayout *l60 = new QVBoxLayout();
        w60->setLayout(l60);
        QLabel *prezzoLabel = new QLabel("Prezzo:");
        labels.push_back(prezzoLabel);
        l60->addWidget(prezzoLabel);
        l60->setAlignment(prezzoLabel, Qt::AlignCenter);
        prezzo = new QDoubleSpinBox();
        prezzo->setSingleStep(500);
        prezzo->setMaximum(500000);
        l60->addWidget(prezzo);
        l60->addStretch();
        mainLayout->addWidget(w60,6,0 );

    //valutazione stelline
        QWidget *w62 = new QWidget();
        QVBoxLayout *l62 = new QVBoxLayout();
        layout62=l62;
        w62->setLayout(l62);
        QLabel *valutazioneLabel = new QLabel("Valutazione:");
        labels.push_back(valutazioneLabel);
        l62->addWidget(valutazioneLabel);
        l62->setAlignment(valutazioneLabel, Qt::AlignCenter);
        stelline = creaWidgetStelline(0);
        l62->addWidget(stelline);
        QPushButton *calcolaButton = new QPushButton("Calcola valutazione!");
        l62->addWidget(calcolaButton);
        connect(calcolaButton, SIGNAL(clicked()), this, SLOT(aggiornaStelline()));

        l62->addStretch();
        mainLayout->addWidget(w62, 6,2);

    //font label
        impostaFont(labels);

    //pulsante salva
        QPushButton *saveButton = new QPushButton("SALVA");
        saveButton->setMinimumWidth(100);
        vLayout->addWidget(saveButton);
        vLayout->addSpacing(20);
        vLayout->setAlignment(saveButton, Qt::AlignCenter);
        connect(saveButton, SIGNAL(clicked()), this, SLOT(salvaPressed()));

}

void InserisciVendita::salvaPressed()
{
    if(idMezzo->text().toStdString() == "")
        displayAdWrong();
    else{
        az->aggiungiVendita(std::stoi(idDipendente->currentText().toStdString()), creaMezzo());
        displayAd();
        resettaCampi();
        emit inseritaNuovaVenditaSignal();
    }
}


void InserisciVendita::tipoMezzoChanged(const QString &text)
{
    tipoMezzo = text;
    if(text == AUTO || text == MOTO){
        batteria->setEnabled(false);
        cilindrata->setEnabled(true);
    }
    if(text == AUTO_IBRIDA){
        batteria->setEnabled(true);
        cilindrata->setEnabled(true);
    }
    if(text == MONOPATTINO){
        batteria->setEnabled(true);
        cilindrata->setEnabled(false);
    }
}

void InserisciVendita::aggiornaStelline()
{
    Mezzo *mezzo = creaMezzo();
    layout62->removeWidget(stelline); //tolgo dal layout la gestione di stelline, ma non fa il delete
    delete stelline;
    stelline = creaWidgetStelline(mezzo->getStar());
    layout62->insertWidget(1,stelline);
    delete mezzo;
}
