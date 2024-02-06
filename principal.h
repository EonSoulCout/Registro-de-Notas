#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QList>
#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>

#include "registroform.h"
#include "aboutform.h"

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

    void cargarTabla();

private slots:
    void addEst(const QString& nombre, int nota1, int nota2);

    void on_actionRegistro_triggered();

    void on_actionGuardar_triggered();

    void on_actionSalir_triggered();

    void on_actionCreditos_triggered();

private:
    Ui::Principal *ui;
    QVector<QString> m_nombres;
    QVector<RegistroForm> m_estudiantes;
    QVector<int> m_nota1;
    QVector<int> m_nota2;
    QVector<int> m_notaFin;
    QVector<QString> m_status;
    QVector<int> m_notaMin;
};
#endif // PRINCIPAL_H
