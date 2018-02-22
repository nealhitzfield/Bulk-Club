#include "credentials.h"

Credentials::Credentials(QString usern, QString passw)
{
    username = usern;
    password = passw;
}

QString Credentials::GetUsername() const
{
    return username;
}

QString Credentials::GetPassword() const
{
    return password;
}
