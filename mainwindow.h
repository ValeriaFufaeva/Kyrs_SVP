#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void DATA_INPUT();
    void BROCK_IMT();
    void DEVIN_IMT();
    void ROBINSON_IMT();
    void AVERAGE_IMT();
    void on_pushButton_clicked();
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
