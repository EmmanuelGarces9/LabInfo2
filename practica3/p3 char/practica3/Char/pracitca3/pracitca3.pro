TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        src/Cod_y_Deco/codYDeco.cpp \
        src/Cod_y_Deco/extra/printInfoArray.cpp \
        src/Cod_y_Deco/extra/unir_char.cpp \
        src/Cod_y_Deco/postreglas/magic.cpp \
        src/Cod_y_Deco/prereglas/funcionesparametodos.cpp \
        src/Cod_y_Deco/reglas/metodo1.cpp \
        src/Cod_y_Deco/reglas/metodo2.cpp \
        src/main.cpp \
        test/test1.cpp

DISTFILES += \
    build/test1/1245578.txt \
    build/test1/test1_v1 \
    build/test1/test1_v2 \
    build/test1/test1_v3 \
    build/test1/test1_v4

HEADERS += \
    hdr/codYDeco.h \
    hdr/extra/printInfoArray.h \
    hdr/extra/unir_char.h \
    hdr/postreglas/magic.h \
    hdr/prereglas/funcionesparametodos.h \
    hdr/reglas/metodo1.h \
    hdr/reglas/metodo2.h
