#include<iostream>
using namespace std;

const int MAPX = 30;
const int MAPY = 30;

int Map[MAPX][MAPY];

class Game
{
    public:
        void init();
        void drawMap();
};

void Game::drawMap()
{
    for (int i = 0; i < MAPX; i++)
    {
        for (int j = 0; j < MAPY; j++)
        {
            cout << Map[i][j];
        }
        cout << endl;
    }
}

void Game::init() // display
{
    
    Game::drawMap();
}

class Object
{
    public:
        int x;
        int y;

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
        void move() // detect and change coordinate and map then Box::moved()
        {

        }
};



void moveit() // detect keyboard then Me::move()
{


}

int main()
{
    Game game;
    game.init();

    while(1)
    {
        moveit();
    }

    return 0;
}