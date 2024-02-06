#ifndef ABOUTFORM_H
#define ABOUTFORM_H

#include <QWidget>

namespace Ui {
class AboutForm;
}

class AboutForm : public QWidget
{
    Q_OBJECT

public:
    explicit AboutForm(QWidget *parent = nullptr);
    ~AboutForm();

private slots:
    void on_btnClose_released();

private:
    Ui::AboutForm *ui;
};

#endif // ABOUTFORM_H
