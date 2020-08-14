#ifndef CALCOLASTIPENDI_H
#define CALCOLASTIPENDI_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QAction>
#include <QStyle>
#include <QToolBar>
#include "azienda.h"
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QHeaderView>
#include <ctgmath>
#include <QSharedPointer>

class CalcolaStipendi : public QMainWindow
{
    Q_OBJECT
private:
    QTreeWidget* table;
    std::vector<QTreeWidgetItem *> itmVect; // mi serve per salvare tutti gli treewidgetitem (in UpdateStipendi) per azzerarli in modo rapido quando azzero le vendite
    void resizeEvent(QResizeEvent *) override; //resizeEvent viene chiamata ogni volta che la finestra viene resizata
    Azienda* az;
    static QWidget* StipendiRating(int x =0);
    void UpdateStipendi(Azienda *a);
    static void resizeStipendi(QTreeWidget* t);
    void ricaricaTab(); //ricarica il tree in caso di aggiornamenti in altre finestre
    void azzeraTab(); //porta a 0 TUTTi gli stipendi e TUTTE le stelline. NON modifica gli ID stipendi
public:
    explicit CalcolaStipendi(Azienda* a, QWidget *parent = nullptr);

signals:
    void goToHomeSignal();
public slots:
    void ricaricaSlot(); //chiamato quando salvo le vendite in mostraVendite
    void deleteStipendiSlot(); // resetta a zero gli stipendi dei dipendenti dell'azienda
};

#endif // CALCOLASTIPENDI_H
