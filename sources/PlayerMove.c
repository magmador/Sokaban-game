#include "main.h"

bool PlayerMove(WINDOW *lvlWnd, int **map, Object* Player, size_t bCount, Object* Boxs, size_t eCount, Object* Endpoints, FILE *logFile, size_t turnCount)
{
	int mapStart[MAP_ROW_COUNT][MAP_COL_COUNT] = { MAP1 };
	bool win;
	
    int inputKey = getchar();
	switch(inputKey)
	{
		/* Код стрелки вверх */
		case KEY_ARROW_UP:
		{
			if (MoveUp(map, Player, bCount, Boxs, eCount, Endpoints))
			{
				turnCount++;
				LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		/* Код стрелки вниз */
		case KEY_ARROW_DOWN:
		{
			if(MoveDown(map, Player, bCount, Boxs, eCount, Endpoints))
			{
				turnCount++;
				LevelOutput(lvlWnd, map, logFile, DOWN_MOVE, turnCount);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		/* Код стрелки влево */
		case KEY_ARROW_LEFT:
		{
			if(MoveLeft(map, Player, bCount, Boxs, eCount, Endpoints))
			{
				turnCount++;
				LevelOutput(lvlWnd, map, logFile, LEFT_MOVE, turnCount);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		/* Код стрелки вправо */
		case KEY_ARROW_RIGHT:
		{
			if(MoveRight(map, Player, bCount, Boxs, eCount, Endpoints))
			{
				turnCount++;
				LevelOutput(lvlWnd, map, logFile, RIGHT_MOVE, turnCount);
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		case 'R':
		case 'r':
			free(Boxs);
			free(Endpoints);
		    turnCount = 0;
			//ObjectInitialization(bCount, Boxs, logFile, eCount, Endpoints, map, Player);	
			LevelOutput(lvlWnd, map, logFile, UP_MOVE, turnCount);
		    break;
		case 'q':
		{
		    endwin();
		    exit(1);
		    break;
		}
		default:
		{
			/* Нажатие любой другой кнопки, помимо кнопок движения должно игнорироваться */
		}
	}
}
