#include "Texture_Texture_Manager.h"

Texture::Texture(){   

    sdl_texture=NULL;
}


Texture::~Texture(){
    Clear();
}

// Deleting texture
void Texture::Clear(){
    if(sdl_texture==NULL){
        return;
    }else{
        SDL_DestroyTexture(sdl_texture);
        sdl_texture=NULL;
   
        return;
    }
}

//Loading Texture from Image
bool Texture::LoadTextureFromImage(string filename,SDL_Renderer* renderer){
    Clear();//Remove previous texture
    if(renderer==NULL)   return false;
    SDL_Surface* temp_surface=IMG_Load(filename.c_str());
    if(temp_surface==NULL) {
        cout<<"Cannot load image  %s! SDL Error: %s\n"<<filename.c_str()<<SDL_GetError()<<endl;
        return false;
    }
    sdl_texture=SDL_CreateTextureFromSurface(renderer,temp_surface);
    if(sdl_texture==NULL){
        cout<<"Cannot Create Texture From Surface  %s! SDL Error: %s\n"<<filename.c_str()<<SDL_GetError()<<endl;
    }
 
 
    SDL_FreeSurface(temp_surface); //Making the Surface free 
    return true;
}

bool Texture::LoadTextureFromRenderedText(TTF_Font* font,string text, SDL_Color color,SDL_Renderer* renderer){
     Clear();//Remove previous texture
    if(renderer==NULL)   return false;
     SDL_Surface* temp_surface=TTF_RenderText_Solid(font, text.c_str(), color);
     if(temp_surface==NULL) {
        cout<<"Could not Create Surface from rendered text  %s! SDL Error: %s\n"<<text.c_str()<<SDL_GetError()<<endl;
        return false;
    }
    sdl_texture=SDL_CreateTextureFromSurface(renderer,temp_surface);
    if(sdl_texture==NULL){
        cout<<"Cannot Create Texture From Surface  %s! SDL Error: %s\n"<<text.c_str()<<SDL_GetError()<<endl;
    }
    SDL_FreeSurface(temp_surface); //Making the Surface free 
    return true;

}

void Texture::Render(int x, int y, SDL_Rect* src_rect,const double angle, SDL_Point* center, SDL_RendererFlip render_flip,SDL_Renderer* renderer){
    if(renderer==NULL)   return;
    SDL_Rect dst_rect = { x, y,0,0 };

	if (src_rect != NULL) {
		dst_rect.w = src_rect->w;
		dst_rect.h =src_rect->h;
	}

	SDL_RenderCopyEx(renderer, sdl_texture,src_rect, &dst_rect, angle, center, render_flip);
}


void Texture_Manager::Add_Texture(Texture* texture,string key){
    Texture_List[key]=texture;
    return;
}

Texture* Texture_Manager::Get_Texture(string key){
    return Texture_List[key];
}


//erasing all the textures
void Texture_Manager::Delete_all_Textures(){
 for (auto itr = Texture_List.begin(); itr != Texture_List.end(); ++itr) {
        delete itr->second;
        Texture_List.erase(itr->first);
    }
}


//erasing a Particular Texture
void Texture_Manager::Delete_Texture(string key){
    auto itr=Texture_List.begin();
    for (auto itr = Texture_List.begin(); itr != Texture_List.end(); ++itr) {
        if(itr->first.compare(key)==0){
            delete itr->second;
            Texture_List.erase(itr->first);

        }
    }
}
Texture_Manager::Texture_Manager(){
    
}
Texture_Manager::~Texture_Manager(){
    Delete_all_Textures();
}






