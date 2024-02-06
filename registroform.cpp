#include "registroform.h"
#include "ui_registroform.h"

RegistroForm::RegistroForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistroForm)
{
    ui->setupUi(this);
}

RegistroForm::~RegistroForm()
{
    delete ui;
}

QString RegistroForm::getNombres() const
{
    return ui->lneName->text();
}

QString RegistroForm::getApellidos() const
{
    return ui->lneLast->text();
}

int RegistroForm::getNota1() const
{
    return ui->sbxNot1->value();
}

int RegistroForm::getNota2() const
{
    return ui->sbxNot2->value();
}

void RegistroForm::on_buttonBox_accepted()
{
    QString nombres = getNombres();
    QString apellidos = getApellidos();
    int nota1 = getNota1();
    int nota2 = getNota2();

    // Verificar si los campos están vacíos
    if (nombres.isEmpty() || apellidos.isEmpty() || nota1 == 0 || nota2 == 0) {
        QMessageBox::warning(this, tr("Advertencia"), tr("Por favor, complete todos los campos no pueden estar vacios."));
        return; // Detener la ejecución si hay campos vacíos
    }

    // Combinar nombres y apellidos
    QString nombreCompleto = nombres + " " + apellidos;

    // Emitir la señal con los datos ingresados
    emit datosIngresados(nombreCompleto, nota1, nota2);

    // Cerrar el formulario
    this->parentWidget()->close();
}


void RegistroForm::on_buttonBox_rejected()
{
    this->parentWidget()->close();
}

