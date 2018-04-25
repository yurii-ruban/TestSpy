#include "human.h"

Human::Human(QObject* parent):QObject(parent)
{
    emit hello(name, age);
}

Human::Human(QString _name, int _age):name(_name), age(_age)
{
    emit hello(name, age);
}

void Human::changeName(QString _name)
{
    name=_name;
}

void Human::set_name(QString _name)
{
    name=_name;
    emit hello(name, age);
}

void Human::set_age(int _age)
{
    age= _age;
    emit hello(name, age);
}

QString Human::get_name()
{
    return name;
}

int Human::get_age()
{
    return age;
}

Human::~Human()
{
    emit goodbye(name, age);
}
