#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

#define isKeyPressed(nVirtKey) (GetKeyState(nVirtKey) & (1<<(sizeof(SHORT)*8-1))) != 0

const int MAPX = 30;
const int MAPY = 30;
const int ME = 1;
const int AIR = 0;

struct Coor
{
	int x;
	int y;
};

int Map[MAPX+5][MAPY+5];

int keyState();
void gotoxy(short x,short y);

class Object
{
    public:
        int x;
        int y;
	Coor getcoor()
	{
		Coor coor;
		coor.x = x;
		coor.y = y;
		return coor;
	}
        
};

class Box: public Object
{
    public:
        void moved() // change coordinate and map then display()
        {
            
        }
};

class Me: public Object
{
    public:    
        void move(int); // detect and change coordinate and map then Box::moved()
        void setcoor(int cor_x, int cor_y)
        {
            Map[cor_x][cor_y] = ME;
            this->x = cor_x;
            this->y = cor_y;
        }
		void moveaway()
		{
			Map[this->x][this->y] = AIR;
		}
};
Me me;

void Me::move(int dir)
{
	Me::moveaway();
	if (dir == 1)
		Me::setcoor(getcoor().x-1, getcoor().y);
}

class Game
{
    public:
        void drawMap();
        void readMap();
		void moveit();
		Game();
};


void Game::drawMap()
{
	gotoxy(0,0);
    for (int i = 1; i <= MAPX; i++)
    {
        for (int j = 1; j <= MAPY; j++)
        {
            cout << Map[i][j];
        }
        cout << endl;
    }
	cout << endl;
}

void Game::readMap()
{
    fstream mapfile;
    mapfile.open("./bin/map.txt", ios::in | ios::out);
    for (int i = 1; i <= MAPX; i++)
    {
        for (int j = 1; j <= MAPY; j++)
        {
            // mapfile << Map[i][j];
            mapfile >> Map[i][j];
        }
        // mapfile << endl;
    }

    mapfile.close();
}

void Game::moveit()
{
	me.move(keyState());
	Game::drawMap();
}

Game::Game() // display
{
    Game::readMap();
    me.setcoor(MAPX/2, MAPY/2);

    Game::drawMap();
}

int main()
{
    Game game;

    while(1)
    {
        game.moveit();
		Sleep(200);
    }

    cin.get();

    return 0;
}

int keyState()
{
	while(1)
	{
		if (isKeyPressed('W'))
			return 1;
		if (isKeyPressed('S'))
			return 2;
		if (isKeyPressed('A'))
			return 3;
		if (isKeyPressed('D'))
			return 4;
		Sleep(5);
	}
}

void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}