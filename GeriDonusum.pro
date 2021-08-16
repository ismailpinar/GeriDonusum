
    linux:!android:
    {
        QT += core gui network printsupport

    }
    linux:android:
    {
  #QT += core gui network printsupport androidextras

    }





greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_LFLAGS += -no-pie


CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Globaller.cpp \
    anaform.cpp \
    dialog.cpp \
    hakkinda.cpp \
    jsonokuyucu.cpp \
    main.cpp \
    malzemegiris.cpp \
    musterigirisi.cpp \
    musterilistesi.cpp \
    pdf.cpp \
    urungirisi.cpp

HEADERS += \
    Globaller.h \
    anaform.h \
    dialog.h \
    hakkinda.h \
    jsonokuyucu.h \
    malzemegiris.h \
    musterigirisi.h \
    musterilistesi.h \
    pdf.h \
    urungirisi.h

FORMS += \
    anaform.ui \
    dialog.ui \
    hakkinda.ui \
    hakkinda2.ui \
    malzemegiris.ui \
    musterigirisi.ui \
    musterilistesi.ui \
    urungirisi.ui

TRANSLATIONS += \
    GeriDonusum_tr_TR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



DISTFILES += \
    Info.ico \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/build.gradle \
    android/build.gradle \
    android/gradle.properties \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew \
    android/gradlew.bat \
    android/gradlew.bat \
    android/res/values/libs.xml \
    android/res/values/libs.xml \
    android/res/values/libs.xml \

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android



android: include(/home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/openssl.pri)

ANDROID_EXTRA_LIBS = /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/arm/libcrypto_1_1.so /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/arm/libssl_1_1.so /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/arm64/libcrypto_1_1.so /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/arm64/libssl_1_1.so /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/x86/libcrypto_1_1.so /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/x86/libssl_1_1.so /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/x86_64/libcrypto_1_1.so /home/mate/Qt/Tools/OpenSSL/android_openssl-1.1.1k_1.0.2u/latest/x86_64/libssl_1_1.so
android: include(/home/mate/Android/Sdk/android_openssl-master/openssl.pri)

RESOURCES += \
    resources.qrc
