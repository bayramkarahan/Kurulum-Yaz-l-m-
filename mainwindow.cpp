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

    QMessageBox::information(this,"Program Kurulumu",
                             "\n"
                             "\nKurulum Tamamlandı.."
                             "\n");


}
void MainWindow::removeButtonClickSlot()
{

    kontrol();
if (status==false) return;

    QString kmt05="echo "+localPassword->text()+" |sudo -S su -c ' "+QDir::currentPath()+"/remove.sh'";
    system(kmt05.toStdString().c_str());
      system("sleep 1");



    QMessageBox::information(this,"Program Kaldırma",
                             "\n"
                             "\nEklentiler Kaldırıldı.."
                             "\n");
}

void MainWindow::kontrol()
{
    status=true;
    versionKontrolSlot();
    /********************password null text kontrol********************************/

     if(localPassword->text()=="")
    {
        QMessageBox::information(this,"Program Kurulumu","Lütfen Şifre Giriniz..");
        status=false;
        return;
    }
    /*********************sudo yetki kontrol*************************/
   sudoYetkiKontolSlot();
     if(sudoyetki=="0")
    {
        QMessageBox::information(this,"Program Kurulumu","Lütfen Yetkili Bir Kullanıcı ile Kurulum Yapınız..");
        status=false;
        return;
    }

    /*************************şifre kontrol***********************/
   passwordKontrolSlot();
   if(passwordstatus=="0")
    {
        QMessageBox::information(this,"Program Kurulumu","Lütfen Şifrenizi Doğru Giriniz..");
        status=false;
        return;
    }


}
MainWindow::~MainWindow()
{

}
