#include<vector>
#include<SFML/Graphics.hpp>

class Board
{
    unsigned int x;
    std::vector<std::vector<sf::RectangleShape>> field;
    std::vector<std::vector<bool>> occupied;
    sf::Color background[2];
public:
    Board(int x);
    void draw(sf::RenderWindow& window);
    void setOccupied(int x, int y) { occupied[x][y] != occupied[x][y];}
    bool getOccupied(int x, int y) { return occupied[x][y]; }
    unsigned int getX() { return x; }
};

class Apple
{
    sf::CircleShape circle;
    unsigned int x,y;
public:
    Apple(int x, int y, Board& b);
    void draw(sf::RenderWindow& window);
    unsigned int getX() { return x;}
    unsigned int getY() { return y;}
    void setPosition(int x, int y, Board& b);
};

class Snake
{
    std::vector<sf::CircleShape> body;
    int dir=4;
    int x,y; //position of head of the snake
public:
    Snake(Board& b);
    void draw(sf::RenderWindow& window);
    void add();
    int getdir() { return dir; } 
    void setdir(int i) { dir=i; }
    int getX() {return x;}
    int getY() {return y;}
    void move(Board& b);
    bool collision(int x, int y, Board& b)
{
    for(int i=0;i<body.size();i++)
    {
        if((720/b.getX()*x==body[i].getPosition().x)&&(720/b.getX()*y==body[i].getPosition().y)) 
        return true;
    }
    return false;
}
    bool selfcollision(Board& b)
 {
    for(int i=1;i<body.size();i++)
    {
        if((720/b.getX()*x==body[i].getPosition().x)&&(720/b.getX()*y==body[i].getPosition().y)) 
        return true;
    }
    return false;
}
};
