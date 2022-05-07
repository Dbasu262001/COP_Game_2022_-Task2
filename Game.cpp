#include "Game.h"

Game::Game(){
    isrunning=true;
}
//Initialize the SDL_Game
bool Game::Initialize_Game(const char* title,int xpos,int ypos, int width,int height){//Initilaizing SDL_Game
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout<<"SDL is  initialised"<<endl;
        window =SDL_CreateWindow(title,xpos,ypos,width,height, SDL_WINDOW_SHOWN);
        if(window){
            cout<<"Window is Created"<<endl;
        
            renderer =SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer){
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                SDL_RenderPresent( renderer );
                cout<<"Renderer is Created"<<endl;
                isrunning=true;
            }else{
                cout<<"Failed to Create SDL_Renderer ! SDL_Error : "<< SDL_GetError()<<endl;
                isrunning=false;
                return false;
            }
           
        }else{
            cout<<"Failed to Create SDL_Window ! SDL_Error : "<< SDL_GetError()<<endl;
            isrunning=false;
            return false;
        }
    }else{
        cout<<"SDL_Cannot be Initilaised ! SDL_Error : "<< SDL_GetError()<<endl;
        isrunning=false;
        return false;
    }
    return true;
}
//Load a media_File
bool Game::Load_Media_One(const string filename,string key){
    Texture* templ =new Texture();
    templ->LoadTextureFromImage(filename,renderer);
    Texture_M->Add_Texture(templ,key);
    if(templ==NULL) return false;
    templ=NULL;
    return true;
}
void Game::Store_All_Tiles(){
    Tiles_M->Set_Tiles_Map_Size(30,52);
    for(int i=0;i<30;i++){
        for(int j=0;j<52;j++){
            Tile* temp =new Tile(i,j);
             Tiles_M->Add_Tile(i,j,temp);
        }
    }

}

bool Game::Load_Media(){//Load all the required Media_Files
Load_Media_One("Paint/Paints/Blue.png","Blue");
Load_Media_One("Paint/Paints/Red.png","Red");
Load_Media_One("Paint/Paints/Brown.png","Wall");
Load_Media_One("Paint/Paints/Green.png","Green");
Load_Media_One("Paint/Paints/Silver.png","Silver");
Load_Media_One("Paint/Paints/anime1.png","anime");
Load_Media_One("Paint/Hospital.png","Hospital");

Load_Media_One("Paint/Indraprashtha.png","Indrap");
Load_Media_One("Paint/Taxilla_Apart.png","Taxilla");
Load_Media_One("Paint/Vaishali.png","Vaishali");
Load_Media_One("Paint/Vikramsila.png","Vikram");
Load_Media_One("Paint/Hospital.png","Hospital");

Load_Media_One("Paint/Library.png","Library");
Load_Media_One("Paint/Main_Building.png","Main_Building");
Load_Media_One("Paint/Bharti_Building.png","Bharti_Building");
Load_Media_One("Paint/Academic_area.png","Academic_area");
Load_Media_One("Paint/Buildings.png","Buildings");
Load_Media_One("Paint/Blank_Brown.png","Blank_Brown");

Load_Media_One("Paint/DOD.png","DOD");
Load_Media_One("Paint/Indoor_Sports.png","Indoor_Sports");
Load_Media_One("Paint/IRD_Hostel.png","IRD_Hostel");
Load_Media_One("Paint/LHC.png","LHC");
Load_Media_One("Paint/Research_Park.png","Research_Park");
Load_Media_One("Paint/sac_oat.png","sac_oat");
Load_Media_One("Paint/Amaltus.png","Amaltus");
Load_Media_One("Paint/Block99.png","Block99");
Load_Media_One("Paint/IIT_Market.png","IIT_Market");
Load_Media_One("Paint/Gulmohar.png","Gulmohar");



Load_Media_One("Grounds/grass_30.png","grass");
Load_Media_One("Grounds/yulu.png","Yulu");
Load_Media_One("Grounds/ground_N.png","ground_N");
Load_Media_One("Grounds/green_ground.png","green_ground");

Load_Media_One("Grounds/lawn.png","lawn");


Load_Media_One("Hostels/Aravali.png","Aravali");
Load_Media_One("Hostels/Girnar.png","Girnar");
Load_Media_One("Hostels/Himadri.png","Himadri");
Load_Media_One("Hostels/Jwala.png","Jwala");
Load_Media_One("Hostels/Kailash.png","Kailash");
Load_Media_One("Hostels/Kumaon.png","Kumaon");
Load_Media_One("Hostels/Nilgiri.png","Nilgiri");
Load_Media_One("Hostels/Satpura.png","Satpura");
Load_Media_One("Hostels/Shivalik.png","Shivalik");
Load_Media_One("Hostels/Udaigiri.png","Udaigiri");
Load_Media_One("Hostels/Vindhyachal.png","Vindhyachal");
Load_Media_One("Hostels/Zanskar.png","Zanskar");
Load_Media_One("Hostels/Karakoram.png","Kara");
Load_Media_One("Hostels/Nalanda.png","Nalanda");



}


void Game::Kill_Player(Player* PL){
    PL = NULL;
}
bool Game::Generate_Map(){
    int arr[30][52]={ 
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  
                        
                           };
int arr2[45][78]={
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,4,4,4,4,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,1},
                        {1,1,1,1,4,4,4,4,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1},
                        {1,1,1,1,4,4,4,4,1,1,0,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1},
                        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,0,0},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,9},
                        {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

                        
    };

    SDL_Rect SpriteClips[2];
    SpriteClips[0].x=0;
    SpriteClips[0].y=0;
    SpriteClips[0].w=30;
    SpriteClips[0].h=30;
    SpriteClips[1].x=0;
    SpriteClips[1].y=0;
    SpriteClips[1].w=20;
    SpriteClips[1].h=20;
   // Tiles_M->Erase_Map();
    
    for(int i=0;i<30;i++){
        for(int j=0;j<52;j++){
            SDL_Rect renderQuad = { j*30, i*30, 30, 30 };
            Tile* temp =Tiles_M->Get_Tile(i,j);
            temp->Update_Tile_Position_in_Map(j*30,i*30);
            temp->Update_Tile_Position_in_Tile_Map(i,j);
            
            
            Texture* temp_T =Texture_M->Get_Texture("grass");
            temp_T->Render(temp->Tile_Position_in_Map.x,temp->Tile_Position_in_Map.y,&SpriteClips[0],0,NULL,SDL_FLIP_NONE,renderer);
            
           
        }
    }

    for(int i=0;i<45;i++){
        for(int j=0;j<78;j++){
            SDL_Rect renderQuad = { j*20, i*20, 20, 20 };
            if(arr2[i][j]==0){
            Texture* temp_T =Texture_M->Get_Texture("Wall");
             temp_T->Render(j*20,i*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
            }

        }
    }
    SpriteClips[1].w=30;
    SpriteClips[1].h=20;
    Texture* Yulu=Texture_M->Get_Texture("Yulu");
    Yulu->Render(8.5*20,1*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Yulu->Render(8.5*20,23*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Yulu->Render(34.5*20,15*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Yulu->Render(54*20,15*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Yulu->Render(60.5*20,0*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Yulu->Render(76.8*20,24.5*20,&SpriteClips[1],90,NULL,SDL_FLIP_NONE,renderer);


    SpriteClips[1].w=90;
    SpriteClips[1].h=60;
    Texture* Hostel=NULL;
    Hostel=Texture_M->Get_Texture("Jwala");
    Hostel->Render(4*20,2*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Kumaon");
    Hostel->Render(12*20,1*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Aravali");
    Hostel->Render(4*20,7*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Kara");
    Hostel->Render(4*20,12*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Nilgiri");
    Hostel->Render(4*20,17*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Vindhyachal");
    Hostel->Render(18.5*20,2*20,&SpriteClips[1],90,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Satpura");
    Hostel->Render(23.5*20,2.5*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Shivalik");
    Hostel->Render(19.5*20,7.3*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Hostel=Texture_M->Get_Texture("Zanskar");
    Hostel->Render(22.5*20,10.7*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    SpriteClips[1].w=80;
    SpriteClips[1].h=50;
    Hostel=Texture_M->Get_Texture("Nalanda");
    Hostel->Render(12*20,22*20,&SpriteClips[1],90,NULL,SDL_FLIP_NONE,renderer);
    



    SpriteClips[1].w=60;
    SpriteClips[1].h=60;
    Texture* Hospital = Texture_M->Get_Texture("Hospital");
    Hospital->Render(33*20,10.5*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);


    SpriteClips[1].w=100;
    Texture* Ground = Texture_M->Get_Texture("ground_N");
    Ground->Render(11.5*20,15*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
   
    SpriteClips[1].w=320;
    SpriteClips[1].h=180;
     Ground = Texture_M->Get_Texture("green_ground");
    Ground->Render(31*20,16*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    
    SpriteClips[1].w=75;
    SpriteClips[1].h=60;
     Ground = Texture_M->Get_Texture("Indoor_Sports");
    Ground->Render(40*20,22*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    



    SpriteClips[1].h=55;
    SpriteClips[1].w=90;
    Texture* Apartment=Texture_M->Get_Texture("Indrap");
    Apartment->Render(0*20,17*20,&SpriteClips[1],90,NULL,SDL_FLIP_NONE,renderer);
    Apartment=Texture_M->Get_Texture("Vaishali");
    SpriteClips[1].h=60;
    Apartment->Render(0*20,25*20,&SpriteClips[1],90,NULL,SDL_FLIP_NONE,renderer);
    Apartment=Texture_M->Get_Texture("Vikram");
    Apartment->Render(4*20,32*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Apartment=Texture_M->Get_Texture("Taxilla");
    Apartment->Render(4*20,37*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=50;
    SpriteClips[1].w=50;
    Apartment=Texture_M->Get_Texture("Library");
    Apartment->Render(50*20,11*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    Apartment=Texture_M->Get_Texture("Bharti_Building");
    Apartment->Render(43*20,11*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    
    SpriteClips[1].h=126;
    SpriteClips[1].w=180;
    Apartment=Texture_M->Get_Texture("Academic_area");
    Apartment->Render(44.5*20,1.3*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);
    SpriteClips[1].h=33;
    SpriteClips[1].w=75;
    Apartment=Texture_M->Get_Texture("Blank_Brown");
    Apartment->Render(53.5*20,1.3*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=70;
    SpriteClips[1].w=70;
    Apartment=Texture_M->Get_Texture("Main_Building");
    Apartment->Render(50*20,6*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=60;
    SpriteClips[1].w=100;
    Apartment=Texture_M->Get_Texture("lawn");
    Apartment->Render(55*20,4.7*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=150;
    SpriteClips[1].w=90;
    Apartment=Texture_M->Get_Texture("Buildings");
    Apartment->Render(36.2*20,6*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    // 
    SpriteClips[1].h=60;
    SpriteClips[1].w=60;
    Apartment=Texture_M->Get_Texture("Gulmohar");
    Apartment->Render(15.6*20,22.5*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=160;
    SpriteClips[1].w=100;
    Apartment=Texture_M->Get_Texture("sac_oat");
    Apartment->Render(19.7*20,16.5*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=120;
    SpriteClips[1].w=120;
    Apartment=Texture_M->Get_Texture("DOD");
    Apartment->Render(50*20,16*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=140;
    SpriteClips[1].w=160;
    Apartment=Texture_M->Get_Texture("LHC");
    Apartment->Render(56.5*20,13*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=60;
    SpriteClips[1].w=90;
    Apartment=Texture_M->Get_Texture("Block99");
    Apartment->Render(58.5*20,9.5*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);


    SpriteClips[1].h=60;
    SpriteClips[1].w=90;
    Apartment=Texture_M->Get_Texture("Himadri");
    Apartment->Render(61.7*20,3*20,&SpriteClips[1],90,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=60;
    SpriteClips[1].w=90;
    Apartment=Texture_M->Get_Texture("Kailash");
    Apartment->Render(65*20,1*20,&SpriteClips[1],90,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=60;
    SpriteClips[1].w=58;
    Apartment=Texture_M->Get_Texture("Amaltus");
    Apartment->Render(73.05*20,3.5*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=60;
    SpriteClips[1].w=60;
    Apartment=Texture_M->Get_Texture("IIT_Market");
    Apartment->Render(72*20,10.5*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=60;
    SpriteClips[1].w=60;
    Apartment=Texture_M->Get_Texture("IRD_Hostel");
    Apartment->Render(58*20,22*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);

    SpriteClips[1].h=60;
    SpriteClips[1].w=90;
    Apartment=Texture_M->Get_Texture("Research_Park");
    Apartment->Render(34*20,28*20,&SpriteClips[1],0,NULL,SDL_FLIP_NONE,renderer);






















}


void Game::close_Game(){
    // Tiles_M->Erase_Map();
    SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
    renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}