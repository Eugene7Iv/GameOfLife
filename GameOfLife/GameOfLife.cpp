#include "GameOfLife.h"
#include <QGraphicsRectItem>
#include <iostream>
#include "GameView.h"

GameOfLife::GameOfLife(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
