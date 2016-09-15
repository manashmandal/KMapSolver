#include "dialog.h"
#include "ui_dialog.h"

#include "filterkmapresults.h"
#include "operation.h"
#include "karnaughmap.h"
#include "graycodehandler.h"
#include "include/Lepton.h"
#include "expressionhandler.h"
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


}

Dialog::~Dialog()
{
    delete ui;
}
