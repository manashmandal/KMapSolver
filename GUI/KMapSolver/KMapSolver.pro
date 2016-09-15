QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KMapSolver
TEMPLATE = app

SOURCES += main.cpp \
           src/CompiledExpression.cpp \
           src/ExpressionProgram.cpp \
           src/ExpressionTreeNode.cpp \
           src/Operation.cpp \
           src/ParsedExpression.cpp \
           src/Parser.cpp \
           src/MSVC_erfc.h \
    dialog.cpp

HEADERS += \
    comparekmapterms.h \
    filterkmapresults.h \
    operation.h \
    setkmap.h \
    karnaughmap.h \
    graycodehandler.h \
    include/Lepton.h \
    include/lepton/CompiledExpression.h \
    include/lepton/CustomFunction.h \
    include/lepton/Exception.h \
    include/lepton/ExpressionProgram.h \
    include/lepton/ExpressionTreeNode.h \
    include/lepton/Operation.h \
    include/lepton/ParsedExpression.h \
    include/lepton/Parser.h \
    include/lepton/windowsIncludes.h \
    expressionhandler.h \
    dialog.h

FORMS += \
    dialog.ui

