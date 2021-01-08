#include "Game.h"

Game::Game(size_t hc, size_t vc) :
	m_nHorCell(hc),
	m_nVerCell(vc)
{
	createField();
	initNeighbors();
}

Game::~Game()
{
}

void Game::createField()
{
	m_pGameField.reserve(m_nVerCell);
	for (size_t i = 0; i < m_nVerCell; i++)
	{
		m_pGameField.push_back(vector<shared_ptr<Cell>>(m_nHorCell));
		for (size_t j = 0; j < m_nHorCell; j++)
			m_pGameField[i].push_back(shared_ptr<Cell>());
	}
}

void Game::initNeighbors()
{
	auto init = [&](shared_ptr<Cell> currCell, vector<pair<size_t, size_t>>& indxs) -> void
	{
		vector<shared_ptr<Cell>> neighbors;
		for (auto indxPair : indxs)
			neighbors.push_back(m_pGameField[indxPair.first][indxPair.second]);
		currCell->initNeighbors(neighbors);
	};

	for (size_t i = 0; i < m_pGameField.size(); i++)
		for (size_t j = 0; j < m_pGameField[i].size(); j++)
		{
			auto& cellPtr = m_pGameField[i][j];
			if (i == 0 && j == 0)
			{
				vector<pair<size_t, size_t>> indxs{ {i,j + 1},{i + 1,j},{i + 1,j + 1} };
				init(cellPtr, indxs);
			}
			else if (i == m_nHorCell - 1 && j == m_nVerCell - 1)
			{
				vector<pair<size_t, size_t>> indxs{ {i - 1,j - 1},{i - 1,j},{i,j - 1} };
				init(cellPtr, indxs);
			}
			else if (i == 0 && j != 0)
			{
				vector<pair<size_t, size_t>> indxs{
													{i    ,j - 1},             {i    ,j + 1},
													{i + 1,j - 1}, {i + 1,j},{i + 1,j + 1} };
				init(cellPtr, indxs);
			}
			else if (i != 0 && j == 0)
			{
				vector<pair<size_t, size_t>> indxs{ {i - 1,j},{i - 1,j + 1},
													          {i    ,j + 1},
													{i + 1,j},{i + 1,j + 1} };
				init(cellPtr, indxs);
			}
			else if (i != 0 && j != 0)
			{
				vector<pair<size_t, size_t>> indxs{ {i - 1,j - 1}, {i - 1,j},{i - 1,j+1},
													{i    ,j - 1},			 {i    ,j+1},
													{i + 1,j - 1}, {i + 1,j},{i + 1,j+1}};
				init(cellPtr, indxs);
			}




		}
}

void Game::iterarion()
{
	for (size_t i = 0; i < m_pGameField.size(); i++)
		for (size_t j = 0; j < m_pGameField[i].size(); j++)
		{
			auto& cellPtr = m_pGameField[i][j];
			cellPtr->checkNeighbors();
		}

	for (auto cells : m_pGameField)
		for (auto& cellPtr : cells)
		{
			cellPtr->goToNewEra();
		}
}
