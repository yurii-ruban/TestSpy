#ifndef HUMAN_H
#define HUMAN_H

#include<QObject>
#include <QString>
#include <QDebug>

class Human: public QObject
{
    Q_OBJECT
public:
    explicit Human(QObject *parent = nullptr);
    Human(QString _name, int _age);
    ~Human();

    Human(const Human& H);
    Human& operator =(const Human& H);

    void setter(QString _name, int _age);
    QString get_name() const;
    int get_age() const;

private:
    QString name;
    int age;

signals:
    void logger(Human h);
};

#endif // HUMAN_H
