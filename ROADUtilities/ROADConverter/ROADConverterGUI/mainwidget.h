#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPoint>



class ListItemsModel;
class OptionsWidget;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void closeEvent(QCloseEvent *event);

protected:

    void mousePressEvent(QMouseEvent * event);

    void mouseReleaseEvent(QMouseEvent * event);

    void mouseMoveEvent(QMouseEvent * event);


private:
    Ui::MainWidget *ui;
    ListItemsModel *_ptrListItemsModel;
    OptionsWidget* _ptrOptionsWidget;
    bool _pressLeftButtonMouse;
    QPoint _prevPosition;

private slots:

    void addFiles();

    void openOptionsWidget();

    void updateModelOptions();

};

#endif // MAINWIDGET_H
