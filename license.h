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
        _macAddress(""), _expiryDate(QDate::currentDate()), _licenseHash(000)
    {
        saveToFile(QString("test.txt"));
    }

    License(QString mac):
        _macAddress(mac), _expiryDate(QDate::currentDate())
    {
        _licenseHash = generateLicenseHash(_macAddress);
        saveToFile(QString("test.txt"));
    }

    License(QString mac, QDate expiry) :
        _macAddress(mac),
        _expiryDate(expiry)
    {
        _licenseHash = generateLicenseHash(_macAddress);
        saveToFile(QString("test.txt"));
    }

    // Print the generated license hash
    void printLicenseHash() const;

    // Generate the Hash from a MAC addr
    uint generateLicenseHash(QString addr);

    // Write the generated license hash and expiry date to a file
    void saveToFile(QString fileName, QString path=QDir::homePath());

    // Getter methods
    uint getLicenseHash() const;
    QDate getExpiryDate() const;
    QString getMacAddress() const;

    // Setter methods
    void setExpiryDate(QDate date);
    void setMacAddress(QString mac);

private:
    uint _licenseHash;
    QDate _expiryDate;
    QString _macAddress;
};

#endif // LICENSE_H
