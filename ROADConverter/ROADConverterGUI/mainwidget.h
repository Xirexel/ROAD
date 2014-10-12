#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>



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


private:
    Ui::MainWidget *ui;
    ListItemsModel *_ptrListItemsModel;
    OptionsWidget* _ptrOptionsWidget;

private slots:

    void addFiles();

    void openOptionsWidget();

    void updateModelOptions();

};

#endif // MAINWIDGET_H
