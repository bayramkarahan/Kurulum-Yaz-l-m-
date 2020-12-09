#include "mainwindow.h"
#include<QProcess>
#include<init.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
init();
}

void MainWindow::kurButtonClickSlot()
{

    kontrol();
    if (status==false) return;
/*
    QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                             "\n"
                             "Kurulum tamamlanınca alta bulunan butonlar yeşil olacak ve pasifleşecektir..."
                             "Lütfen bekleyiniz.."

                             "\n"
                             "\n\t         Bayram KARAHAN"
                             "\n\tBilişim Teknolojileri Öğretmeni"
                             "\n"
                             "\n"
                             "İstek ve önerileriniz için;"
                             "\nE-Posta: bayramk@gmail.com"
                             "\nwww.bayramkarahan.blogspot.com"
                             "\n");
                             */
    QString kmt05="echo "+localPassword->text()+" |sudo -S su -c ' "+QDir::currentPath()+"/install.sh'";
    system(kmt05.toStdString().c_str());
      system("sleep 1");

    QMessageBox::information(this,"Eba Canlı Ders Kurulumu",
                             "\n"
                             "\nKurulum Tamamlandı.."
                             "\n");


}
void MainWindow::removeButtonClickSlot()
{

    kontrol();
if (status==false) return;
  /*  QMessageBox::information(this,"Eba Canlı Ders Kurulum Kaldırma",
                             "\n"
                             "Eklentilerin KAldırılması tamamlanınca alta bulunan butonlar kırmızı olacak ve aktifleşecektir..."
                             "Lütfen bekleyiniz.."

                             "\n"
                             "\n\t         Bayram KARAHAN"
                             "\n\tBilişim Teknolojileri Öğretmeni"
                             "\n"
                             "\n"
                             "İstek ve önerileriniz için;"
                             "\nE-Posta: bayramk@gmail.com"
                             "\nwww.bayramkarahan.blogspot.com"
                             "\n");
                             */
    QString kmt05="echo "+localPassword->text()+" |sudo -S su -c ' "+QDir::currentPath()+"/remove.sh'";
    system(kmt05.toStdString().c_str());
      system("sleep 1");



    QMessageBox::information(this,"Eba Canlı Ders Kurulum Kaldırma",
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
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu","Lütfen Şifre Giriniz..");
        status=false;
        return;
    }
    /*********************sudo yetki kontrol*************************/
   sudoYetkiKontolSlot();
     if(sudoyetki=="0")
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu","Lütfen Yetkili Bir Kullanıcı ile Kurulum Yapınız..");
        status=false;
        return;
    }

    /*************************şifre kontrol***********************/
   passwordKontrolSlot();
   if(passwordstatus=="0")
    {
        QMessageBox::information(this,"Eba Canlı Ders Kurulumu","Lütfen Şifrenizi Doğru Giriniz..");
        status=false;
        return;
    }


}
MainWindow::~MainWindow()
{

}
