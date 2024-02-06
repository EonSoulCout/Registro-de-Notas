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
