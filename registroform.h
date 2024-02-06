#ifndef REGISTROFORM_H
#define REGISTROFORM_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class RegistroForm;
}

class RegistroForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegistroForm(QWidget *parent = nullptr);
    ~RegistroForm();

    QString getNombres() const;
    QString getApellidos() const;
    int getNota1() const;
    int getNota2() const;

signals:
    void datosIngresados(const QString& nombre, int nota1, int nota2);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::RegistroForm *ui;

};

#endif // REGISTROFORM_H
