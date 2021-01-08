#include "Cell.h"

Cell::Cell()
{
}


Cell::~Cell()
{
}

void Cell::initNeighbors(const vector<shared_ptr<Cell>>& neighbors)
{
	for (auto cell : neighbors)
		m_neighborsWeakPtr.push_back(cell);
}

bool Cell::changeNextAliveStatus()
{
	m_nextAliveStatus = !m_alive;

	return m_nextAliveStatus;
}

void Cell::checkNeighbors()
{
	int numberOfAliveNeighbors = 0;
	for (auto& cellWeakPtr : m_neighborsWeakPtr)
	{
		auto cellPtr = cellWeakPtr.lock();
		if (!cellPtr)
			return;
		if (cellPtr->isAlive())
			numberOfAliveNeighbors++;
	}

	if (numberOfAliveNeighbors == 3 && !isAlive())
		changeNextAliveStatus();
	else if ((numberOfAliveNeighbors == 2 ||
		numberOfAliveNeighbors == 3) && isAlive())
		return;
	else if((numberOfAliveNeighbors < 2 || 
		numberOfAliveNeighbors > 3) && isAlive())
		changeNextAliveStatus();

}
