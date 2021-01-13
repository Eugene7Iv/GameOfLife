#pragma once

#include <QtWidgets/QWidget>
#include "ui_GameOfLife.h"
#include "Game.h"

class GameOfLife : public QWidget
{
    Q_OBJECT

public:
    GameOfLife(QWidget *parent = Q_NULLPTR);

private:
    Ui::GameOfLifeClass ui;

	Game* game;
};
