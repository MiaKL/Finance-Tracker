QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Category.cpp \
    CategoryDatabase.cpp \
    Date.cpp \
    Entry.cpp \
    EntryDatabase.cpp \
    Menu.cpp \
    User.cpp \
    UserDatabase.cpp \
    W_CreateNewCategory.cpp \
    W_CreateNewEntry.cpp \
    W_DeleteEntry.cpp \
    W_DisplayEntries.cpp \
    W_GenerateGraph.cpp \
    W_Login.cpp \
    main.cpp \
    qcustomplot.cpp

HEADERS += \
    Category.h \
    CategoryDatabase.h \
    Date.h \
    Entry.h \
    EntryDatabase.h \
    Menu.h \
    User.h \
    UserDatabase.h \
    W_CreateNewCategory.h \
    W_CreateNewEntry.h \
    W_DeleteEntry.h \
    W_DisplayEntries.h \
    W_GenerateGraph.h \
    W_Login.h \
    qcustomplot.h

FORMS += \
    Menu.ui \
    W_CreateNewCategory.ui \
    W_CreateNewEntry.ui \
    W_DeleteEntry.ui \
    W_DisplayEntries.ui \
    W_GenerateGraph.ui \
    W_Login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
