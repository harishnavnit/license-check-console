#include "license.h"

#include <string>
#include <iostream>

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCryptographicHash>

void License::printLicenseHash() const
{
    qDebug() << _licenseHash;
}

uint License::generateLicenseHash(QString addr)
{
    return qHash(addr);
}

void License::saveToFile(QString fileName, QString path)
{
    QFile file(fileName);
    QDir::setCurrent(path);

    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
        qDebug() << "Failed to open file.";
        return;
    }

    QTextStream stream(&file);
    stream << _licenseHash;
}

QDate License::getExpiryDate() const
{
    return _expiryDate;
}

uint License::getLicenseHash() const
{
    return _licenseHash;
}

QString License::getMacAddress() const
{
    return _macAddress;
}

void License::setExpiryDate(QDate expiry)
{
    _expiryDate = expiry;
}

void License::setMacAddress(QString mac)
{
    _macAddress = mac;
}
