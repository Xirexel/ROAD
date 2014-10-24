#ifndef PROGRESSCONTROLPANEL_H
#define PROGRESSCONTROLPANEL_H

#include <QWidget>

namespace Ui {
class ProgressControlPanel;
}

class ProgressControlPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressControlPanel(QWidget *parent = 0);
    ~ProgressControlPanel();

private:
    Ui::ProgressControlPanel *ui;
};

#endif // PROGRESSCONTROLPANEL_H
