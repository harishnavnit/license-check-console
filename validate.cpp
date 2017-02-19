#include "validate.h"

#include <QtNetwork/QNetworkInterface>

Validate::~Validate()
{
    delete m_license;
}

License* Validate::getLicense() const
{
    return m_license;
}

bool Validate::isValidLicense() const
{
    const QString interfaceName = "wlo1";
    QNetworkInterface interface = QNetworkInterface::interfaceFromName(interfaceName);

    //qDebug() << "Machine MAC address = " << interface.hardwareAddress();
    //qDebug() << "MAC address provided = " << m_license->getMacAddress().toUpper();

    return interface.hardwareAddress() == m_license->getMacAddress().toUpper();
}

void Validate::setLicense(License *license)
{
    m_license = license;
}
