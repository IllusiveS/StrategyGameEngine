#include "maptiledisplay.h"
#include "ui_maptiledisplay.h"

MapTileDisplay::MapTileDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTileDisplay)
{
    ui->setupUi(this);
}

MapTileDisplay::~MapTileDisplay()
{
    delete ui;
}
