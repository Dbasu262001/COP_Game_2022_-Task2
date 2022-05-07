#pragma once
#include "Tiles_Tiles_Management.h"
#include "Player.h"
#include "Dog.h"
class Game{
    public:
    Tile_Management* Tiles_M=new Tile_Management();
    Texture_Manager* Texture_M= new Texture_Manager();
    SDL_Renderer* renderer=NULL;
    SDL_Window* window=NULL;
    Game();//
    ~Game();//
    bool Initialize_Game(const char* title,int xpos,int ypos, int width,int height);//
    void close_Game();//
    bool Load_Media();//
    void Kill_Player(Player* P);

    bool Load_Media_One(const string filename,string key);//
    void Store_All_Tiles();
    bool Generate_Map();
    Player* P1=NULL;
    Dog* D2=NULL;
    Dog* D1=NULL;
    Dog* D3=NULL;
    Dog* D4=NULL;
    private:
    bool isrunning;
};