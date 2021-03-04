/*****************************************************************************
 *   Copyright (C) 2020 by Bayram KARAHAN                                    *
 *   <bayramk@gmail.com>                                                     *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 3 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          *
 *****************************************************************************/
#include "mainwindow.h"
#include<QProcess>
#include<init.h>
#include<QTimer>
#include<QSize>
#include<QApplication>
#include<QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(zamanlama()));
    timer->start(1000);

    this->setWindowFlags(Qt::Window|
                       //  Qt::FramelessWindowHint |
                       //Qt::WindowStaysOnTopHint);
                        Qt::X11BypassWindowManagerHint);
    QSize screenSize = qApp->screens()[0]->size();

this->move(screenSize.width()/2,screenSize.height()/2-this->height()/2);


init();
}


void MainWindow::zamanlama()
{

this->activateWindow();
//klavyeButtonClick();
    localPassword->setFocus();

}


void MainWindow::kurButtonClickSlot()
{

    kontrol();
    if (status==false) return;
     QString kmt05="echo "+localPassword->text()+" |sudo -S su -c ' "+QDir::currentPath()+"/install.sh'";
    system(kmt05.toStdString().c_str());
      system("sleep 1");
      QString sonuc=myMessageBox("Program Kurulumu", "\n"
                                                     "\nKurulum Tamamlandı.."
                                                     "\n","","","tamam",QMessageBox::Information);




}
void MainWindow::removeButtonClickSlot()
{

    kontrol();
if (status==false) return;

    QString kmt05="echo "+localPassword->text()+" |sudo -S su -c ' "+QDir::currentPath()+"/remove.sh'";
    system(kmt05.toStdString().c_str());
      system("sleep 1");



      QString sonuc=myMessageBox("Program Kurulumu", "\n"
                                                     "\nKurulum Tamamlandı.."
                                                     "\n","","","tamam",QMessageBox::Information);

}


QString MainWindow::myMessageBox(QString baslik, QString mesaj, QString evet, QString hayir, QString tamam, QMessageBox::Icon icon)
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    flags |= Qt::X11BypassWindowManagerHint;

    QMessageBox messageBox(this);
    messageBox.setWindowFlags(flags);
    messageBox.setText(baslik+"\t\t\t");
    messageBox.setInformativeText(mesaj);
    QAbstractButton *evetButton;
    QAbstractButton *hayirButton;
    QAbstractButton *tamamButton;

    if(evet=="evet") evetButton =messageBox.addButton(tr("Evet"), QMessageBox::ActionRole);
    if(hayir=="hayir") hayirButton =messageBox.addButton(tr("Hayır"), QMessageBox::ActionRole);
    if(tamam=="tamam") tamamButton =messageBox.addButton(tr("Tamam"), QMessageBox::ActionRole);

    messageBox.setIcon(icon);
    messageBox.exec();
    if(messageBox.clickedButton()==evetButton) return "evet";
    if(messageBox.clickedButton()==hayirButton) return "hayır";
    if(messageBox.clickedButton()==tamamButton) return "tamam";
    return "";
}


void MainWindow::kontrol()
{
    status=true;
    versionKontrolSlot();
    /********************password null text kontrol********************************/

     if(localPassword->text()=="")
    {
         QString sonuc=myMessageBox("Program Kurulumu", "\n"
                                                    "\nLütfen Şifre Giriniz..\n"
                                                      "\n","","","tamam",QMessageBox::Critical);

        status=false;
        return;
    }
    /*********************sudo yetki kontrol*************************/
   sudoYetkiKontolSlot();
     if(sudoyetki=="0")
    {
         QString sonuc=myMessageBox("Program Kurulumu", "\n"
                                                    "\nLütfen Yetkili Bir Kullanıcı ile Kurulum Yapınız...\n"
                                                      "\n","","","tamam",QMessageBox::Critical);
         status=false;
        return;
    }

    /*************************şifre kontrol***********************/
   passwordKontrolSlot();
   if(passwordstatus=="0")
    {
       QString sonuc=myMessageBox("Program Kurulumu", "\n"
                                           "\nLütfen Şifrenizi Doğru Giriniz..\n"
                                             "\n","","","tamam",QMessageBox::Critical);
         status=false;
        return;
    }


}
MainWindow::~MainWindow()
{

}
