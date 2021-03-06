#include "license.h"

#include <string>
#include <iostream>

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCryptographicHash>

void License::printLicenseHash() const
{
    qDebug() << m_licenseHash;
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
    stream << m_licenseHash;
}

QDate License::getExpiryDate() const
{
    return m_expiryDate;
}

uint License::getLicenseHash() const
{
    return m_licenseHash;
}

QString License::getMacAddress() const
{
    return m_macAddress;
}

void License::setExpiryDate(QDate expiry)
{
    m_expiryDate = expiry;
}

void License::setMacAddress(QString mac)
{
    m_macAddress = mac;
}
