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
    BuildHole.cpp \
    BuildRemover.cpp \
    BuildWeapon.cpp \
    Cannon.cpp \
    CannonBullet.cpp \
    Coins.cpp \
    Game.cpp \
    Hole.cpp \
    Lifes.cpp \
    PlayAgain.cpp \
    Remover.cpp \
    Robot.cpp \
    Score.cpp \
    Weapon.cpp \
    WeaponBullets.cpp \
    WomanEnemy.cpp \
    Zombie.cpp \
    TankRocket.cpp \
    Tank.cpp \
    BuildTank.cpp

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
    BuildHole.h \
    BuildRemover.h \
    BuildWeapon.h \
    Cannon.h \
    CannonBullet.h \
    Coins.h \
    Game.h \
    Hole.h \
    Lifes.h \
    PlayAgain.h \
    Remover.h \
    Robot.h \
    Score.h \
    Weapon.h \
    WeaponBullets.h \
    WomanEnemy.h \
    Zombie.h \
    TankRocket.h \
    Tank.h \
    BuildTank.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgs.qrc
