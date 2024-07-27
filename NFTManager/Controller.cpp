#include "Controller.h"
#include <QDebug>

Controller::Controller(QObject *parent)
    : QObject{parent}
{}

void Controller::debug()
{
    qDebug() << "[DEBUG] Whatever this is, I guess it is working!";
}
