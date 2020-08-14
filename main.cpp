#include "pagehandler.h"
#include "azienda.h"

#include "auto.h"
#include "moto.h"
#include "autoibrida.h"
#include <QApplication>

//DEBUG
#include "dipendente.h"
#include "lista.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PageHandler w;
    w.show();
    return a.exec();
}
