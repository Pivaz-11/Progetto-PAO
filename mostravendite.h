#ifndef MOSTRAVENDITE_H
#define MOSTRAVENDITE_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QStyle>
#include <QToolBar>
#include "azienda.h"
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

class MostraVendite : public QMainWindow
{
    Q_OBJECT
private:
    Azienda* az;
    static void resizeVendite(QTreeWidget* t);
    static QTreeWidget* UpdateVendite(Azienda *a);
    QTreeWidget* tab;
    void ricaricaTab(); //elimina e ricrea tab per aggiornarlo
public:
    explicit MostraVendite(Azienda* a, QWidget *parent = nullptr);

signals:
    void goToHomeSignal();
    void salvaPressedSignal();
public slots:
    void aggiornaVista(); //viene triggerato quando nella pagina inserisci vendita ho cliccato su salva
    void savePressedSlot(); //triggerato quando si clicca sull'icona salva
};

#endif // MOSTRAVENDITE_H
