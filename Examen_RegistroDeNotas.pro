QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutform.cpp \
    calculos.cpp \
    main.cpp \
    principal.cpp \
    registroform.cpp

HEADERS += \
    aboutform.h \
    calculos.h \
    principal.h \
    registroform.h

FORMS += \
    aboutform.ui \
    principal.ui \
    registroform.ui

TRANSLATIONS += \
    en_us.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc

DISTFILES += \
    Recursos/aprobar.png \
    Recursos/carpeta.png \
    Recursos/cerrar-sesion.png \
    Recursos/creador-de-contenido.png \
    Recursos/disquete.png \
    Recursos/informacion.png \
    Recursos/registro.png \
    en_us.qm
