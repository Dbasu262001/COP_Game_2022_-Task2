#pragma once
#include "Game.h"

Game* G1=new Game();


int main(){

bool Init=G1->Initialize_Game("SDL_Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1560,900);

SDL_Surface* surface=SDL_GetWindowSurface(G1->window);
SDL_Event e;
bool quit=false;
G1->Load_Media();
G1->Store_All_Tiles();
G1->P1=new Player(G1->Texture_M->Get_Texture("Player_1"));

G1->P1->set_Curr_Pos(80,80);
G1->P1->Render(G1->renderer,G1->P1->Player_Curr_POsition.x,G1->P1->Player_Curr_POsition.y,G1->P1->Player_Texture);
G1->D1=new Dog(G1->Texture_M->Get_Texture("Red"));
G1->D1->Set_Dog_Curr_Position(20*8,29*20);

//Set do position
G1->D1->Dog_Update(G1->renderer);
G1->D2=new Dog(G1->Texture_M->Get_Texture("Red"));
G1->D3=new Dog(G1->Texture_M->Get_Texture("Red"));
G1->D4=new Dog(G1->Texture_M->Get_Texture("Red"));
G1->D5=new Dog(G1->Texture_M->Get_Texture("Red"));

G1->D2->Set_Dog_Curr_Position(18*20,7.5*20);
G1->D3->Set_Dog_Curr_Position(50*20,14*20);
G1->D4->Set_Dog_Curr_Position(60*20,7*20);
G1->D5->Set_Dog_Curr_Position(15*20,14*20);


G1->D2->Dog_Update(G1->renderer);
G1->D3->Dog_Update(G1->renderer);
G1->D4->Dog_Update(G1->renderer);
G1->D5->Dog_Update(G1->renderer);

SDL_RenderPresent(G1->renderer);
while( !quit )
			{
               	
				
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0)
				{
			
               
                
                  
					
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
                        break;
					}else {
				SDL_RenderClear(G1->renderer);
                G1->Generate_Map();

					
                       if(e.type==SDL_KEYDOWN && G1->P1!=NULL){
						    G1->D1->Set_Dog_Nextdirection_A(&e);
							G1->D2->Set_Dog_Nextdirection_B(&e);
							G1->D3->Set_Dog_Nextdirection_C(&e);
							G1->D4->Set_Dog_Nextdirection_D(&e);
							G1->D5->Set_Dog_Nextdirection_A(&e);
							if(G1->P1!=NULL){
								G1->P1->Player_Events(&e);
								cout<<"Player_Score"<<G1->P1->Get_Player_Score()<<" Player Health "<<G1->P1->Player_Health_Points<<endl;
					   		}
					   }
					
                    
				G1->D2->Dog_Update(G1->renderer);
				G1->D3->Dog_Update(G1->renderer);
				G1->D4->Dog_Update(G1->renderer);
				G1->D5->Dog_Update(G1->renderer);

				G1->D1->Dog_Update(G1->renderer);
				if(G1->P1 !=NULL){
					G1->P1->Go(G1->renderer);
					if(G1->P1->Check_Player_Collision(G1->D1->Dog_Curr_Position)==true 
					|| G1->P1->Check_Player_Collision(G1->D2->Dog_Curr_Position)==true
					|| G1->P1->Check_Player_Collision(G1->D3->Dog_Curr_Position)==true 
					|| G1->P1->Check_Player_Collision(G1->D4->Dog_Curr_Position)==true 
					|| G1->P1->Check_Player_Collision(G1->D5->Dog_Curr_Position)==true){
							G1->P1->Player_Collides();
					}
					if(G1->P1->Player_Health_Points < 500){
						G1->P1 =NULL;
					}
				}
				SDL_RenderPresent( G1->renderer );
				}
				
				

				}
			
				
            }
    G1->close_Game();



    return 0;
}