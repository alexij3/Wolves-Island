#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void menu(RenderWindow &window){
    Texture menuBackground, startTexture;
    menuBackground.loadFromFile("images/menuback.jpg");
    startTexture.loadFromFile("images/start.png");
    Sprite menuMainSprite(menuBackground), startSprite(startTexture);
    startSprite.setPosition(290, 340);

    char choice;

    while (true){

        window.clear();

        choice = '0';

        if (IntRect(290, 340, 225, 17).contains(Mouse::getPosition(window))){
            cout << "keksik\n";
            startSprite.setColor(Color::Blue);
            choice = '1';
        }

        if (Mouse::isButtonPressed(Mouse::Left)){
            if (choice == '1') break;
        }

        window.draw(menuMainSprite);
        window.draw(startSprite);

        window.display();
    }
}
