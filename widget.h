#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QtWidgets>
#include <QGraphicsSceneMouseEvent>
#include <QMovie>

class Label : public QLabel
{
    Q_OBJECT

public:
    Label(QWidget *parent = 0);
    ~Label();
private:
    // Функция, в которой производится отслеживание положения мыши
       void mouseMoveEvent(QMouseEvent *event);

    void moveImage(QMouseEvent* pe);
    int widthDesktop;
    int heightDesktop;
    QPixmap img;
    QMovie* mv;
signals:
    // Сигнал для передачи координат положения курсора мыши
};

#endif // WIDGET_H
