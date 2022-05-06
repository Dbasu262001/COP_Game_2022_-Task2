#pragma once
#include "Texture_Texture_Manager.h"

//Tile Header
class Tile{
    public:
    const static int Tile_Width=30;
    const static int Tile_Height=30;
    Tile();
    Tile(int x,int y);
    void Update_Tile_Position_in_Tile_Map(int index_x, int index_y);
    void Update_Tile_Position_in_Map(int pixel_x,int pixel_y);
    SDL_Point Tile_Position_in_Tile_Map; 
    SDL_Point Tile_Position_in_Map;
};


//Tile Management header
class Tile_Management{
    public:
    Tile_Management();
    ~Tile_Management();
    void Set_Tiles_Map_Size(int rows,int cols);
    void Erase_Map();

    void Add_Tile(int x, int y, Tile* tile);
    
    Tile* Get_Tile(int x,int y);
    int rows,cols;  
    private:
   
    map<int,Tile*> Tile_Map; 

};

