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
		    turnCount = 0;
		    if(!LevelSelect(LEVEL_1, &map))
			{
				fprintf(logFile, "'%s': Restart Level not loaded\n", __FUNCTION__);
				exit(1);
			}
			else
			{
				fprintf(logFile, "'%s': Restart Level successfully loaded\n", __FUNCTION__);
			}
			if(!ObjInit(&bCount, &Boxs, map, BOX_MAP_OBJ))
			{
				fprintf(logFile, "'%s': Can't Restart initialize object Boxs\n", __FUNCTION__);
				exit(1);
			}
			else
			{
				fprintf(logFile, "'%s': Restart Object Boxs successfully initialized\n", __FUNCTION__);
				for(size_t i = 0; i < bCount; i++) fprintf(logFile, "%d:%d ", Boxs[i].yPos, Boxs[i].xPos);
				fprintf(logFile, "\n");
			}
			if(!ObjInit(&eCount, &Endpoints, map, ENDPOINT_MAP_OBJ))
			{
				fprintf(logFile, "'%s': Can't Restart initialize object Endpoints\n", __FUNCTION__);
				exit(1);
			}
			else
			{
				fprintf(logFile, "'%s': Restart Object Endpoints successfully initialized\n", __FUNCTION__);
				for(size_t i = 0; i < bCount; i++) fprintf(logFile, "%d:%d ", Endpoints[i].yPos, Endpoints[i].xPos);
				fprintf(logFile, "\n");
			}
			if(!PlayerInit(Player, map, PLAYER_MAP_OBJ))
			{
				fprintf(logFile, "'%s': Can't Restart initialize object Player\n", __FUNCTION__);
				exit(1);
			}
			else
			{
				fprintf(logFile, "'%s': Restart Object Player successfully initialized\n", __FUNCTION__);
				fprintf(logFile, "%d:%d \n", Player->yPos, Player->xPos);
			}
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
