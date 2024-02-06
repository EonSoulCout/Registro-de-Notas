#ifndef CALCULOS_H
#define CALCULOS_H

#include <QString>

class Calculos
{
private:
    QString m_Nombres;
    int m_nota1;
    int m_nota2;
    int m_notaF;
    QString m_status;
    int m_notaMin;

public:
    Calculos();
    Calculos(const QString &Nombres, int nota1, int nota2);

    QString getNombres() const;
    void setNombres(const QString &Nombres);

    int getNota1() const;
    void setNota1(int nota1);

    int getNota2() const;
    void setNota2(int nota2);

    int getNotaF() const;
    void setNotaF();

    QString getStatus() const;
    void setStatus();

    int getNotaMin() const;
    void setNotaMin();
};

#endif // CALCULOS_H

