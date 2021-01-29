#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <QtScript/QScriptClass>
#include <QtScript/QScriptEngine>
#include "parser.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(481,390);
    connect(ui->pushButton_0,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->pushButton_cos,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_ctg,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_division,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_dot,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_multiplication,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_parenthesisClose,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_parenthesisOpen,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_plus,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_pow,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_root,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_sin,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_tg,SIGNAL(released()), this, SLOT(digit_pressed()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed() {

   /* QPushButton * button = (QPushButton*)sender();


    double labelNumber;
    QString newLabel;

    labelNumber = (ui->label->text() + button->text()).toDouble();
    newLabel = QString::number(labelNumber,'g',15);

    //ui -> label -> setText(button->text());
    ui ->label->setText(newLabel);*/

    QPushButton * button = (QPushButton*)sender();

   //     QString test = "23+25";
     //   QScriptEngine engine;

    ui->label->setText(ui->label->text() + button->text());

}


void MainWindow::on_pushButton_clear_released()
{
    ui->label->setText(0);
}

void MainWindow::on_pushButton_equal_released()
{
    QPushButton * button = (QPushButton*)sender();
    ui->label->setText(ui->label->text() + button->text());

    QString expression = ui->label->text();
    string xd = expression.toStdString();
    convertExpression(xd);
    string tab[100];
    string ONP[100];


    int size = expressionToArray(xd,tab);

    if (validation(tab, size)){
       expressionToRPN(tab, ONP);
       double wynik;
       wynik = ONPToResult(ONP);
       xd = to_string(wynik);
       expression = expression.fromStdString(xd);
    } else {
        expression = "ERROR";
    }







    //qDebug(expression.toLatin1());
    ui->label->setText(expression);

}

