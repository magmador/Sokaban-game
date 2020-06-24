struct Object
{
	int xPos;
	int yPos;
	int color_number;
};

struct Object *Boxs;
struct Object *Endpoints;
struct Object Player;

init_pair(1, COLOR_RED, COLOR_BLACK);

int main
{
	int map0[5][5] =
	{
		{1,1,1,1,1},
		{1,0,0,1,1},
		{1,0,2,0,1},
		{1,3,0,4,1},
		{1,1,1,1,1};
	}
	return 0;
}
