#include "GameOfLife.h"
#include <QGraphicsRectItem>
#include <iostream>

GameOfLife::GameOfLife(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEditView->setReadOnly(true);
	ui.labelView->setText("View coordinates");
	ui.labelScene->setText("Scene coordinates");
	setWindowTitle("Game of life");
	setFixedHeight(600);
	setFixedWidth(800);

	ui.graphicsView->setBackgroundBrush(QBrush(QColor(0, 0, 0)));

	QGraphicsScene* scene = new QGraphicsScene();	
	scene->setSceneRect(ui.graphicsView->rect());
	ui.graphicsView->setScene(scene);
	auto rect = scene->addRect(0, 0, 8, 8);
	rect->setBrush(QBrush(QColor(255, 255, 255)));
	

	connect(ui.graphicsView, &GraphicsView::mouseMoveSignal,
		[&](int x, int y) {
		QString sPoint = QString("(%1, %2)").arg(x).arg(y);
		ui.lineEditView->setText(sPoint);
		QPointF p = ui.graphicsView->mapToScene(QPoint(x, y));
		sPoint = QString("(%1, %2)").arg(p.x()).arg(p.y());;
		ui.lineEditScene->setText(sPoint);
	});

	
}
