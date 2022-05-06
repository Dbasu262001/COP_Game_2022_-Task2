#include "Dog.h"
Dog::Dog(){
    direction=Dog_Stay_Still;
}

Dog::Dog(Texture* texture){
    Dog_Texture=texture;
}

Texture* Dog::Get_Dog_Texture(){
    return Dog_Texture;
} 


SDL_Rect Dog::Dog_Collider(){ //To be edited
    SDL_Rect temp={0,0,0,0};
    return temp;
}

void Dog::Dog_Update(SDL_Renderer* renderer){
Set_Dog_Nextdirection();
Dog_Pos_Update_helper(direction);
Update_Dog_Pos();
Render(renderer,Dog_Curr_Position.x,Dog_Curr_Position.y,Dog_Texture);

}

void Dog::Set_Dog_Curr_Position(int x,int y){
        Dog_Curr_Position.x=x;
        Dog_Curr_Position.y=y;
}

void Dog::Set_Dog_Next_Position(int x,int y){
    Dog_Next_Position.x=x;
    Dog_Next_Position.y=y;
}

void Dog::Dog_Pos_Update_helper(Dog_MoveDirections direction){
    switch(direction){
           case Dog_Move_Down:
           Set_Dog_Next_Position(Dog_Curr_Position.x,Dog_Next_Position.y=Dog_Curr_Position.y+10);
           break;
           case Dog_Move_Up:
           Set_Dog_Next_Position(Dog_Curr_Position.x,Dog_Next_Position.y=Dog_Curr_Position.y-10);
          
           break;
           case Dog_Move_Right:
           Set_Dog_Next_Position(Dog_Next_Position.x=Dog_Curr_Position.x+10,Dog_Curr_Position.y);
           break;
           case Dog_Move_Left:
           Set_Dog_Next_Position(Dog_Next_Position.x=Dog_Curr_Position.x-10,Dog_Curr_Position.y);
           break;
           case Dog_Stay_Still:
           Set_Dog_Next_Position(Dog_Curr_Position.x,Dog_Curr_Position.y);
           break;
           default:
           break;
       }

}

void Dog::Update_Dog_Pos(){
    if(Dog_Next_Position.x < 0 || Dog_Next_Position.y < 0 || Dog_Next_Position.x>1541 || Dog_Next_Position.y > 881){
        Dog_Next_Position.x=Dog_Curr_Position.x;
        Dog_Next_Position.y=Dog_Curr_Position.y;
        direction = Dog_Stay_Still;
    }else{
        int b_left=(Dog_Next_Position.x +10) /20;
        int b_right=(Dog_Next_Position.y+10) /20;
        int a_left=Dog_Next_Position.x/20;
        int a_right=Dog_Next_Position.y/20;
        int val =arr_D[b_right][b_left];
        int val2=arr_D[a_right][a_left];
        int val3=arr_D[a_right][b_left];
        int val4=arr_D[b_right][a_left];
        if(val==1 || val2==1 || val3==1 || val4==1){
        direction=Dog_Stay_Still;
        Dog_Next_Position.x=Dog_Curr_Position.x;
        Dog_Next_Position.y=Dog_Curr_Position.y;
        }else{
        Dog_Curr_Position.x =  Dog_Next_Position.x;
        Dog_Curr_Position.y =  Dog_Next_Position.y;
        direction = Dog_Stay_Still;
        }
    }
}

Dog_MoveDirections Dog::Get_Direction(){
    return direction;
}


void Dog::Set_Dog_Nextdirection(){
    int Random_Dir=rand() % 5;
    Random_Dir=Random_Dir+1;
    if(Random_Dir==1){
        direction=Dog_Move_Left;

    }else if(Random_Dir==2){
        direction=Dog_Move_Up;
    }else if(Random_Dir==3){
        direction=Dog_Move_Right;
    }else if(Random_Dir==4){
        direction=Dog_Move_Down;
    }else{
       direction=Dog_Stay_Still;
    }
}
void Dog::Render(SDL_Renderer* renderer,int x,int y,Texture* temp){
    SDL_Rect src_Rect={0,0,20,20};
    temp->Render(x,y,&src_Rect,0,NULL,SDL_FLIP_NONE,renderer);
}
