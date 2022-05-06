#include"Player.h"

Player::Player(){
direction=Stay_Still;
}
Player::Player( Texture* texture){
Player_Texture=texture;
direction=Stay_Still;
}


Player::~Player(){
Kill_Player();
}

void Player::Player_Cycle_Update(){
    if((Player_Curr_POsition.x % 20 ==0) && (Player_Curr_POsition.y % 20 ==0)){
        if(Player_has_cycle ==true && arr_P[Player_Curr_POsition.y/20][Player_Curr_POsition.x/20]==9){
            if(distance >=15){
            distance=0;
            Player_has_cycle=false;
            speed=5;
            player_check=15;
            }
        }else if(Player_has_cycle==false && arr_P[Player_Curr_POsition.y/20][Player_Curr_POsition.x/20]==9){
            if(distance==0 && calm>15){
            Player_has_cycle=true;
            speed=10;
            player_check=10;
            calm =0;
            }
        }

    }
}

void Player::Render(SDL_Renderer* renderer,int x,int y,Texture* temp){
    SDL_Rect src_Rect={0,0,20,20};
    temp->Render(x,y,&src_Rect,0,NULL,SDL_FLIP_NONE,renderer);
}


void Player::Go(SDL_Renderer* Re){
   Update(direction);
   Update_Position();
   Player_Cycle_Update();
   if(Player_has_cycle==true && distance < 50) distance=distance + 5;
   if(distance==0 && calm <50) calm=calm+5;
   Render(Re,Player_Curr_POsition.x,Player_Curr_POsition.y,Player_Texture);
}
void Player::Update(MoveDirections direction){
       switch(direction){
           case Move_Down:
           set_NextPos(Player_Curr_POsition.x, Player_Next_Position.y=Player_Curr_POsition.y+speed);
           break;
           case Move_Up:
           set_NextPos(Player_Curr_POsition.x, Player_Next_Position.y=Player_Curr_POsition.y-speed);
           break;
           case Move_Right:
           set_NextPos(Player_Next_Position.x=Player_Curr_POsition.x+speed,Player_Curr_POsition.y);
           break;
           case Move_Left:
           set_NextPos(Player_Next_Position.x=Player_Curr_POsition.x-speed,Player_Curr_POsition.y);
           break;
           case Stay_Still:
           set_NextPos(Player_Curr_POsition.x,Player_Curr_POsition.y);
           break;
           default:
           break;
       }
}

void Player::Update_Position(){
    Update(direction);
    if(Player_Next_Position.x < 0 || Player_Next_Position.y <0 || Player_Next_Position.x > 1541 || Player_Next_Position.y >881 ){
        Player_Next_Position.x =Player_Curr_POsition.x;
        Player_Next_Position.y= Player_Curr_POsition.y;
        direction = Stay_Still;
    }else{
        int b_left=(Player_Next_Position.x +player_check)/20;
        int b_right=(Player_Next_Position.y+player_check)/20;
        int a_left=Player_Next_Position.x/20;
        int a_right=Player_Next_Position.y/20;
        int val =arr_P[b_right][b_left];
        int val2=arr_P[a_right][a_left];
        int val3=arr_P[a_right][b_left];
        int val4=arr_P[b_right][a_left];
        if(val==1 || val2==1 || val3==1 || val4==1){
        Player_Next_Position.x =Player_Curr_POsition.x;
        Player_Next_Position.y= Player_Curr_POsition.y;
        direction = Stay_Still;
        }else if(direction!=Stay_Still){
            Player_Curr_POsition.x=Player_Next_Position.x;
            Player_Curr_POsition.y=Player_Next_Position.y;
            direction = Stay_Still;

        }
        direction=Stay_Still;
    }

}


void Player::set_NextPos(int x,int y){
    Player_Next_Position.x=x;
    Player_Next_Position.y=y;
}
void Player::set_Curr_Pos(int x,int y){
    Player_Curr_POsition.x=x;
    Player_Curr_POsition.y=y;
}

void Player::Kill_Player(){

}

void Player::Player_Score_Update(int x){
    this->score=this->score+x;

    }
int Player::Get_Player_Score(){
    return this->score;
}

SDL_Rect Player::Collider(){
return this->collider;
}

SDL_Point Player::Player_Position(){


}
   
void Player::Player_Events(SDL_Event* event){

    if(event->type==SDL_KEYDOWN){
        if(event->key.keysym.sym==SDLK_UP){           
            direction=Move_Up;

        }else if(event->key.keysym.sym==SDLK_DOWN){
           direction=Move_Down;
        }else if(event->key.keysym.sym==SDLK_RIGHT){
            direction=Move_Right;
        }else if(event->key.keysym.sym==SDLK_LEFT){
            direction=Move_Left;
        }
    
    }
   
}

bool Check_Player_Collision(const SDL_Rect &Other_Collider){

}