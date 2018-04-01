/** @file credentials.h
*	@brief Receives the entered username and password from the login page.
*/

#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <QObject>

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
