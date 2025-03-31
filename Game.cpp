#include "src/Game.h"

//private functions
void Game::inatializeVariables()
{
    this ->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    // this->videoMode.getDesktopMode;
    this ->window = new sf::RenderWindow(this->videoMode,"YouRWeapon",sf::Style::Titlebar |sf::Style::Close);
    this->window->setFramerateLimit(60); //FPS Limit
}
void Game::initEnemies()
{
    this->enemy.setPosition(10.f,10.f);
    this->enemy.setSize(sf::Vector2f(50.f,50.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}
// Constructors // Destructors
Game::Game()
{
    //Put init variable first as they have window nullptr and initWindow has a Variable assigned
    this->inatializeVariables();
    this->initWindow();
    this->initEnemies();
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
    //Update Mouse postitons
    // std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y<< std::endl;
    std::cout << "Mouse Position: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y<< std::endl;
}
void Game::render()
{   
    /*@Return Void
    - clear old frame 
    - render new objects
    -display frame in window
    Renders the game Objects  
    
    */



    this->window->clear();

    //Draw Game Objects 
    this->window->draw(this->enemy);
    this->window->display();
}