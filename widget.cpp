#include "widget.h"

Label::Label(QWidget *parent)
    : QLabel(parent)
{
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
   // img.load(":/mg/180px-Tux.svg.png");
   // setPixmap(img);

    mv=new QMovie(":/mg/Gif/doom1.gif");
    setMovie(mv);
    mv->start();

    this->setMouseTracking(true);
    setWindowFlags(Qt::SplashScreen | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    widthDesktop=QApplication::desktop()->availableGeometry().width();
    heightDesktop=QApplication::desktop()->availableGeometry().height();

    move(widthDesktop/3,heightDesktop/3);

}

void Label::mouseMoveEvent(QMouseEvent *pe){
    moveImage(pe);
}

void Label::moveImage(QMouseEvent *pe){

   if((pe->globalX()>=this->x()-(this->width()/2)&&pe->globalX()<=this->x()+(this->width()/2))||(pe->globalX()>=this->x()+(this->width()/2)&&pe->globalX()<=this->x()+(this->width()))){
        this->move(rand()%(widthDesktop-this->width()*2)+this->width(),rand()%(heightDesktop-this->height()*2)+this->height());
    }
}

Label::~Label()
{

}
