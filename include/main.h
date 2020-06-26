#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef MAIN_H
#define MAIN_H 

#define NOT_PL_SPACE_MAP_OBJ -1
#define WALL_MAP_OBJ 1
#define SPACE_MAP_OBJ 0
#define BOX_MAP_OBJ 2
#define ENDPOINT_MAP_OBJ 3
#define PLAYER_MAP_OBJ 4

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
bool PlayerMove(char* direct, int **map, Object* player, size_t oCount, Object* boxs, size_t eCount, Object* endpoints); //функция передвижения персонажа
bool LevelSelect(int levelNumber, int ***map); //выбор уровня из пресета карт
bool ObjInit(size_t *objCount, Object **Objs, int **map, int obj); //инициализация массива объектов (obj - цифра с map, см. define в main.h)
bool PlayerInit(Object *Player, int **map, int obj); //инициализация объекта игрока.
bool MoveUp(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints); //Движение вверх
bool MoveDown(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints); //Движение вниз
bool MoveLeft(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints); //Движение влево
bool MoveRight(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints); //Движение вправо
bool Winable(Object *Boxs, Object *Endpoints, size_t bCount, size_t eCount);
#endif
