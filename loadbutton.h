#ifndef LOADBUTTON_H
#define LOADBUTTON_H

#include <QObject>
#include <QPushButton>

class LoadButton : public QPushButton
{
    Q_OBJECT
public:
    LoadButton(QWidget* qw):QPushButton(qw){}
signals:
    void iChanged(QObject*);

public slots:
    void buildMyDatabase();
};

#endif // LOADBUTTON_H
