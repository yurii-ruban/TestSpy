#ifndef HUMAN_H
#define HUMAN_H

#include<QObject>
#include <QString>

class Human: public QObject
{
    Q_OBJECT
public:
    explicit Human(QObject *parent = nullptr);
    Human(QString _name, int _age);
    void changeName(QString _name);
    void set_name(QString _name);
    void set_age(int _age);
    QString get_name();
    int get_age();
    ~Human();

private:
    QString name;
    int age;

signals:
    void goodbye(QString name, int age);
    void hello(QString name, int age);
};

#endif // HUMAN_H
