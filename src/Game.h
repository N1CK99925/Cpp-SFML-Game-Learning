#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
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
    //Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosview;

    //Resources
    sf::Font font;

    //Text  handles text on my ui
    sf::Text uiText;
    
    //Game Logic
    bool endGame;
    unsigned points;// Gives positive values, no negiteive values or it'll crash    
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;

    
    //Game Objects

    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    //Private Function
    void inatializeVariables();
    void initWindow();
    void initFonts();
    void initTexts();
    void initEnemies();
public:
    //Constructors and Destructors
    Game(/* args */);
    virtual  ~Game();

    //Accessors
    const bool running() const;
    const bool getEndGame() const;

    //Functions
    void spawnEnemy();
    void pollEvents();
    void updateMousePositions();
    void updateText();
    void updateEnemies();
    void update();

    void renderText(sf::RenderTarget& target);
    void renderEnemies(sf::RenderTarget& target);
    void render();
};
#endif
