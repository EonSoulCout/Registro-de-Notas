#ifndef REGISTROFORM_H
#define REGISTROFORM_H

#include <QWidget>

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

private:
    Ui::RegistroForm *ui;

};

#endif // REGISTROFORM_H
