#include "mostravendite.h"
// creazione della tabella
QTreeWidget* MostraVendite::UpdateVendite(Azienda *a){
    QTreeWidget *table= new QTreeWidget();
    table->setColumnCount(3);
    QStringList Titoli;
    Titoli<<"ID MEZZO"<<"PREZZO"<<"ID DIPENDENTE";
    table->setHeaderLabels(Titoli);
    // allineamento dell'header
    for(int h=0;h<3;++h)
        table->headerItem()->setTextAlignment(h,Qt::AlignCenter);
    // resize dell'header
    table->header()->setSectionResizeMode(2,QHeaderView::Stretch);
    table->header()->setSectionResizeMode(1,QHeaderView::Stretch);
    table->header()->setSectionResizeMode(0,QHeaderView::Stretch);
    Lista<Dipendente*> b=a->getDipendenti();
    // popolamento della tabella
    for(Lista<Dipendente*>::Iterator it =b.begin();it!=b.end();++it){
        Lista<Mezzo*> lista=(*it)->getLista();
        // test che il dipendente abbia effettuato vendite
        if(lista.getSize()>0){
            for(Lista<Mezzo*>::Iterator it1=lista.begin(); it1!=lista.end(); ++it1){
                QTreeWidgetItem *itm=new QTreeWidgetItem(table);
                itm->setText(0,QString::fromStdString((*it1)->getIdMezzo()));
                itm->setText(1,QString::number((*it1)->getPrezzo()));
                itm->setText(2,QString::number((*it)->getId()));
                //allineamento oggetti della lista
                for(int m=0;m<3;++m) itm->setTextAlignment(m,Qt::AlignCenter);
                table->addTopLevelItem(itm);
                }
        }
     }
    return table;
}

void MostraVendite::ricaricaTab()
{
    delete tab;
    tab = UpdateVendite(az);
    resizeVendite(tab);
    setCentralWidget(tab);
}

//resize delle colonne della tabella
void MostraVendite::resizeVendite(QTreeWidget* t){
    for(int i=0;i<3;++i){
        t->resizeColumnToContents(i);
    }
}

MostraVendite::MostraVendite(Azienda* a, QWidget *parent) : QMainWindow(parent), az(a), tab(nullptr)
{
    //toolbar
        QToolBar *toolBar = addToolBar("main toolbar");
        QIcon backIcon = QApplication::style()->standardIcon(QStyle::QStyle::SP_ArrowLeft);
        QIcon save_icon = QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton);
        toolBar->setMovable(false);
        QAction *back= toolBar->addAction(backIcon, "Home");
        toolBar->addSeparator();
        QAction *save = toolBar->addAction(save_icon, "Salva");
        connect(back, SIGNAL(triggered()), this, SIGNAL(goToHomeSignal()));
        connect(save,SIGNAL(triggered()), this, SLOT(savePressedSlot()));
        ricaricaTab();
}

void MostraVendite::aggiornaVista()
{
    ricaricaTab();
}

void MostraVendite::savePressedSlot()
{
    az->salvaStipendi();
    QMessageBox msgb(QMessageBox::Information,"Salvate", "Gli stipendi sono stati aggiornati in base alle nuove vendite\nLe nuove vendite sono state ora azzerate", QMessageBox::Ok,this);
    msgb.exec();
    ricaricaTab();
    emit salvaPressedSignal();
}



