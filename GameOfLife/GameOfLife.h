#pragma once

#include <QtWidgets/QWidget>
#include "ui_GameOfLife.h"

class GameOfLife : public QWidget
{
    Q_OBJECT

public:
    GameOfLife(QWidget *parent = Q_NULLPTR);

private:
    Ui::GameOfLifeClass ui;
};
