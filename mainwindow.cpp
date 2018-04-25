#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&m_person, &Human::hello, this, &MainWindow::change_log);
    connect(&m_person, &Human::goodbye, this, &MainWindow::change_log);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    m_person.set_name(ui->nameEdit->text());
    m_person.set_age(ui->ageEdit->text().toInt());
    collection.push_back(&m_person);
    ui->logger->setText(log+" was added");
}

void MainWindow::on_deleteButton_clicked()
{
    ui->logger->setText(log+" was deleted");
    collection.pop_back();
}

void MainWindow::change_log(QString name, int age)
{
    log= "("+name+", "+QString::number(age)+")";
}
