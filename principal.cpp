#include "principal.h"
#include "registroform.h"

#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    ui->tblEstu->setColumnCount(6);  // Configurar el número de columnas
    ui->tblEstu->setHorizontalHeaderLabels(QStringList() << tr("Nombre") << tr("Nota 1") << tr("Nota 2") << tr("Nota Final") << tr("Estado") << tr("Nota Minima"));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_actionRegistro_triggered()
{
    // Crear una instancia de RegistroForm como un cuadro de diálogo
    RegistroForm *registroForm = new RegistroForm(this);

    // Mostrar como un cuadro de diálogo modal
    QDialog dialog;
    dialog.setWindowTitle(tr("Registro"));
    dialog.setLayout(new QVBoxLayout);
    dialog.layout()->addWidget(registroForm);
    connect(registroForm, &RegistroForm::datosIngresados, this, &Principal::addEst);

    // Si se acepta, realizar acciones necesarias
    if (dialog.exec() == QDialog::Accepted) {
        // Realizar acciones después de aceptar en RegistroForm
    }
}


void Principal::on_actionGuardar_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar archivo CSV"), "", tr("Archivos CSV (*.csv);;Todos los archivos (*.*)"));

    if (!filePath.isEmpty()) {
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            for (int i = 0; i < m_nombres.size(); ++i) {
                stream << m_nombres[i] << "," << m_nota1[i] << "," << m_nota2[i] << "," << m_notaFin[i] << "," << m_status[i] << "," << m_notaMin[i] << "\n";
            }
            file.close();
        } else {
            qDebug() << tr("Error al abrir el archivo para escribir");
        }
    }
}

void Principal::cargarTabla()
{
    ui->tblEstu->setRowCount(m_nombres.size());

    for (int i = 0; i < m_nombres.size(); ++i) {
        QTableWidgetItem *itemNombre = new QTableWidgetItem(m_nombres[i]);
        QTableWidgetItem *itemNota1 = new QTableWidgetItem(QString::number(m_nota1[i]));
        QTableWidgetItem *itemNota2 = new QTableWidgetItem(QString::number(m_nota2[i]));

        // Perform calculations
        Calculos calculo(m_nombres[i], m_nota1[i], m_nota2[i]);
        calculo.setNotaF();
        calculo.setStatus();
        calculo.setNotaMin();

        // Create items for calculated values
        QTableWidgetItem *itemNotaFinal = new QTableWidgetItem(QString::number(calculo.getNotaF()));
        QTableWidgetItem *itemEstado = new QTableWidgetItem(calculo.getStatus());
        QTableWidgetItem *itemNotaMinima = new QTableWidgetItem(QString::number(calculo.getNotaMin()));

        // Set items in the table
        ui->tblEstu->setItem(i, 0, itemNombre);
        ui->tblEstu->setItem(i, 1, itemNota1);
        ui->tblEstu->setItem(i, 2, itemNota2);
        ui->tblEstu->setItem(i, 3, itemNotaFinal);
        ui->tblEstu->setItem(i, 4, itemEstado);
        ui->tblEstu->setItem(i, 5, itemNotaMinima);
    }

    qDebug() << "Tabla cargada correctamente.";
}

void Principal::on_actionSalir_triggered()
{
    close();
}

void Principal::addEst(const QString &nombre, int nota1, int nota2)
{

    m_nombres.append(nombre);
    m_nota1.append(nota1);
    m_nota2.append(nota2);
    qDebug() << "Estudiante agregado:"
             << "Nombre:" << nombre
             << "Nota1:" << nota1
             << "Nota2:" << nota2;

    cargarTabla();

}


void Principal::on_actionCreditos_triggered()
{
    // Crear una instancia de RegistroForm como un cuadro de diálogo
    AboutForm *aboutform = new AboutForm(this);

    // Mostrar como un cuadro de diálogo modal
    QDialog dialog;
    dialog.setWindowTitle(tr("Creditos"));
    dialog.setLayout(new QVBoxLayout);
    dialog.layout()->addWidget(aboutform);

    // Si se acepta, realizar acciones necesarias
    if (dialog.exec() == QDialog::Accepted) {
        // Realizar acciones después de aceptar en RegistroForm
    }
}

