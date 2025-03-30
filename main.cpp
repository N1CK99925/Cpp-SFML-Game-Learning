#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main( ) {
   sf::RenderWindow window(sf::VideoMode(640,480),"YouRWeapon",sf::Style::Titlebar |sf::Style::Close);
   sf::Event ev;
   //Game Loop
   while (window.isOpen())
   {
    //event polling
    while(window.pollEvent(ev)){
        switch(ev.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
            if(ev.key.code == sf::Keyboard::Escape);
             window.close();
            break;    
        }
    }
    //Update
    //Render
    window.clear(sf::Color::Blue); //Clear old frame
    //Here you draw your game

    window.display();// Tell the window that app is done drawing

   }
    //End of application
    return 0;
    
}

