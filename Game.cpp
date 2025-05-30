#include "src/Game.h"

// #include "Game.h"


//private functions
void Game::inatializeVariables()
{
    this->endGame = false;
    this ->window = nullptr;
    this->points = 0;
    this->health = 20;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
    this->mouseHeld = false;

}

void Game::initFonts()
{
    if(this->font.loadFromFile("fonts/ARCADECLASSIC.TTF")){}
    else{
        std::cout<< "ERROR::GAME::INITFONTS::Failed to load fonts" << std::endl;
    }
}
void Game::initTexts()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");

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
    this->initFonts();
    this->initTexts();
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
        spawn enemies and set thier color and position randomly and their types
        -Random Color
        -Random Position
        -Adds enemy to vector
    */
   this->enemy.setPosition( //This is done so that the enemy does nto spawn outside the window
    static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
    // static_cast<float>(rand()%  static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
    0.f // spawn at the top of the screen

   );
   //Randomize enemy type

   int type = rand() % 5;

   switch (type)
   {
    case 0:
        this->enemy.setSize(sf::Vector2f(10.f,10.f));
        this->enemy.setFillColor(sf::Color::Magenta);
        break;
    case 1:
        this->enemy.setSize(sf::Vector2f(30.f,30.f));
        this->enemy.setFillColor(sf::Color::Blue);
        break;
    case 2:
        this->enemy.setSize(sf::Vector2f(50.f,50.f));
        this->enemy.setFillColor(sf::Color::Cyan);
        break;
    case 3:
        this->enemy.setSize(sf::Vector2f(70.f,70.f));
        this->enemy.setFillColor(sf::Color::White);
        break;
    case 4:
        this->enemy.setSize(sf::Vector2f(100.f,100.f));
        this->enemy.setFillColor(sf::Color::Green);
        break;
   
   default:
    this->enemy.setSize(sf::Vector2f(100.f,100.f));
        this->enemy.setFillColor(sf::Color::Yellow);
    break;
   }
   
   


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

void Game::updateText()
{
    std::stringstream ss;

    ss << "Points " <<this->points << "\n"
       << "Health " <<this->health << "\n";
    this->uiText.setString(ss.str());
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
                    this->enemies.erase(this->enemies.begin()+ i);

                    if(enemies[i].getFillColor() == sf::Color::Magenta)
                    {
                        this->points += 10;
                    }else if(enemies[i].getFillColor() == sf::Color::Blue)
                    {
                        this->points += 5;
                    }else if(enemies[i].getFillColor() == sf::Color::Cyan)
                    {
                        this->points += 3;
                    }else if(enemies[i].getFillColor() == sf::Color::White)
                    {
                        this->points += 2;
                    }else if(enemies[i].getFillColor() == sf::Color::Green){
                        this->points += 1;
                    }

                    //Gain Points
                    std::cout << "Points " << this->points << "\n"; 
                    //Delete the enemies
                   deleted = true;    
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

        this->updateText();
        this->updateEnemies();
    }
    //end game condition
    if (this->health <=0)
    {
        this->endGame = true;
    }
    
    
}
void Game::renderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}
void Game::renderEnemies(sf::RenderTarget& target)
{
    for(auto &e : this->enemies)
    {
            target.draw(e);// draw enemies
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

    this->renderEnemies(*this->window);

    this->renderText(*this->window);
    this->window->display();
}