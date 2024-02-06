#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QList>
#include <QDialog>

#include "registroform.h"

#include "calculos.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionRegistro_triggered();

    void on_actionGuardar_triggered();

    void on_actionSalir_triggered();

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
