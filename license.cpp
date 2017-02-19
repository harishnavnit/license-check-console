#include "license.h"

#include <string>
#include <iostream>

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCryptographicHash>

void License::printLicenseHash() const
{
    std::string str = _licenseHash.toStdString();
    std::cout << "[ " << str << " ]";

    qDebug() << QString::fromStdString(str);
}

QByteArray License::generateLicenseHash(QByteArray addr)
{
    return QCryptographicHash::hash(addr, QCryptographicHash::Md4);
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
    foreach(char c, _licenseHash) {
        stream << c;
    }
}

QDate License::getExpiryDate() const
{
    return _expiryDate;
}

QByteArray License::getLicenseHash() const
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
