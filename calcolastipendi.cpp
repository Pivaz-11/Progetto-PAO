#include "calcolastipendi.h"
// restituisce la un file png con la corrispondente valutazione del Dipendente
QWidget* CalcolaStipendi::StipendiRating(int x){
    // Utilizzo del QWidget in modo da centrare l'immagine nella celle, operazione non concessa con QIcon
    QWidget *k=new QWidget();
    QHBoxLayout *lal=new QHBoxLayout(k);
    QLabel *image1;
    QPixmap image(":/resources/starLight.png");
    for(int a=0;a<x;++a){
        image1 = new QLabel();
        //QPixmap image=QPixmap(":/resources/starLight.png");
        image = image.scaled(QSize(20,20),Qt::AspectRatioMode::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
        image1->setPixmap(image);
        lal->addWidget(image1);
    }
    QPixmap imagep(":/resources/starDark.png");
    for(int a=0;a<5-x;++a){
        image1 = new QLabel();
        imagep = imagep.scaled(QSize(20,20),Qt::AspectRatioMode::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
        image1->setPixmap(imagep);
        lal->addWidget(image1);
    }
    return k;
}

// creazione della tabella
void CalcolaStipendi::UpdateStipendi(Azienda *a){
    table= new QTreeWidget();
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //nasconde la scrollbar orizzontale
    table->setColumnCount(3);
    QStringList Titoli;
    Titoli<<"ID DIPENDENTE"<<"STIPENDIO"<<"RATING";
    table->setHeaderLabels(Titoli);
    // allineamento dell'header
    for(int h=0;h<3;++h)
        table->headerItem()->setTextAlignment(h,Qt::AlignCenter);
    table->header()->setSectionResizeMode(QHeaderView::Fixed); //impedisce all'utente di fare resize delle colonne
    Lista<Dipendente*> b=a->getDipendenti();
    // popolamento della tabella
    double d;
    QTreeWidgetItem *itm;
    for(Lista<Dipendente*>::Iterator it =b.begin();it!=b.end();++it){
        itm = new QTreeWidgetItem(table);
        itmVect.push_back(itm);
        itm->setText(0,QString::number((*it)->getId()));
        itm->setText(1,QString::number((*it)->getStipendio()));
        // gestione del caso in cui non siano state effettuate vendite (0/0)
        d = (*it)->getNvendite();

        if(d>0){
           table->setItemWidget(itm,2,StipendiRating(round(((*it)->getSumRating()/d))));
        }else{
            table->setItemWidget(itm,2,StipendiRating(0));
        }
        //allineamento oggetti della lista
        for(int m=0;m<3;++m) itm->setTextAlignment(m,Qt::AlignCenter);
        table->addTopLevelItem(itm);

    }
}

void CalcolaStipendi::resizeEvent(QResizeEvent *event) { //Imposta il width al 30% del totale per la prima colonna, 20% e 45% per la seconda e terza. 5% rimanente è per dare spazio alla barra di scroll
    table->setColumnWidth(0, this->width()/10*3);
    table->setColumnWidth(1, this->width()/10*2);
    table->setColumnWidth(2, this->width()/10*4.5);
    QMainWindow::resizeEvent(event); //viene richiamato l'override originale in qmainwindow che fa le sue cose
}

//resize delle colonne della tabella
void CalcolaStipendi::resizeStipendi(QTreeWidget* t){
    for(int i=0;i<3;++i){
        t->resizeColumnToContents(i);
    }
}

void CalcolaStipendi::ricaricaTab()
{
    delete table;
    UpdateStipendi(az);
    resizeStipendi(table);
    setCentralWidget(table);
}



CalcolaStipendi::CalcolaStipendi(Azienda* a, QWidget *parent) : QMainWindow(parent), table(nullptr), az(a)
{
    //toolbar
        QToolBar *toolBar = addToolBar("main toolbar");
        QIcon backIcon = QApplication::style()->standardIcon(QStyle::QStyle::SP_ArrowLeft);
        QIcon delete_icon=QApplication::style()->standardIcon(QStyle::QStyle::SP_DialogCancelButton);
        toolBar->setMovable(false);
        QAction *back= toolBar->addAction(backIcon, "Home");
        toolBar->addSeparator();
        QAction *deletes=toolBar->addAction(delete_icon, "Azzera");
        connect(back, SIGNAL(triggered()), this, SIGNAL(goToHomeSignal()));
        connect(deletes,SIGNAL(triggered()),this,SLOT(deleteStipendiSlot()));
        ricaricaTab();
}

void CalcolaStipendi::ricaricaSlot()
{
    itmVect.clear();
    ricaricaTab();
}

void CalcolaStipendi::azzeraTab()
{
    for(std::vector<QTreeWidgetItem *>::iterator it = itmVect.begin(); it != itmVect.end(); ++it){
        (*it)->setText(1,"0");
        table->removeItemWidget(*it,2);
        table->setItemWidget(*it,2,StipendiRating(0));
    }
}

void CalcolaStipendi::deleteStipendiSlot(){
    QMessageBox msgb(QMessageBox::Information,"Azzerato", "Gli stipendi sono stati resettati", QMessageBox::Ok,this);
    az->azzeraStipendi();
    ricaricaTab();
    msgb.exec();
}
