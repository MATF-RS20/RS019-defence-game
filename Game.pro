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
    BuildSmallTower.cpp \
    Enemy.cpp \
    ExitBtn.cpp \
    Player.cpp \
    TowerSmall.cpp \
    TowerSmallBullet.cpp \
    main.cpp \
    Bomb.cpp \
    BuildBomb.cpp \
    BuildCannon.cpp \
    Cannon.cpp \
    CannonBullet.cpp \
    Robot.cpp \
    WomanEnemy.cpp \
    Lifes.cpp \
    Remover.cpp \
    BuildRemover.cpp \
    BuildWeapon.cpp \
    Weapon.cpp \
    WeaponBullets.cpp \
    Hole.cpp \
    BuildHole.cpp \
    PlayAgain.cpp \
    Zombie.cpp

HEADERS += \
    BuildSmallTower.h \
    Enemy.h \
    ExitBtn.h \
    Player.h \
    TowerSmall.h \
    TowerSmallBullet.h \
    Bomb.h \
    BuildBomb.h \
    BuildCannon.h \
    Cannon.h \
    CannonBullet.h \
    Robot.h \
    WomanEnemy.h \
    Lifes.h \
    Remover.h \
    BuildRemover.h \
    BuildWeapon.h \
    Weapon.h \
    WeaponBullets.h \
    Hole.h \
    BuildHole.h \
    PlayAgain.h \
    Zombie.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgs.qrc
