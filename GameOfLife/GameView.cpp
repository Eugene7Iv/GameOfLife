#include "GameView.h"
#include <QMouseEvent>

GameView::GameView(QWidget * pParent) : QGraphicsView(pParent)
{
}

GameView::~GameView()
{
}

void GameView::mouseReleaseEvent(QMouseEvent * ev)
{
	emit mouseReleaseSignal(ev->pos());
}
