#ifndef PAGEHANDLER_H
#define PAGEHANDLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "home.h"
#include "inseriscivendita.h"
#include "calcolastipendi.h"
#include "mostravendite.h"
#include "azienda.h"

class PageHandler : public QWidget
{
    Q_OBJECT
private:
        QStackedWidget *stackedWidget;
        Azienda az;
private slots:
    void mostraHomeSlot();
    void mostraInserisciVenditaSlot();
    void mostraCalcolaStipendiSlot();
    void mostraMostraVenditeSlot();
public:
    PageHandler(QWidget *parent = nullptr);
    ~PageHandler();
};
#endif // PAGEHANDLER_H
