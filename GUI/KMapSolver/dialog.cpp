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
    setWindowTitle("KMap Solver");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_minimizeButton_clicked()
{
    KarnaughMap k;
    std::string expr = ui->expressionLineEdit->text().toUpper().toStdString();
    k.setType(countVariable(expr));
    k.setOnesPosition(getOnesPosition(expr));
    k.setResultType(true);
    std::string res = k.getResult();
    cout << "Result: " << res << endl;
    ui->resultLineEdit->setText(QString::fromStdString(res));
}

void Dialog::on_clearButton_clicked()
{
    ui->expressionLineEdit->clear();
    ui->resultLineEdit->clear();
}
