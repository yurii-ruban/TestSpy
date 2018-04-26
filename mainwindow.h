#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QMessageBox>
#include "human.h"
#include <QSignalSpy>

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
    void change_log(Human H);

    void on_spyButton_clicked();

private:
    QSignalSpy *spy;
    Human m_person;
    QStack<Human> collection;
    QString log;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
