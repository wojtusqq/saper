#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
MSSFMLView::MSSFMLView(MinesweeperBoard &board):board(board){}
void MSSFMLView::gameresult()
{
    sf::Font font;
    font.loadFromFile("Courier.ttf");
    if(board.getGameState()==FINISHED_LOSS)
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "saper");
        sf::Text texta;
        texta.setFont(font);
        texta.setColor(sf::Color::Black);
        texta.setCharacterSize(65);
        texta.setPosition(800/2-150, 600/2-50);
        texta.setString("P O R A Z K A");
        // program jest wlaczony, dopoki okienko jest wlaczone
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            // clear the window with black color
            window.clear(sf::Color(300,100,100));
            // draw everything here...
            // window.draw(...);
            window.draw(texta);
            // end the current frame
            window.display();
        }
    }
    else
        {
        sf::RenderWindow window(sf::VideoMode(800, 600), "saper");
        sf::Text texta;
        texta.setFont(font);
        texta.setColor(sf::Color::Black);
        texta.setCharacterSize(50);
        texta.setPosition(800/2-150, 600/2-50);
        texta.setString("Z W Y C I E S T W O");
        // program jest wlaczony, dopoki okienko jest wlaczone
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            // clear the window with black color
            window.clear(sf::Color(300,100,100));
            // draw everything here...
            // window.draw(...);
            window.draw(texta);
            // end the current frame
            window.display();
        }
        }
}
void MSSFMLView::view()
{
    sf::Font font;
    font.loadFromFile("Courier.ttf");
    int X=board.getBoardWidth();
    int Y=board.getBoardHeight();
    int size=50;
    sf::Text text[X][Y];
    sf::RenderWindow window(sf::VideoMode(X*size+2*size, Y*size+2*size), "saper");
    sf::RectangleShape plansza[X][Y];
    for(size_t i = 0; i < X; i++)
    {
        for(size_t j = 0; j < Y; j++)
        {
            plansza[i][j].setSize(sf::Vector2f(size,size));
            plansza[i][j].setPosition( i *(size+5)+2, 2 + j * 55);
            plansza[i][j].setFillColor(sf::Color::White);
            plansza[i][j].setOutlineColor(sf::Color::Yellow);
            plansza[i][j].setOutlineThickness(2.f);
        }
    }
    window.clear(sf::Color::Black);
    while(window.isOpen() && board.getGameState()==RUNNING)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
        if(event.type == sf::Event::Closed)
        {
        window.close();
        }
        {
        if (event.type == sf::Event::MouseButtonPressed)
        {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
        std::cout << "the left button was pressed" << std::endl;
        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        for(int i = 0; i <board.getBoardHeight(); i++)
        {
        for(int j = 0; j <board.getBoardWidth(); j++)
        {
        if(plansza[i][j].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
        {
        board.Reveal(i,j);
        if(board.isRevealed(i,j)==true&&board.hasMine(i,j)==false)
        {
        plansza[i][j].setFillColor(sf::Color::Green);
        text[i][j].setFont(font);
        text[i][j].setColor(sf::Color::Black);
        text[i][j].setCharacterSize(size/2);
        text[i][j].setPosition(20 + i * 55, 15 + j * 55);
        if(board.countMines(i,j)==1)
        {
        text[i][j].setString("1");
        }
        if(board.countMines(i,j)==2)
        {
        text[i][j].setString("2");
        }
        if(board.countMines(i,j)==3)
        {
        text[i][j].setString("3");
        }
        if(board.countMines(i,j)==4)
        {
        text[i][j].setString("4");
        }
        if(board.countMines(i,j)==5)
        {
        text[i][j].setString("5");
        }
        if(board.countMines(i,j)==6)
        {
        text[i][j].setString("6");
        }
        if(board.countMines(i,j)==7)
        {
        text[i][j].setString("7");
        }
        if(board.countMines(i,j)==8)
        {
        text[i][j].setString("8");
        }
        if(board.countMines(i,j)==9)
        {
        text[i][j].setString("9");
        }
        else
        {
        text[i][j].setString(" ");
        }
        }
        if(board.hasMine(i,j)==true&&board.isRevealed(i,j)==true)
        {
        board.Reveal(i,j);
        text[i][j].setString("X");
        plansza[i][j].setFillColor(sf::Color::Red);
        }
        }
        }
        }
        }
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
        if (event.mouseButton.button == sf::Mouse::Right)
        {
                        std::cout << "prawy przycisk zostal nacisniety" << std::endl;
                        std::cout << "x myszki: " << event.mouseButton.x << std::endl;
                        std::cout << "y myszki: " << event.mouseButton.y << std::endl;

        for(int i = 0; i <board.getBoardHeight(); i++)
        {
        for(int j = 0; j <board.getBoardWidth(); j++)
        {
        if(plansza[i][j].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
        plansza[i][j].setFillColor(sf::Color::Blue);
        board.toggleFlag(i,j);
        }
        }
        }
        {
        for(size_t i = 0; i < X; i++)
        {
        for(size_t j = 0; j < Y; j++)
                  {
                  window.draw(plansza[i][j]);
                  window.draw(text[i][j]);
                  }
        }
        //koniec
        window.display();
        }
        }
        }
        }
    }
}
