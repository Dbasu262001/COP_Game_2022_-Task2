#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Texture{
    public:
    Texture();
	~Texture();

    //loading texture from  image file (png)
    bool LoadTextureFromImage(string filename,SDL_Renderer* renderer);

    //loading texture from rendered text
    bool LoadTextureFromRenderedText(TTF_Font* font,string text, SDL_Color text_color,SDL_Renderer* renderer);//not req

    // Rendering  the texture
	void Render(int x, int y,SDL_Rect* clip,const double angle, SDL_Point* center, SDL_RendererFlip render_flip,SDL_Renderer* renderer);


    void Clear();
    SDL_Texture* sdl_texture;

};


class Texture_Manager{
    public:
    Texture_Manager();
    //Storing  texture in a ordered map
    void Add_Texture(Texture* texture,string key);


    //  Get Texture from the map
    Texture* Get_Texture(string key);

    // Deleting the all the textures

    void Delete_all_Textures();
    
    //Deleting a specific texture
    void Delete_Texture(string key);

    ~Texture_Manager();
    private:
        map<string,Texture*> Texture_List;

};

