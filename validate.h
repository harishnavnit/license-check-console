#ifndef VALIDATE_H
#define VALIDATE_H

#include "license.h"

class Validate
{
public:
    // Constructor
    Validate(License *ptr) : m_license(ptr)
    {
    }

    // Destructor
    ~Validate();

    // Getter methods
    License* getLicense() const;
    bool isValidLicense() const;

    // Setter methods
    void setLicense(License *license);

private:
    License *m_license;
};

#endif // VALIDATE_H
