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
       void zamanlama();

private:

    int boy=50;
    int en=50;
    int btsayisi=5;
    QString version;
    QString sudoyetki="";
    QString user;
    QString passwordstatus;
    bool status;
    QLineEdit *localPassword;
    QLineEdit *localUsername;
    QPushButton *kurButton;
    QPushButton *removeButton;
    QPushButton *closeButton;
};

#endif // MAINWINDOW_H
