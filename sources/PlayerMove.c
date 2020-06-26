#include "main.h"

bool PlayerMove(char* direct, int **map, Object* player, size_t bCount, Object* Boxs, size_t eCount, Object* Endpoints)
{
	/* Заменить при отрисовке графики на нажатие клавиши */
	int tmpDirect = 0;
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
	}
	
	bool win;
	switch (tmpDirect)
	{
		case 1:
		{
			if (MoveUp(map, player, bCount, Boxs, eCount, Endpoints))
			{
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		case 2:
		{
			if(MoveDown(map, player, bCount, Boxs, eCount, Endpoints))
			{
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		case 3:
		{
			if(MoveLeft(map, player, bCount, Boxs, eCount, Endpoints))
			{
				if(win = Winable(Boxs, Endpoints, bCount, eCount))
				return win;
			}
			break;
		}
		case 4:
		{
			if(MoveRight(map, player, bCount, Boxs, eCount, Endpoints))
			{
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