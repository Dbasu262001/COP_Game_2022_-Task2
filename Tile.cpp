#include "Tiles_Tiles_Management.h"

Tile::Tile(){
    Tile_Position_in_Tile_Map={0,0};
}

Tile::Tile(int x,int y){
    Tile_Position_in_Tile_Map={x,y};
    Tile_Position_in_Map={y*Tile_Width,x*Tile_Height};
}
    

void Tile::Update_Tile_Position_in_Tile_Map(int x, int y){
   Tile_Position_in_Tile_Map ={x,y};
}
void Tile::Update_Tile_Position_in_Map(int x , int y){
    Tile_Position_in_Map={x,y};
}
