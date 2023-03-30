#include"classes.h"
#include<vector>
#include<math.h>

Board::Board(int x)
{
    this->x=x;
    background[0] = sf::Color(0,255,85);
    background[1] = sf::Color(26,153,0);
    for(int i=0;i<x;i++)
    {
        std::vector<sf::RectangleShape> temp;
        std::vector<bool> b;
        for(int j=0;j<x;j++)
        {
            sf::RectangleShape r_temp(sf::Vector2f(720/x,720/x));
            r_temp.setFillColor(background[(i+j)%2]);
            r_temp.setPosition(720/x*i,720/x*j);
            temp.push_back(r_temp);

            bool b1 = false;
            b.push_back(b1);
        }
        field.push_back(temp);
        occupied.push_back(b);
    }
}

void Board::draw(sf::RenderWindow& window)
{
    for(int i=0;i<x;i++)
        for (int j = 0; j < x; j++)
            window.draw(field[i][j]);
}

Apple::Apple(int x, int y, Board& b)
{
    this->x = x;
    this->y = y;
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(720/b.getX()*x,720/b.getX()*y);
    circle.setRadius(360/b.getX());
    b.setOccupied(x,y);
}

void Apple::draw(sf::RenderWindow& window)
{
    window.draw(circle);
}

void Apple::setPosition(int x, int y, Board& b)
{
    this->x = x;
    this->y = y;
    circle.setPosition(720/b.getX()*x,720/b.getX()*y);
}

Snake::Snake(Board& b)
{
    dir=1;
    x=2;
    y=5;
    for(int i=0;i<3;i++)
    {
        sf::CircleShape c;
        c.setFillColor(sf::Color(body.size(),body.size(),255-body.size()));
        c.setRadius(360/b.getX());
        c.setPosition(720/b.getX()*(x-i),720/b.getX()*y);
        body.push_back(c);
    }
}

void Snake::draw(sf::RenderWindow& window)
{
    for(int i=0;i<body.size();i++) window.draw(body[i]);
}

void Snake::move(Board& b)
{
    for(int i=body.size()-1;i>0;i--)
    {
        body[i].setPosition(body[i-1].getPosition());
    }

    switch(dir)
    {
        case 0: //down
            y--;
        break;
        case 1: //left
            x++;
        break; 
        case 2: //up
            y++;
        break;
        case 3: //right
            x--;
        break;
    }

    body[0].setPosition(720/b.getX()*x,720/b.getX()*y);
}

void Snake::add()
{
    body.push_back(body[0]);
    body[body.size()-1].setPosition(body[body.size()-2].getPosition());
    body[body.size()-1].setFillColor(sf::Color(body.size(),body.size(),255-body.size()));
}

