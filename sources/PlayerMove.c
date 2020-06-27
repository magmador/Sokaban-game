#include "main.h"

bool PlayerMove(WINDOW *lvlWnd, int **map, Object* player, size_t bCount, Object* Boxs, size_t eCount, Object* Endpoints, FILE *logFile, size_t count)
{
	int ch;
	bool win;
	
	while(1)
	{
        	ch = getchar();
		switch(ch)
		{
			case 65:// - код стрелки вверх:
			{
				if (MoveUp(map, player, bCount, Boxs, eCount, Endpoints))
				{
					count++;
					LevelOutput(lvlWnd, map, logFile, UP_MOVE, count);
					if(win = Winable(Boxs, Endpoints, bCount, eCount))
					return win;
				}
				break;
			}
			case 66:
			{
				if(MoveDown(map, player, bCount, Boxs, eCount, Endpoints))
				{
					count++;
					LevelOutput(lvlWnd, map, logFile, DOWN_MOVE, count);
					if(win = Winable(Boxs, Endpoints, bCount, eCount))
					return win;
				}
				break;
			}
			case 68:
			{
				if(MoveLeft(map, player, bCount, Boxs, eCount, Endpoints))
				{
					count++;
					LevelOutput(lvlWnd, map, logFile, LEFT_MOVE, count);
					if(win = Winable(Boxs, Endpoints, bCount, eCount))
					return win;
				}
				break;
			}
			case 67:
			{
				if(MoveRight(map, player, bCount, Boxs, eCount, Endpoints))
				{
					count++;
					LevelOutput(lvlWnd, map, logFile, RIGHT_MOVE, count);
					if(win = Winable(Boxs, Endpoints, bCount, eCount))
					return win;
				}
				break;
			}
			case 'r':
			    LevelOutput(lvlWnd, map, logFile, UP_MOVE, count);
			    break;
			case 'q':
			    endwin();
			    exit(1);
			    break;
			default:
			{
				/* Нажатие любой другой кнопки, помимо кнопок движения должно игнорироваться */
			}
		}
	}
}
