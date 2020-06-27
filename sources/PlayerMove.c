#include "main.h"

bool PlayerMove(WINDOW *lvlWnd, char* direct, int **map, Object* player, size_t bCount, Object* Boxs, size_t eCount, Object* Endpoints, FILE *logFile)
{
	/* Заменить при отрисовке графики на нажатие клавиши */
	/*int tmpDirect = 0;
	if (!strcmp(direct,"up"))
	{
		tmpDirect = 1;
	}
	else if (!strcmp(direct,"down"))
	{
		tmpDirect = 2;
	}
	else if (!strcmp(direct,"left"))
	{
		tmpDirect = 3;
	}
	else if (!strcmp(direct,"right"))
	{
		tmpDirect = 4;
	}*/
	
	int ch = wgetch(lvlWnd);//считывание клавиши с окна уровня
	bool win;
	switch(ch)
	//switch (tmpDirect)
	{
		case KEY_UP:
		{
			if (MoveUp(map, player, bCount, Boxs, eCount, Endpoints))
			{
			        LevelOutput(lvlWnd, map, logFile, UP_MOVE);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		case KEY_DOWN:
		{
			if(MoveDown(map, player, bCount, Boxs, eCount, Endpoints))
			{
				LevelOutput(lvlWnd, map, logFile, DOWN_MOVE);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		case KEY_LEFT:
		{
			if(MoveLeft(map, player, bCount, Boxs, eCount, Endpoints))
			{
				LevelOutput(lvlWnd, map, logFile, LEFT_MOVE);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		case KEY_RIGHT:
		{
			if(MoveRight(map, player, bCount, Boxs, eCount, Endpoints))
			{
				LevelOutput(lvlWnd, map, logFile, RIGHT_MOVE);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		default:
		{
			/* Нажатие любой другой кнопки, помимо кнопок движения должно игнорироваться */
		}
	}
}
