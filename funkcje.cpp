#include "funkcje.h"

#include <string>
#include <string.h>

QString pozyskaj_date()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    QString data;

    int tmp1 = st.wYear;
    string tmp2 =  to_string(tmp1);
    QString help = QString::fromStdString(tmp2);
    data.push_back(help);
    data.push_back("-");

    tmp1 = st.wMonth;
    tmp2 =  to_string(tmp1);
    help = QString::fromStdString(tmp2);
    if(help.size()==1)
        help.push_front("0");
    data.push_back(help);
    data.push_back("-");

    tmp1 = st.wDay;
    tmp2 =  to_string(tmp1);
    help = QString::fromStdString(tmp2);
    if(help.size()==1)
        help.push_front("0");
    data.push_back(help);
    data.push_back("  ");

    tmp1 = st.wHour;
    tmp2 =  to_string(tmp1);
    help = QString::fromStdString(tmp2);
    if(help.size()==1)
        help.push_front(" ");
    data.push_back(help);
    data.push_back(":");

    tmp1 = st.wMinute;
    tmp2 =  to_string(tmp1);
    help = QString::fromStdString(tmp2);
    if(help.size()==1)
        help.push_front("0");
    data.push_back(help);

    return data;

}
