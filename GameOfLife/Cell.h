#pragma once
#include <memory>
#include <vector>

using namespace std;

class Cell
{
public:
	Cell();
	~Cell();

	void goToNewEra() { m_alive = m_nextAliveStatus; }
	void checkNeighbors();

	bool isAlive() { return m_alive; }

	void initNeighbors(const vector<shared_ptr<Cell>>& neighbors);
private:
	bool changeNextAliveStatus(); // return new "m_nextAliveStatus"

private:
	bool m_alive = false;
	bool m_nextAliveStatus = false;

	std::vector<std::weak_ptr<Cell>> m_neighborsWeakPtr;
};