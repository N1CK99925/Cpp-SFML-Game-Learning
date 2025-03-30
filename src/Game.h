#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
/*
Class that acts as the game engine
Wrapper Class 
*/

class Game
{
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    //Private Function
    void inatializeVariables();
    void initWindow();
public:
    //Constructors and Destructors
    Game(/* args */);
    virtual  ~Game();

    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();
    void render();
    void update();
};
#endif
