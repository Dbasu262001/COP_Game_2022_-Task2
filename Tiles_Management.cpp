#include "Tiles_Tiles_Management.h"
Tile_Management::Tile_Management(){
  rows=cols=0;
}
Tile_Management::~Tile_Management(){
    Erase_Map();
    rows=cols=0;
}

void Tile_Management::Erase_Map(){
     auto itr=Tile_Map.begin();
   for (auto itr = Tile_Map.begin(); itr != Tile_Map.end(); ++itr) {
        delete itr->second;
        Tile_Map.erase(itr->first);
    }
   
}
void Tile_Management::Set_Tiles_Map_Size(int row,int col){
        rows=row;
        cols=col;
    return;
}

void Tile_Management::Add_Tile(int x, int y, Tile* tile){
  Tile_Map[x*cols+y]=tile;
}

Tile* Tile_Management::Get_Tile(int x,int y){
 if(x<0 || y<0 || x>=rows || y>=cols) {
    return NULL;
 }
 return Tile_Map[x*cols+y];

}
