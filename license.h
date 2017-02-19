#ifndef LICENSE_H
#define LICENSE_H

#include <QDir>
#include <QDate>
#include <QString>
#include <QByteArray>

class License
{
public:
    // Constructors
    License() :
        _macAddress(""), _expiryDate(QDate::currentDate()), _licenseHash("")
    {
        saveToFile(QString("test.txt"));
    }

    License(QString mac):
        _macAddress(mac), _expiryDate(QDate::currentDate())
    {
        _licenseHash = generateLicenseHash(_macAddress.toUtf8());
        saveToFile(QString("test.txt"));
    }

    License(QString mac, QDate expiry) :
        _macAddress(mac),
        _expiryDate(expiry)
    {
        _licenseHash = generateLicenseHash(_macAddress.toUtf8());
        saveToFile(QString("test.txt"));
    }

    // Print the generated license hash
    void printLicenseHash() const;

    // Generate the Hash from a MAC addr
    QByteArray generateLicenseHash(QByteArray addr);

    // Write the generated license hash and expiry date to a file
    void saveToFile(QString fileName, QString path=QDir::homePath());

    // Getter methods
    QDate getExpiryDate() const;
    QString getMacAddress() const;
    QByteArray getLicenseHash() const;

    // Setter methods
    void setExpiryDate(QDate date);
    void setMacAddress(QString mac);

private:
    QDate _expiryDate;
    QString _macAddress;
    QByteArray _licenseHash;
};

#endif // LICENSE_H
