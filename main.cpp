#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>
#include <time.h>
#include "Animal.h"
#include "Wolf.h"
#include "Wolfess.h"
#include "Rabbit.h"
#include "TheWolves.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>

using namespace std;
using namespace sf;

Sprite background;

RenderWindow window(VideoMode(768,768), "Wolves Island");

void menu(){
    window.setActive(true);
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
            if (choice == '1'){
                cout << "batman\n";
                window.clear();
                window.setActive(false);
                break;
        }
        }

        window.draw(menuMainSprite);
        window.draw(startSprite);

        window.display();
    }
    }

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

bool freeCell(char island[][21], int X, int Y, int choice){
    if (choice == 0){
        if (island[X][Y] == 'r' || island[X][Y] == '.') return true;
        else return false;
    }

    if (choice == 1){
        if (island[X][Y] == 'f' || island[X][Y] == 'r' || island[X][Y] == 'C' || island[X][Y] == '.') return true;
        else return false;
    }

    return 0;
}

bool isThereAFreeCell(char island[][21], int X, int Y, int choice) {
    if (choice == 0){
        if (X != 0 && Y != 0 && freeCell(island, X-1, Y-1, choice)) return true;

        else if (X != 0 && freeCell(island, X-1, Y, choice)) return true;
        else if (X != 0 && Y != 19 && freeCell(island, X-1, Y+1, choice)) return true;
        else if (Y != 19 && freeCell(island, X, Y+1, choice)) return true;
        else if (X != 19 && Y != 19 && freeCell(island, X+1, Y+1, choice)) return true;
        else if (X != 19 && freeCell(island, X+1, Y, choice)) return true;
        else if (X != 19 && Y != 0 && freeCell(island, X+1, Y-1, choice)) return true;
        else if (Y != 0 && freeCell(island, X, Y-1, choice)) return true;
    }

    if (choice == 1) {
        if (X != 0 && Y != 0 && freeCell(island, X-1, Y-1, choice)) return true;

        else if (X != 0 && freeCell(island, X-1, Y, choice)) return true;
        else if (X != 0 && Y != 19 && freeCell(island, X-1, Y+1, choice)) return true;
        else if (Y != 19 && freeCell(island, X, Y+1, choice)) return true;
        else if (X != 19 && Y != 19 && freeCell(island, X+1, Y+1, choice)) return true;
        else if (X != 19 && freeCell(island, X+1, Y, choice)) return true;
        else if (X != 19 && Y != 0 &&freeCell(island, X+1, Y-1, choice)) return true;
        else if (Y != 0 && freeCell(island, X, Y-1, choice)) return true;

    }
    else if (choice == 2){
        if (X != 0 && Y != 0 && (island[X-1][Y-1] == 'f' || island[X-1][Y-1] == 'w')) return true;

        else if (X != 0 && (island[X-1][Y] == 'f' || island[X-1][Y] == 'w' || island[X-1][Y] == '.')) return true;
        else if (X != 0 && Y != 19 && (island[X-1][Y+1] == 'f' || island[X-1][Y+1] == 'w' || island[X-1][Y+1] == '.')) return true;
        else if (Y != 19 && (island[X][Y+1] == 'f' || island[X][Y+1] == 'w' || island[X][Y+1] == '.')) return true;
        else if (X != 19 && Y != 19 && (island[X+1][Y+1] == 'f' || island[X+1][Y+1] == 'w' || island[X+1][Y+1] == '.')) return true;
        else if (X != 19 && (island[X+1][Y] == 'f' || island[X+1][Y] == 'w' || island[X+1][Y] == '.')) return true;
        else if (X != 19 && Y != 0 && (island[X+1][Y-1] == 'f' || island[X+1][Y-1] == 'w' || island[X+1][Y-1] == '.')) return true;
        else if (Y != 0 && (island[X][Y-1] == 'f' || island[X][Y-1] == 'w' || island[X][Y-1] == '.')) return true;

    }

    else if (choice == 3){
        if (X != 0 && Y != 0 && island[X-1][Y-1] == '.') return true;

        else if (X != 0 && island[X-1][Y] == '.') return true;
        else if (X != 0 && Y != 19 && island[X-1][Y+1] == '.') return true;
        else if (Y != 19 && island[X][Y+1] == '.') return true;
        else if (X != 19 && Y != 19 && island[X+1][Y+1] == '.') return true;
        else if (X != 19 && island[X+1][Y] == '.') return true;
        else if (X != 19 && Y != 0 && island[X+1][Y-1] == '.') return true;
        else if (Y != 0 && island[X][Y-1] == '.' ) return true;
    }

    return false;
}

void Born(vector <Rabbit> &rabbits, char island[][21], int number){
    for (int i = 0; i < number; i++){
        rabbits.push_back(Rabbit(island));
    }
}

void Born(vector <Wolf> &wolves, char island[][21], int number){
    for (int i = 0; i < number; i++){
        wolves.push_back(Wolf(island));
    }
}

void Born(vector <Wolfess> &wolfess, char island[][21], int number){
    for (int i = 0; i < number; i++){
        wolfess.push_back(Wolfess(island));
    }
}

void Birth(vector <Rabbit> &rabbits, char island[][21], int X, int Y){
    int r;
    cout << "cheeki\n";
    while (true) {
        r = rand()%8;
        switch(r) {
            case 0: {
                if (X != 0 && Y != 0 && island[X-1][Y-1] == '.'){
                    rabbits.push_back(Rabbit(X-1, Y-1, island));
                    return;
                }
                else break;
            }
            case 1: {
                if (X != 0 && island[X-1][Y] == '.'){
                    rabbits.push_back(Rabbit(X-1, Y, island));
                    return;
                }
                else break;
            }
            case 2: {
                if (X != 0 && Y != 19 && island[X-1][Y+1] == '.'){
                    rabbits.push_back(Rabbit(X-1, Y+1, island));
                    return;
                }
                else break;
            }
            case 3: {
                if (Y != 19 && island[X][Y+1] == '.'){
                    rabbits.push_back(Rabbit(X, Y+1, island));
                    return;
                }
                else break;
            }
            case 4: {
                if (X != 19 && Y != 19 && island[X+1][Y+1] == '.'){
                    rabbits.push_back(Rabbit(X+1, Y+1, island));
                    return;
                }
                else break;
            }
            case 5: {
                if (X != 19 && island[X+1][Y] == '.'){
                    rabbits.push_back(Rabbit(X+1, Y, island));
                    return;
                }
                else break;
            }
            case 6: {
                if (X != 19 && Y != 0 && island[X+1][Y-1] == '.'){
                    rabbits.push_back(Rabbit(X+1, Y-1, island));
                    return;
                }
                else break;
            }
            case 7: {
                if (Y != 0 && island[X][Y-1] == '.'){
                    rabbits.push_back(Rabbit(X, Y-1, island));
                    return;
                }
                else break;
            }
        }
    }
}

void Birth(vector <Wolfess> &wolfess, vector <Wolf>&wolves, char island[][21], int X, int Y){
    int r;
    while (true) {
        r = rand()%8;
        switch(r) {
            case 0: {
                if (X != 0 && Y != 0 && island[X-1][Y-1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X-1, Y-1, island));
                    else wolves.push_back(Wolf(X-1, Y-1, island));
                    return;
                }
                else break;
            }
            case 1: {
                if (X != 0 && island[X-1][Y] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X-1, Y, island));
                    else wolves.push_back(Wolf(X-1, Y, island));
                    return;
                }
                else break;
            }
            case 2: {
                if (X != 0 && Y != 19 && island[X-1][Y+1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X-1, Y+1, island));
                    else wolves.push_back(Wolf(X-1, Y+1, island));
                    return;
                }
                else break;
            }
            case 3: {
                if (Y != 19 && island[X][Y+1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X, Y+1, island));
                    else wolves.push_back(Wolf(X, Y+1, island));
                    return;
                }
                else break;
            }
            case 4: {
                if (X != 19 && Y != 19 && island[X+1][Y+1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X+1, Y+1, island));
                    else wolves.push_back(Wolf(X+1, Y+1, island));
                    return;
                }
                else break;
            }
            case 5: {
                if (X != 19 && island[X+1][Y] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X+1, Y, island));
                    else wolves.push_back(Wolf(X+1, Y, island));
                    return;
                }
                else break;
            }
            case 6: {
                if (X != 19 && Y != 0 && island[X+1][Y-1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X+1, Y-1, island));
                    else wolves.push_back(Wolf(X+1, Y-1, island));
                    return;
                }
                else break;
            }
            case 7: {
                if (Y != 0 && island[X][Y-1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X, Y-1, island));
                    else wolves.push_back(Wolf(X, Y-1, island));
                    return;
                }
                else break;
            }
        }
    }
}

void refreshMap(Sprite &sMap){

    window.setActive(true);
    window.clear();
    window.draw(background);
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < HEIGHT; j++){
            if (island[i][j] == '.') sMap.setTextureRect(IntRect(224, 0, 32, 32));
            //else if (island[i][j] == 'W') sMap.setTextureRect(IntRect(256, 0, 32, 32));
            //else if (island[i][j] == 'S') sMap.setTextureRect(IntRect(288, 0, 32, 32));
            else if (island[i][j] == 'w') sMap.setTextureRect(IntRect(0, 0, 32, 32));
            else if (island[i][j] == 'f') sMap.setTextureRect(IntRect(32, 0, 32, 32));
            else if (island[i][j] == 'r') sMap.setTextureRect(IntRect(64, 0, 32, 32));
            else if (island[i][j] == 'B') sMap.setTextureRect(IntRect(96, 0, 32, 32));
            else if (island[i][j] == 'K') sMap.setTextureRect(IntRect(128, 0, 32, 32));
            else if (island[i][j] == 'C') sMap.setTextureRect(IntRect(160, 0, 32, 32));
            else if (island[i][j] == 'A') sMap.setTextureRect(IntRect(192, 0, 32, 32));

            sMap.setPosition((j+2)*32, (i+2)*32);
            window.draw(sMap);
        }
    }
    window.display();
    window.setActive(false);
}

void w_playSound(int wf_size, int w_fixed_size, int w_size, vector <Wolfess>&wolfess){
    if (wf_size < wolfess.size()){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/wolf_fidget.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(3000);
    }
    else if (w_fixed_size < w_size){
        SoundBuffer buffer;
        buffer.loadFromFile("sounds/wolf_fidget.wav");
        Sound sound(buffer);
        sound.play();
        Sleep(3000);
    }
}

int main() {
    Image icon;
    icon.loadFromFile("images/icon.png");
    window.setIcon(32, 32, icon.getPixelsPtr());

    window.setActive(false);
    menu();
    srand(time(NULL));
    ShowConsoleCursor(false);
    system("color F9");

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            cout << island[i][j] << " ";
        }
        cout << endl;
    }
    vector<Wolf> wolves;
    vector <Wolfess> wolfess;
    vector<Rabbit> rabbits;

    Born(wolves, island, 15);
    Born (wolfess, island, 15);
    Born(rabbits, island, 20);

    Texture tMap, bgrt;
    tMap.loadFromFile("images/map3.png");
    bgrt.loadFromFile("images/background.png");
    Sprite sMap;
    sMap.setTexture(tMap);
    background.setTexture(bgrt);

    Thread graphicsThread(&refreshMap, sMap);

    cout << "Wolves: " << wolves.size() << endl;
    cout << "Rabbits: " << rabbits.size() << endl;
    for (int i = 0; i < wolves.size(); i++){
        cout << "Wolf " << i << ": " << "X = " << wolves[i].getX() << ", Y = " << wolves[i].getY() << endl;
    }

    window.setActive(true);
        //_getch();
        Sleep(300);
        refreshMap(sMap);
        window.setActive(false);
    Music music;
    music.openFromFile("sounds/music.wav");
    music.play();
    music.setVolume(5);
    music.setLoop(true);
    while (window.isOpen()){
    system("cls");
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            cout << island[i][j] << " ";
        }
        cout << endl;
    }
       int w_fixed_size = wolves.size();
       int w_size = wolves.size();
       int wf_size = wolfess.size();
       int r_size = rabbits.size();
        for (int i = 0; i < w_size; i++) {
            if (isThereAFreeCell(island, wolves[i].getX(), wolves[i].getY(), 1) && wolves[i].getPoints() != 0) {
                wolves[i].doStep(rabbits, wolfess, island);
                if (wolves[i].isReadyToGiveLife)
                    if (isThereAFreeCell(island, wolves[i].getX(), wolves[i].getY(), 3) && rabbits.size() + wolfess.size() + wolves.size() != 400){
                        Birth(wolfess, wolves, island, wolves[i].getX(), wolves[i].getY());
                        wolves[i].isReadyToGiveLife = false;
                    }
            if (wolves[i].getPoints() == 0){
                    cout << "Wolf dies on " << wolves[i].getX() << " " << wolves[i].getY() << "\n";
                    island[wolves[i].getX()][wolves[i].getY()] = '.';
                    wolves.erase(wolves.begin() + i);
                    w_size--;
                    i--;
                }
            }
            graphicsThread.launch();
        }
        //_getch();
        //window.clear();
        //refreshMap(sMap);
        //graphicsThread.launch();
        //Sleep(300);
        //window.display();

        if (r_size > rabbits.size()){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/rabbit_death.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(600);
        }

        if (w_fixed_size > w_size){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/wolf_death.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(1200);
        }

        if (wf_size < wolfess.size()){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/wolf_fidget.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(3000);
        }
        else if (w_fixed_size < w_size){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/wolf_fidget.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(3000);
        }

        if (rabbits.size() == 0){
                cout << "The wolves have eaten all the rabbits!\n";
                Font font;
                font.loadFromFile("fonts/impact.ttf");
                Text text("THE WOLVES HAVE EATEN ALL THE RABBITS!", font, 40);
                text.setColor(Color::White);
                text.setStyle(Text::Underlined);
                text.setPosition(50, 350);
                graphicsThread.launch();
                window.draw(text);
                window.display();
                cout << "THE WOLVES HAVE EATEN ALL THE RABBITS!\n";
                music.stop();
                _getch();
                window.close();
                break;
        }

        r_size = rabbits.size();
        for (int i = 0; i < r_size; i++) {
            if (isThereAFreeCell(island, rabbits[i].getX(), rabbits[i].getY(), 2)) {
                rabbits[i].doStep(rabbits, island);
                if (rabbits[i].isReadyToGiveLife){
                    if (isThereAFreeCell(island, rabbits[i].getX(), rabbits[i].getY(), 3) && rabbits.size() + wolfess.size() + wolves.size() != 400){
                        Birth(rabbits, island, rabbits[i].getX(), rabbits[i].getY());
                    }
                }
            }
            graphicsThread.launch();
        }
        //_getch();
        //window.clear();
        //refreshMap(sMap);
        //window.display();

        //graphicsThread.launch();
        //Sleep(300);

        if (r_size < rabbits.size()){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/rabbit_birth.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(600);
        }

        r_size = rabbits.size();
        wf_size = wolfess.size();
        w_fixed_size = wolves.size();
        int wf_fixed_size = wf_size;
        for (int i = 0; i < wf_size; i++){
            if (isThereAFreeCell(island, wolfess[i].getX(), wolfess[i].getY(), 0)) {
                wolfess[i].doStep(rabbits, wolves, island);
                if (wolfess[i].isReadyToGiveLife){
                    if (isThereAFreeCell(island, wolfess[i].getX(), wolfess[i].getY(), 3) && rabbits.size() + wolfess.size() + wolves.size() != 400){
                        Birth(wolfess, wolves, island, wolfess[i].getX(), wolfess[i].getY());
                        wolfess[i].isReadyToGiveLife = false;
                }
                }
            }
            if (wolfess[i].getPoints() == 0){
                cout << "Wolfess dies on " << wolfess[i].getX() << " " << wolfess[i].getY() << "\n";
                island[wolfess[i].getX()][wolfess[i].getY()] = '.';
                wolfess.erase(wolfess.begin() + i);
                wf_size--;
                i--;
            }
            graphicsThread.launch();
        }
        //_getch();
        //window.clear();
        //refreshMap(sMap);
        //window.display();

        //graphicsThread.launch();
        //Sleep(300);

        if (r_size > rabbits.size()){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/rabbit_death.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(600);
        }

        if (wf_size < wf_fixed_size){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/wolf_death.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(1200);
        }

        if (wf_size < wolfess.size()){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/wolf_fidget.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(3000);
        }
        else if (w_fixed_size < wolves.size()){
            SoundBuffer buffer;
            buffer.loadFromFile("sounds/wolf_fidget.wav");
            Sound sound(buffer);
            sound.play();
            Sleep(3000);
        }

        if (rabbits.size() == 0){
                Font font;
                font.loadFromFile("fonts/impact.ttf");
                Text text("THE WOLVES HAVE EATEN ALL THE RABBITS!", font, 40);
                text.setColor(Color::White);
                text.setStyle(Text::Underlined);
                text.setPosition(50, 350);
                graphicsThread.launch();
                window.draw(text);
                window.display();
                cout << "THE WOLVES HAVE EATEN ALL THE RABBITS!\n";
                music.stop();
                _getch();
                window.close();
                break;
        }

        if (wolves.size() + wolfess.size() == 0){
                Font font;
                font.loadFromFile("fonts/impact.ttf");
                Text text("ALL THE WOLVES ARE DEAD!", font, 65);
                text.setColor(Color::White);
                text.setStyle(Text::Underlined);
                text.setPosition(50, 320);
                graphicsThread.launch();
                window.draw(text);
                window.display();
                cout << "All the wolves are dead!\n";
                music.stop();
                _getch();
                window.close();
                break;
        }

        cout << "Wolves: " << wolves.size() << endl;
        cout << "Wolfess: " << wolfess.size() << endl;
        cout << "Rabbits: " << rabbits.size() << endl;

        Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
    }
        _getch();
        return 0;
}
