#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define Max_main_menu 4
class MainMenu
{
    //oublic class means it is acessed outside the class
    public:
    MainMenu(float width, float height);
    void draw(RenderWindow& Window);
    void MoveUp();
    void MoveDOwn();

    int MainMenuPressed(){
        return MainMenuSelected;
    }
    ~MainMenu();
    //private means its not acessed outside the class
    private:
        int MainMenuSelected;
        Font font;
        Text mainMenu[Max_main_menu];
};
