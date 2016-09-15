TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT     += core
QT     -= gui

SOURCES += main.cpp \
           src/CompiledExpression.cpp \
           src/ExpressionProgram.cpp \
           src/ExpressionTreeNode.cpp \
           src/Operation.cpp \
           src/ParsedExpression.cpp \
           src/Parser.cpp \
           src/MSVC_erfc.h

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
    expressionhandler.h

