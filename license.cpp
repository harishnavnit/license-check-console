#include "license.h"

#include <QCryptographicHash>

QByteArray License::generateLicenseHash(QByteArray addr)
{
    return QCryptographicHash::hash(addr, QCryptographicHash::Md4);
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
