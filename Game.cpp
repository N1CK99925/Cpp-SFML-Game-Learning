#include "src/Game.h"
//private functions
void Game::inatializeVariables()
{
    this ->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 800;
    this->videoMode.width = 600;
    // this->videoMode.getDesktopMode;
    this ->window = new sf::RenderWindow(this->videoMode,"YouRWeapon",sf::Style::Titlebar |sf::Style::Close);
}
//Constructors // Destructors
Game::Game()
{
    //Put init variable first as they have window nullptr and initWindow has a Variable assigned
    this->inatializeVariables();
    this->initWindow();
}

Game::~Game()
{

    delete this->window;
}
// Accessors
const bool Game::running() const
{
    
    return this->window->isOpen();
}

// functions
void Game::pollEvents()
{
    //Event Polling
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape);
             this->window->close();
            break;    
        }
    }
}


void Game::update()
{   
    this->pollEvents();
}
void Game::render()
{   
    /*@Return Void
    - clear old frame 
    - render new objects
    -display frame in window
    Renders the game Objects  
    
    */



    this->window->clear(sf::Color(255,0,0,255));
    //Draw Game Objects 
    this->window->display();
}