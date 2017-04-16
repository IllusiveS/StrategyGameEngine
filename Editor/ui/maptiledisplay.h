#ifndef MAPTILEDISPLAY_H
#define MAPTILEDISPLAY_H

#include <QWidget>

namespace Ui {
class MapTileDisplay;
}

class MapTileDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit MapTileDisplay(QWidget *parent = 0);
    ~MapTileDisplay();

private:
    Ui::MapTileDisplay *ui;
};

#endif // MAPTILEDISPLAY_H
