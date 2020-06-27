#include "main.h"

bool PlayerMove(WINDOW *lvlWnd, char* direct, int **map, Object* player, size_t bCount, Object* Boxs, size_t eCount, Object* Endpoints, FILE *logFile, size_t count)
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
	int ch;
	bool win;
	
	while(1)
	{
        	ch = wgetch(lvlWnd/*stdscr*/);//считывание клавиши с окна уровня
        	//ch = getchar(); - альтернативный способ считывания
		switch(ch)
	//switch (tmpDirect)
		{
			case KEY_UP://65 - код стрелки вверх:
			{
				if (MoveUp(map, player, bCount, Boxs, eCount, Endpoints))
				{
					LevelOutput(lvlWnd, map, logFile, UP_MOVE, count);
					if(win = Winable(Boxs, Endpoints, bCount, eCount))
					return win;
				}
				break;
			}
			case KEY_DOWN://66:
			{
				if(MoveDown(map, player, bCount, Boxs, eCount, Endpoints))
				{
					LevelOutput(lvlWnd, map, logFile, DOWN_MOVE, count);
					if(win = Winable(Boxs, Endpoints, bCount, eCount))
					return win;
				}
				break;
			}
			case KEY_LEFT://68:
			{
				if(MoveLeft(map, player, bCount, Boxs, eCount, Endpoints))
				{
					LevelOutput(lvlWnd, map, logFile, LEFT_MOVE, count);
					if(win = Winable(Boxs, Endpoints, bCount, eCount))
					return win;
				}
				break;
			}
			case KEY_RIGHT://67:
			{
				if(MoveRight(map, player, bCount, Boxs, eCount, Endpoints))
				{
					LevelOutput(lvlWnd, map, logFile, RIGHT_MOVE, count);
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
}
