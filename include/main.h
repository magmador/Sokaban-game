#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

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
#define MENU_X_OPPONENT	   35
#define MULTI_MENU_COLS 20
#define MULTI_MENU_ROWS 10
#define MULTI_MENU_Y 5
#define MULTI_MENU_X 2
#define MENU_TITLE "SOKABAN THE GAME"
#define MENU_SIN   "PRESS 'S' FOR NEW SINGLE GAME"
#define MENU_MULTI "PRESS 'M' FOR MULTIPLAYER"
#define MENU_EXIT  "PRESS 'Q' FOR EXIT"
#define MULTI_MENU_TITLE "CHOOSE YOUR SIDE:"
#define MULTI_MENU_CLIENT "C - CLINET"
#define MULTI_MENU_SERVER "S - SERVER"
#define LVL_CLEAR  "LEVEL CLEAR!"
#define PRESS_KEY  "PRESS ANY KEY..."
#define MSG_FROM_CLIENT "CONNECT"
#define MSG_TO_CLIENT "SUCCESS"

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
#define MAP_SIZE 	  MAP_ROW_COUNT * MAP_COL_COUNT * sizeof(int)

#define LVL_WIN_COLS MAP_COL_COUNT + 10
#define LVL_WIN_ROWS MAP_ROW_COUNT + 5

#define UP_MOVE    ACS_UARROW
#define DOWN_MOVE  ACS_DARROW
#define LEFT_MOVE  ACS_LARROW
#define RIGHT_MOVE ACS_RARROW

#define SINGLE_PLAYER_FLAG 26
#define MULTI_PLAYER_FLAG  27
#define QUIT_FLAG 		   28

#define SERVER_PORT 2222
#define CLIENT_PORT 2223

#define LEVEL_COUNT 3

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

#define LEVEL_3 3
#define MAP3 \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, \
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
	{ 1, 1, 1, 1, 1, 3, 1, 1, 1, 1}, \
	{ 1, 1, 1, 1, 0, 2, 1, 1, 1, 1}, \
	{ 1, 1, 1, 1, 0, 0, 0, 2, 4, 1}, \
	{ 1, 1, 1, 3, 0, 2, 2, 3, 1, 1}, \
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, \
	{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 1}, \
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

/* Стурктура игрового объекта */
typedef struct
   {
        int xPos;
        int yPos;
   } Object;

/* Структура сетевого буфера */
typedef struct
   {
	   int **map;
	   bool win;
	   int levelNumber;
   } NetworkBuffer;
    
/* Инициализация ncurses */
void InitCurses();
/* Вывод карты уровня */
void LevelOutput(WINDOW *lvlWnd, int **map, FILE *logFile, const chtype move, size_t count, size_t levelCur);
/* Функция выбора уровня из пресета карт */
bool LevelSelect(int levelNumber, int ***map);
/* Функция передвижения персонажа */
bool PlayerMove(WINDOW *lvlWnd, int **map, Object *player, size_t oCount, Object *boxs, size_t eCount, Object *endpoints, FILE *logFile, size_t *turnCount, bool *restart, int levelCur);
/* Выбор уровня из пресета карт */
bool LevelSelect(int levelNumber, int ***map);
/* Инициализация массива объектов */
bool ObjInit(size_t *objCount, Object **Objs, int **map, int obj);
/* Инициализация объекта игрока */
bool PlayerInit(Object *Player, int **map, int obj);
/* Движение вверх */
bool MoveUp(int **map, Object *player, size_t bCount, Object *boxs, size_t eCount, Object *endpoints);
/* Движение вниз */
bool MoveDown(int **map, Object *player, size_t bCount, Object *boxs, size_t eCount, Object *endpoints);
/* Движение влево */
bool MoveLeft(int **map, Object *player, size_t bCount, Object *boxs, size_t eCount, Object *endpoints);
/* Движение вправо */
bool MoveRight(int **map, Object *player, size_t bCount, Object *boxs, size_t eCount, Object *endpoints); 
/* Проверка условия локальной победы */
bool Winable(Object *Boxs, Object *Endpoints, size_t bCount, size_t eCount);  
/* Отрисовка меню */
void DrawMenu(WINDOW *menuWnd); 
/* Выбор пунктов в меню */
int PickMenu(WINDOW *menuWnd); 
/* Инициализация объектов */
void ObjectInitialization(size_t *boxCount, Object **Boxs, FILE *logFile, size_t *endpointCount, Object **Endpoints, int ***map, Object *Player, int lvlNumber, size_t *turnCount);
/* Инициализация сокета */
bool NetworkInit(int *socket_fd, bool server_init, FILE *logFile);
/* Соединение между клиентом и сервером */
bool NetworkConnect(int *socket_fd, struct sockaddr_in *addr, bool server_init, FILE *logFile);
/* Вывод карты уровня оппонента в мультиплеере */
void LevelMultiplayerOutput(WINDOW *lvl2Wnd, int **map, FILE *logFile, const chtype move, size_t count, size_t levelCur);
/* Удаление основного меню */
void DeleteMenu(WINDOW *menuWnd);
/* Отрисовка меню выбора в мультиплеере */
void DrawMultiplayerMenu();
/* Функция игры в синглплеере */
void SinglePlayer(WINDOW *lvlWnd, int **map, Object Player, size_t bCount, Object *Boxs, size_t eCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[]);
/* Функция выбора режима в мультиплеере */
void MultiPlayer(WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t bCount, Object *Boxs, size_t eCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[]);
/* Функция игры в качестве клиента */
void MultiPlayerClient(int *socket_fd, struct sockaddr_in *addr, WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t boxCount, Object *Boxs, size_t endpointCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[]);
/* Функция игры в качестве сервера */
void MultiPlayerServer(int *socket_fd, struct sockaddr_in *addr, WINDOW *lvlWnd, WINDOW *lvl2Wnd, int **map, Object Player, size_t boxCount, Object *Boxs, size_t endpointCount, Object *Endpoints, FILE *logFile, size_t turnCount, bool restart, int Levels[]);
/* Функция выделения памяти под map в структуре сетевого буфера */
bool InitNetBufferMap(int ***map);
#endif
