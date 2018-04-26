#include "human.h"

Human::Human(QObject* parent):QObject(parent)
{
    emit logger(name, age);
}

Human::Human(QString _name, int _age):name(_name), age(_age)
{
    emit logger(name, age);
}

Human::Human(const Human &H)
{
    this->name=H.get_name();
    this->age=H.get_age();
}

Human &Human::operator =(const Human& H)
{
    this->name=H.get_name();
    this->age=H.get_age();
    return *this;
}

void Human::changeName(QString _name)
{
    name=_name;
}

void Human::setter(QString _name, int _age)
{
    name=_name;
    age= _age;
    emit logger(name, age);
}

QString Human::get_name() const
{
    return name;
}

int Human::get_age() const
{
    return age;
}

Human::~Human()
{
}
