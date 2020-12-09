#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QDebug>
#include<QDir>
#include<QWidget>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
#include<QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void init();
    void kurButtonClickSlot();
    void removeButtonClickSlot();
    void kontrol();
    void sudoYetkiKontolSlot();
    void passwordKontrolSlot();
    void versionKontrolSlot();

private:
    QString yol="/EbaDers/";
    int boy=50;
    int en=50;
    int btsayisi=4;
    QString version;
    QString sudoyetki="";
    QString user;
    QString passwordstatus;
    bool status;
    QLineEdit *localPassword;
    QLineEdit *localUsername;
    QPushButton *chromeeklentiButton;
    QPushButton *linkButton;
    QPushButton *chromeButton;
    QPushButton *zoomButton;
    QPushButton *kurButton;
    QPushButton *removeButton;
};

#endif // MAINWINDOW_H
