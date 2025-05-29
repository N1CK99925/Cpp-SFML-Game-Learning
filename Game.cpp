#include "src/Game.h"
// #include "Game.h"


//private functions
void Game::inatializeVariables()
{
    this->endGame = false;
    this ->window = nullptr;
    this->points = 0;
    this->health = 10;
    this->enemySpawnTimer = 0.f;
    this->enemySpawnTimerMax = 10.f;
    this->maxEnemies = 5;
    this->mouseHeld = false;

}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    // this->videoMode.getDesktopMode;
    this ->window = new sf::RenderWindow(this->videoMode,"Game 1",sf::Style::Titlebar |sf::Style::Close);
    this->window->setFramerateLimit(60); //FPS Limit
}
void Game::initEnemies()
{
    this->enemy.setPosition(10.f,10.f);
    this->enemy.setSize(sf::Vector2f(50.f,50.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    // this->enemy.setOutlineColor(sf::Color::Green);
    // this->enemy.setOutlineThickness(1.f);


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

const bool Game::getEndGame() const
{
    return this->endGame;
}
// functions
void Game::spawnEnemy()
{
    /*
     @Return Void 
        spawn enemies and set thier color and position
        -Random Color
        -Random Position
        -Adds enemy to vector
    */
   this->enemy.setPosition( //This is done so that the enemy does nto spawn outside the window
    static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
    // static_cast<float>(rand()%  static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
    0.f // spawn at the top of the screen

   );
   this->enemy.setFillColor(sf::Color::Green);
   //spawn the enemy
   this->enemies.push_back(this->enemy); // push back enemy back to the vector
}

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

void Game::updateMousePositions()
{
    /*
    @Return Void 

    update Mouse Positions
     mouse Position relative to window (vector2i)
    */
   this->mousePosWindow =sf::Mouse::getPosition(*this->window);
   this->mousePosview = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{   //Updating timer for enemy spawn
    //Moves the enemies downwo=ards
    //Moves the enemy to the edge of the screen // TODO

    if(this->enemies.size()<= this->maxEnemies){

    if (this->enemySpawnTimer >= this->enemySpawnTimerMax){
        this->spawnEnemy();
        this->enemySpawnTimer = 0.f;
    } else{
        this->enemySpawnTimer += 1.f;
    }
}
// Move the enemies and update the enemies
for(int i =0; i< this->enemies.size(); i++)
{   
    bool deleted = false;
    this->enemies[i].move(0.f,3.f);// draw enemies
    //If enemy is past the bottom of the screen
    if(this->enemies[i].getPosition().y > this->window->getSize().y)
    {
    this->enemies.erase(this->enemies.begin()+ i);
    this->health -= 1;
    std::cout << "Health " << this->health << "\n";
    }
    
}
//check if clicked upon
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(this->mouseHeld == false)
        {   
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
            {
                if(this->enemies[i].getGlobalBounds().contains(this->mousePosview)){
              //Delete the enemies
             deleted = true;    
                this->enemies.erase(this->enemies.begin()+ i);
                //Gain Points
                this->points += 1.f;
                std::cout << "Points " << this->points << "\n"; 
            }
            }
        }
        
    }else {
        this->mouseHeld= false;
    }
}

void Game::update()
{   
    this->pollEvents();
    if (this->endGame == false)
    {
        
        
        this-> updateMousePositions();
        this->updateEnemies();
    }
    //end game condition
    if (this->health <=0)
    {
        this->endGame = true;
    }
    
    
}
void Game::renderEnemies()
{
    for(auto &e : this->enemies)
    {
        this->window->draw(e);// draw enemies
    }
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

    this->renderEnemies();
    this->window->display();
}