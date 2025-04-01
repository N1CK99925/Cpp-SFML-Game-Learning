#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
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
    
    //Game Logic
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    int points;

    
    //Game Objects

    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    //Private Function
    void inatializeVariables();
    void initWindow();
    void initEnemies();
public:
    //Constructors and Destructors
    Game(/* args */);
    virtual  ~Game();

    //Accessors
    const bool running() const;

    //Functions
    void spawnEnemy();
    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();
    void renderEnemies();
    void render();
};
#endif
