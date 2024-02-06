#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[]){

        QApplication a(argc, argv);
        QTranslator traducion;
        QStringList idiomas;
        idiomas << "English" << "Spanish";
        QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                           "Languaje",
                                                           "Set a languaje",
                                                           idiomas);
        if (idiomaSeleccionado == "English"){
            traducion.load(":/en_us.qm");
        }
    if (idiomaSeleccionado != "Spanish"){
        a.installTranslator(&traducion);
    }
    Principal w;
    w.show();
    return a.exec();
}
