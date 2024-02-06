#include "aboutform.h"
#include "ui_aboutform.h"

AboutForm::AboutForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);

    ui->label_2->setText(tr("Creador:\n\nMateo Espinosa\nhttps://github.com/EonSoulCout/Registro-de-Notas\n"));
}

AboutForm::~AboutForm()
{
    delete ui;
}

void AboutForm::on_btnClose_released()
{
    this->parentWidget()->close();
}

