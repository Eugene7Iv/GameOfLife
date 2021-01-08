#pragma once
#include <qgraphicsview.h>
class GameView :
	public QGraphicsView
{
	Q_OBJECT
public:
	GameView(QWidget* pParent = nullptr);
	~GameView();

protected:
	void mouseReleaseEvent(QMouseEvent* ev) override;

public:
signals:
	void mouseReleaseSignal(const QPoint& pos);
};

