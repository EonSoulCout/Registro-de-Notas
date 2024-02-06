#include "principal.h"
#include "registroform.h"

#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_actionRegistro_triggered()
{
    // Crear una instancia de RegistroForm como un cuadro de diálogo
    RegistroForm *registroForm = new RegistroForm(this);

    // Mostrar como un cuadro de diálogo modal
    QDialog dialog;
    dialog.setWindowTitle("Registro");
    dialog.setLayout(new QVBoxLayout);
    dialog.layout()->addWidget(registroForm);

    // Si se acepta, realizar acciones necesarias
    if (dialog.exec() == QDialog::Accepted) {
        // Realizar acciones después de aceptar en RegistroForm
    }

    // Eliminar la instancia de RegistroForm
    delete registroForm;
}


void Principal::on_actionGuardar_triggered()
{
    //que me guarde como csv
}


void Principal::on_actionSalir_triggered()
{
    close();
}

