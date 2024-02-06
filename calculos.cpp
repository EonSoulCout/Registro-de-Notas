#include "calculos.h"

Calculos::Calculos() : m_Nombres(""), m_nota1(0), m_nota2(0), m_notaF(0), m_status(""), m_notaMin(0)
{
}

Calculos::Calculos(const QString &Nombres, int nota1, int nota2) : m_Nombres(Nombres), m_nota1(nota1), m_nota2(nota2), m_notaF(0), m_status(""), m_notaMin(0)
{
}

QString Calculos::getNombres() const
{
    return m_Nombres;
}

void Calculos::setNombres(const QString &Nombres)
{
    m_Nombres = Nombres;
}

int Calculos::getNota1() const
{
    return m_nota1;
}

void Calculos::setNota1(int nota1)
{
    m_nota1 = nota1;
}

int Calculos::getNota2() const
{
    return m_nota2;
}

void Calculos::setNota2(int nota2)
{
    m_nota2 = nota2;
}

int Calculos::getNotaF() const
{
    return m_notaF;
}

void Calculos::setNotaF()
{
    m_notaF = (getNota1()+getNota2());
}

void Calculos::setStatus()
{
    int nota = getNotaF();
    if (nota >= 70) {
        m_status = "Aprobado";
    } else if (nota < 70 && nota >= 25) {
        m_status = "Remedial";
    } else {
        m_status = "Reprobado";
    }

}

void Calculos::setNotaMin()
{
    m_notaMin = (70-0.4*getNotaF())/0.6;
}

int Calculos::getNotaMin() const
{
    return m_notaMin;
}

QString Calculos::getStatus()
{
    return m_status;
}
