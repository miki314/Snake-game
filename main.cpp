#include<iostream>
#include<SFML/Graphics.hpp>
#include"classes.h"
#include<random>

int main()
{
    sf::RenderWindow window(sf::VideoMode(720,720), "Snake");
    window.setFramerateLimit(8);

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,12);

    Board board(13);
    Apple apple(1,7, board);
    Snake snake(board);

    int counter = 4;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(snake.getdir() != 1)) snake.setdir(3);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(snake.getdir() != 3)) snake.setdir(1);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(snake.getdir() != 2)) snake.setdir(0);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(snake.getdir() != 0)) snake.setdir(2);

        if(apple.getX()==snake.getX()&&apple.getY()==snake.getY())
        {
            do
            {
                apple.setPosition(distribution(generator),distribution(generator),board);
            } while (snake.collision(apple.getX(),apple.getY(),board));
            
            snake.add();
        }

        if(snake.getX()<0||snake.getY()<0||snake.getX()>12||snake.getY()>12||snake.selfcollision(board)) //game over condition
            break;

        if(counter==4)
        {
            counter=0;
            window.clear();
            board.draw(window);
            apple.draw(window);

            snake.move(board);
            snake.draw(window);        
            window.display();
        }
        counter++;
    }

    //After you lose, snake disappears from the screen
    window.clear();
    board.draw(window);
    apple.draw(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
    

    return 0;
}
