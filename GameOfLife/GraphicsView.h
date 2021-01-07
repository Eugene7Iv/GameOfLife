#pragma once
#include <QGraphicsView>

class GraphicsView :
	public QGraphicsView
{
	Q_OBJECT

public:
	GraphicsView(QWidget* pParent = nullptr);
	~GraphicsView();

signals:
	void mouseMoveSignal(int x, int y);

protected:
	void mouseMoveEvent(QMouseEvent* ev) override;
};

