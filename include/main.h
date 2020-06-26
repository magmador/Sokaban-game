#include <ncurses.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAP_ROW_COUNT 10
#define MAP_COL_COUNT 10
#define ROW_MAP_SIZE MAP_ROW_COUNT * sizeof(int *)
#define COL_MAP_SIZE MAP_COL_COUNT * sizeof(int)
#define MAP0 \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1, 1, 0, 0, 0, 0, 0, 0, 1,-1}, \
	{-1, 1, 2, 0, 0, 2, 1, 1, 1,-1}, \
	{-1, 1, 3, 0, 4, 3, 0, 0, 1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}

#define MAP1 \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1, 1, 0, 0, 0, 0, 0, 0, 1,-1}, \
	{-1, 1, 0, 0, 2, 0, 1, 1, 1,-1}, \
	{-1, 1, 0, 0, 4, 0, 0, 3, 1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}

typedef struct
   {
        int xPos;
        int yPos;
        int color_number;
   } Object;

void LevelOutput(int **map); //вывод карты уровня
bool LevelSelect(int levelNumber, int ***map); //функция выбора уровня из пресета карт
