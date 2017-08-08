#-------------------------------------------------
#
# Project created by QtCreator 2017-03-13T13:53:26
#
#-------------------------------------------------

QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hello_arm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ctrlthread.cpp \
    plotdialog.cpp \
    waveform.cpp

HEADERS  += mainwindow.h \
    ctrlthread.h \
    plotdialog.h \
    waveform.h
FORMS    += mainwindow.ui \
    plotdialog.ui
##################################################

   target.path = /home/pi
  # target.path = /home/linaro
   INSTALLS += target

##################################################


INCLUDEPATH += /usr/include/qwt/
INCLUDEPATH += /opt/wiringPi/include

LIBS += -L"/home/phantom/qwt-6.1.0/libArm/" -lqwt
LIBS += -L"/opt/wiringPi/lib/" -lwiringPi



