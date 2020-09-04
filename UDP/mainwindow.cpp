#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->radioButton_Red,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButton_Blue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->radioButton_black,SIGNAL(clicked()),this,SLOT(setTextFontColor()));

    connect(ui->checkBox_bold,SIGNAL(clicked()),this,SLOT(setTextFontShape()));
    connect(ui->checkBox_italic,SIGNAL(clicked()),this,SLOT(setTextFontShape()));
    connect(ui->checkBox_underline,SIGNAL(clicked()),this,SLOT(setTextFontShape()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTextFontShape()
{
    // 非互斥，互不影响
    QFont font = ui->textEdit_2->font();
    if (ui->checkBox_underline->isChecked())
        font.setUnderline(true);
    else
        font.setUnderline(false);
    if (ui->checkBox_bold->isChecked())
        font.setBold(true);
    else
        font.setBold(false);
    if (ui->checkBox_italic->isChecked())
        font.setItalic(true);
    else
        font.setItalic(false);
    ui->textEdit_2->setFont(font);
}

void MainWindow::setTextFontColor()
{
    // 互斥，if/else
    QPalette plet=ui->textEdit_2->palette();
    if (ui->radioButton_Blue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if (ui->radioButton_Red->isChecked())
       plet.setColor(QPalette::Text,Qt::red);
    else if (ui->radioButton_black->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else
       plet.setColor(QPalette::Text,Qt::black);
    ui->textEdit_2->setPalette(plet);
}
