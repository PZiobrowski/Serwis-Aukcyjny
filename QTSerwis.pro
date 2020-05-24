QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Aukcja.cpp \
    Rozmowa.cpp \
    Uzytkownik_administrator.cpp \
    Wiadomosc.cpp \
    aukcjadialog.cpp \
    bank.cpp \
    bank_uzytkownik.cpp \
    chatdialog.cpp \
    funkcje.cpp \
    main.cpp \
    mainwindow.cpp \
    powiaz_dialog.cpp \
    przedmiot.cpp \
    przedmiotdialog.cpp \
    serwis.cpp \
    serwis_uzytkownik.cpp \
    uzytkownik.cpp

HEADERS += \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/Aukcja.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/Aukcja.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/Rozmowa.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/Uzytkownik_administrator.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/Wiadomosc.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/bank.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/bank_uzytkownik.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/przedmiot.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/serwis.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/serwis_uzytkownik.h \
    ../PK4 - serwis aukcyjny/PK4 - serwis aukcyjny/uzytkownik.h \
    Aukcja.h \
    Rozmowa.h \
    Uzytkownik_administrator.h \
    Wiadomosc.h \
    aukcjadialog.h \
    bank.h \
    bank_uzytkownik.h \
    chatdialog.h \
    funkcje.h \
    mainwindow.h \
    powiaz_dialog.h \
    przedmiot.h \
    przedmiotdialog.h \
    serwis.h \
    serwis_uzytkownik.h \
    uzytkownik.h

FORMS += \
    aukcjadialog.ui \
    chatdialog.ui \
    mainwindow.ui \
    powiaz_dialog.ui \
    przedmiotdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Zasoby.qrc
