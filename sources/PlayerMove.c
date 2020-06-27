#include "main.h"

bool PlayerMove(WINDOW *lvlWnd, int **map, Object* player, size_t bCount, Object* Boxs, size_t eCount, Object* Endpoints, FILE *logFile, size_t count)
{
	int mapStart[MAP_ROW_COUNT][MAP_COL_COUNT] = { MAP1 };
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
		               count = 0;
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
				if(!PlayerInit(player, map, PLAYER_MAP_OBJ))
				{
					fprintf(logFile, "'%s': Can't Restart initialize object Player\n", __FUNCTION__);
					exit(1);
				}
				else
				{
					fprintf(logFile, "'%s': Restart Object Player successfully initialized\n", __FUNCTION__);
					fprintf(logFile, "%d:%d \n", player->yPos, player->xPos);
				}
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
