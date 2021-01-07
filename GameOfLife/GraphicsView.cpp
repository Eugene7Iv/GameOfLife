#include "GraphicsView.h"
#include <QMouseEvent>
GraphicsView::GraphicsView(QWidget * pParent) : QGraphicsView(pParent)
{
	setMouseTracking(true);
}

GraphicsView::~GraphicsView()
{
}

void GraphicsView::mouseMoveEvent(QMouseEvent * ev)
{
	auto point = ev->pos();
	emit mouseMoveSignal(point.x(), point.y());
}
