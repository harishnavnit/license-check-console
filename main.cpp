#include <iostream>

#include <QDebug>
#include <QCoreApplication>

#include "license.h"
#include "validate.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string macAddr;
    QString _macAddr;

    std::cout << "Enter MAC address : ";
    std::cin >> macAddr;

    _macAddr = QString::fromStdString(macAddr);

    License *l = new License(_macAddr);
    Validate v(l);

    v.isValidLicense() ? qDebug() << "Valid License" : qDebug() << "Invalid License" ;

    return a.exec();
}
