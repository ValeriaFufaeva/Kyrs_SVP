#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QValidator>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int
    male_height,
    woman_height;

double
    male_imt,
    woman_imt,
    devin_male_imt,
    devin_woman_imt,
    robinson_male_imt,
    robinson_woman_imt;

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QRegularExpression rx ("[1-9][0-9][0-9]");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit->setValidator(validator);
}

void MainWindow::DATA_INPUT()
{
    QString S1 = ui->lineEdit->text();
    male_height = S1.toInt();
    woman_height = S1.toInt();
}


void MainWindow::BROCK_IMT()
{
    DATA_INPUT();

    if (ui->radioButton->isChecked()) {

        male_imt = male_height - (100 + (male_height - 100) / 20);
            ui->lineEdit_2->setText(QString::number(male_imt));
    }
    else if (ui->radioButton_2->isChecked()) {

        woman_imt = woman_height - (100 + (woman_height - 100) / 10);
            ui->lineEdit_2->setText(QString::number(woman_imt));
    }
}

void MainWindow::DEVIN_IMT()
{
    DATA_INPUT();

    if (ui->radioButton->isChecked()) {

        devin_male_imt = 50 + 2.3 * ((0.394 * male_height) - 60);
        ui->lineEdit_2->setText(QString::number(devin_male_imt));
    }

    else if (ui->radioButton_2->isChecked()) {

        devin_woman_imt = 45.5 + 2.3 * ((0.394 * woman_height) - 60);
        ui->lineEdit_2->setText(QString::number(devin_woman_imt));

    }
}

void MainWindow::ROBINSON_IMT()
{
    DATA_INPUT();

    if (ui->radioButton->isChecked()) {

        robinson_male_imt = 52 + 1.9 * ((0.394 * male_height) - 60);
        ui->lineEdit_2->setText(QString::number(robinson_male_imt));
    }

    else if (ui->radioButton_2->isChecked()) {

        robinson_woman_imt = 49 + 1.7 * ((0.394 * woman_height) - 60);
        ui->lineEdit_2->setText(QString::number(robinson_woman_imt));

    }
}

void MainWindow::AVERAGE_IMT()
{
    double average;

    BROCK_IMT();
    DEVIN_IMT();
    ROBINSON_IMT();

    if (ui->radioButton->isChecked()) {

       average = (male_imt + devin_male_imt + robinson_male_imt)/3;

    }
    else if (ui->radioButton_2 ->isChecked()) {

        average = (woman_imt + devin_woman_imt + robinson_woman_imt)/3;

    }

    ui->lineEdit_2->setText(QString::number(average));
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->comboBox->currentIndex() == 0) {

        BROCK_IMT();
    }
    if (ui->comboBox->currentIndex() == 1) {

        DEVIN_IMT();
    }
    if (ui->comboBox->currentIndex() == 2) {

        ROBINSON_IMT();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    AVERAGE_IMT();
}

