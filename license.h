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
        m_macAddress(""), m_expiryDate(QDate::currentDate()), m_licenseHash(000)
    {
        saveToFile(QString("test.txt"));
    }

    License(QString mac):
        m_macAddress(mac), m_expiryDate(QDate::currentDate())
    {
        m_licenseHash = generateLicenseHash(m_macAddress);
        saveToFile(QString("test.txt"));
    }

    License(QString mac, QDate expiry) :
        m_macAddress(mac), m_expiryDate(expiry)
    {
        m_licenseHash = generateLicenseHash(m_macAddress);
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
    uint m_licenseHash;
    QDate m_expiryDate;
    QString m_macAddress;
};

#endif // LICENSE_H
