#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_person, &Human::logger, this, &MainWindow::change_log);

    QRegExp rx( "[0-9]\\d{0,1}" );
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->ageEdit->setValidator(validator);

    qRegisterMetaType<Human>("Human");
    spy= new QSignalSpy(&m_person, SIGNAL(logger(QString,int)));
}

MainWindow::~MainWindow()
{
    delete spy;
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    m_person.setter(ui->nameEdit->text(), ui->ageEdit->text().toInt());
    collection.push_back(m_person);
    ui->logger->setText(log+" added");

    ui->logger->setStyleSheet("color:green");
    ui->ageEdit->setText("");
    ui->nameEdit->setText("");
}

void MainWindow::on_deleteButton_clicked()
{
    if(!collection.isEmpty())
    {
        m_person.setter(collection.last().get_name(),collection.last().get_age());

        ui->logger->setStyleSheet("color:red");
        ui->logger->setText(log+" deleted");
        collection.pop_back();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Container is empty, add more people!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        ui->logger->setText("");
    }
}

void MainWindow::change_log(QString name, int age)
{
    log= "("+name+", "+QString::number(age)+")";
}

void MainWindow::on_spyButton_clicked()
{
    ui->operationsEdit->setText(QString::number(spy->count()));
}
