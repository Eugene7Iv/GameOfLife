#pragma once
#include <vector>
#include <memory>
#include "Cell.h"

using namespace std;

class Game
{
	friend class GameOfLife;
public:
	Game(size_t hc, size_t vc);
	~Game();

	void iterarion();
private:
	void createField();
	void initNeighbors();

private:
	vector<vector<shared_ptr<Cell>>> m_pGameField;

	size_t m_nHorCell;
	size_t m_nVerCell;
};
