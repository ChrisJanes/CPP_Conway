#include "Conway.h"



Conway::Conway()
{
}


Conway::~Conway()
{
}

int Conway::checkNeighbours(int x, int y)
{
	int neighbours = 0;
	if (x > 0)
	{
		if (board[x - 1][y] == 1)
			neighbours++;

		if (y > 0)
		{
			if (board[x - 1][y - 1] == 1)
				neighbours++;
		}

		if (y < 12)
		{
			if (board[x - 1][y + 1] == 1)
				neighbours++;
		}
	}

	if (y > 0)
	{
		if (board[x][y - 1] == 1)
			neighbours++;

		if (x < 12)
		{
			if (board[x + 1][y - 1] == 1)
				neighbours++;
		}
	}

	if (y < 12)
	{
		if (board[x][y + 1] == 1)
			neighbours++;

		if (x < 12)
		{
			if (board[x + 1][y + 1] == 1)
				neighbours++;
		}
	}

	if (x < 12)
	{
		if (board[x + 1][y] == 1)
			neighbours++;
	}

	return neighbours;
}

void Conway::Update()
{
	int newboard[12][12];

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			newboard[i][j] = 0;
		}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			int neighbours = checkNeighbours(i, j);
			
			// if dead
			if (board[i][j] == 0 && neighbours == 3)
				newboard[i][j] = 1;

			if (board[i][j] == 1)
			{
				if (neighbours < 2)
					newboard[i][j] = 0;
				if (neighbours == 2 || neighbours == 3)
					newboard[i][j] = 1;
				if (neighbours > 3)
					newboard[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			board[i][j] = newboard[i][j];
		}
	}
}

void Conway::Draw()
{
	std::system("cls");

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			std::cout << ((board[i][j] == 0) ? " " : "#");
		}

		std::cout << std::endl;
	}
}
