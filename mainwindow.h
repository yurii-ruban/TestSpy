#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "human.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void change_log(QString name, int age);

private:
    Human m_person;
    QVector<Human*> collection;
    QString log;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H