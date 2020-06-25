#include "main.h"

/*typedef struct
   {
        int xPos;
        int yPos;
        int color_number;
   } Object;

   Object *Boxs; //массив ящиков
   Object *Endpoints; //массив эндпоинтов
   Object Player; //перменная игрока*/

void Level_select(int n, int ***map)
{
	if(n==0)
	{
		int map_s[H][W] = { MAP0 };

		*map = (int **)malloc(H*sizeof(int *));
		if(*map == NULL) return;
		for(int row = 0; row < H; row++)
		{
			(*map)[row] = (int *)malloc(W*sizeof(int));                                                                                                                                                 //выделение памяти под строку
			memcpy((*map)[row],map_s[row],W*sizeof(int));
		}
	}
}

int main()
{
	int **map = NULL;
	Level_select(0, &map);
	for(int row = 0; row < H; row++)
	{
		for(int col = 0; col < W; col++)
		{
			printf("%2d ", map[row][col]);
		}
		printf("\n");
	}
	return 0;
}
