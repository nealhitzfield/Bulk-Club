/** @file credentials.h
*	@brief Contains data in regard to username and password pairs within the databse.
*/

#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <QObject>

/**
* @brief Loads username and password pairs from the database.
*/
class Credentials
{
private:
    QString username;
    QString password;
public:
    Credentials(QString usern, QString passw);

    QString GetUsername() const;
    QString GetPassword() const;
};

#endif // CREDENTIALS_H
