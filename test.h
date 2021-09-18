#ifndef TEST_H
#define TEST_H

#include <QMainWindow>

class test : public QMainWindow
{
    Q_OBJECT

public:
    test(QWidget *parent = nullptr);
    ~test();
};
#endif // TEST_H
