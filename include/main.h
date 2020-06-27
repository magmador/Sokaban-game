#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef MAIN_H
#define MAIN_H 

#define LOGFILE    "./log/sokaban.log"

#define KEY_ARROW_UP 	65
#define KEY_ARROW_DOWN 	66
#define KEY_ARROW_LEFT	68
#define KEY_ARROW_RIGHT 67

#define MENU_COLS  50
#define MENU_ROWS  25
#define MENU_X	   5
#define MENU_Y	   2
#define MENU_TITLE "SOKABAN THE GAME"
#define MENU_SIN   "PRESS 'S' FOR NEW SINGLE GAME"
#define MENU_MULTI "PRESS 'M' FOR MULTIPLAYER"
#define MENU_EXIT  "PRESS 'Q' FOR EXIT"


#define NOT_PL_SPACE_MAP_OBJ -1
#define SPACE_MAP_OBJ 		  0
#define WALL_MAP_OBJ 		  1
#define BOX_MAP_OBJ 		  2
#define ENDPOINT_MAP_OBJ 	  3
#define PLAYER_MAP_OBJ 		  4

#define MAP_ROW_COUNT 10
#define MAP_COL_COUNT 10
#define ROW_MAP_SIZE  MAP_ROW_COUNT * sizeof(int *)
#define COL_MAP_SIZE  MAP_COL_COUNT * sizeof(int)

#define UP_MOVE ACS_UARROW
#define DOWN_MOVE ACS_DARROW
#define LEFT_MOVE ACS_LARROW
#define RIGHT_MOVE ACS_RARROW

#define LEVEL_1 1
#define MAP1 \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1, 1, 0, 0, 0, 0, 0, 0, 1,-1}, \
	{-1, 1, 2, 0, 0, 2, 1, 1, 1,-1}, \
	{-1, 1, 3, 0, 4, 3, 0, 0, 1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}

#define LEVEL_2 2
#define MAP2 \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1, 1, 0, 0, 0, 0, 0, 0, 1,-1}, \
	{-1, 1, 0, 0, 2, 0, 1, 1, 1,-1}, \
	{-1, 1, 0, 0, 4, 0, 0, 3, 1,-1}, \
	{-1, 1, 1, 1, 1, 1, 1, 1, 1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}

/* Стурктура игрового объекта */
typedef struct
   {
        int xPos;
        int yPos;
        int color_number;
   } Object;

/* Вывод карты уровня */
void LevelOutput(WINDOW *lvlWnd, int **map, FILE *logFile, const chtype move, size_t count);
/* Функция выбора уровня из пресета карт */
bool LevelSelect(int levelNumber, int ***map);
/* Функция передвижения персонажа */
bool PlayerMove(WINDOW *lvlWnd, int **map, Object* player, size_t oCount, Object* boxs, size_t eCount, Object* endpoints, FILE *logFile, size_t count);
/* Выбор уровня из пресета карт */
bool LevelSelect(int levelNumber, int ***map);
/* Инициализация массива объектов */
bool ObjInit(size_t *objCount, Object **Objs, int **map, int obj);
/* Инициализация объекта игрока */
bool PlayerInit(Object *Player, int **map, int obj);
/* Движение вверх */
bool MoveUp(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints);
/* Движение вниз */
bool MoveDown(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints);
/* Движение влево */
bool MoveLeft(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints);
/* Движение вправо */
bool MoveRight(int **map, Object* player, size_t bCount, Object* boxs, size_t eCount, Object* endpoints); 
/* Проверка условия локальной победы */
bool Winable(Object *Boxs, Object *Endpoints, size_t bCount, size_t eCount);  
/* Отрисовка меню */
void DrawMenu(WINDOW *menuWnd); 
/* Выбор пунктов в меню */
void PickMenu(WINDOW *menuWnd); 
/* Инициализация объектов */
void ObjectInitialization(size_t boxCount, Object **Boxs, FILE *logFile, size_t endpointCount, Object **Endpoints, int **map, Object *Player);


#endif
