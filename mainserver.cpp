#pragma once
#include "Game.h"


#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080


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
G1->D1->Dog_Update(G1->renderer);
SDL_RenderPresent(G1->renderer);

//socket server
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char* hello = "Hello from server";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
		== 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt,
				sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr*)&address,
			sizeof(address))
		< 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket
		= accept(server_fd, (struct sockaddr*)&address,
				(socklen_t*)&addrlen))
		< 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}
	valread = read(new_socket, buffer, 1024);
	string mystr= buffer;
	int position= mystr.find(".");
	string xposstr= mystr.substr(0, position);
	string yposstr= mystr.substr(position+1, mystr.length());
	int xpos= stoi(xposstr);
	int ypos= stoi(yposstr);


	string curr=to_string(G1->P1->Player_Curr_POsition.x)+"."+to_string(G1->P1->Player_Curr_POsition.y);

	char* h= const_cast<char*>(curr.c_str());

	printf("%s\n", buffer);
	send(new_socket, h, strlen(h), 0);
	printf("Hello message sent\n");

G1->P2=new Player(G1->Texture_M->Get_Texture("Player_2"));
G1->P2->set_Curr_Pos(150*8,29*8);
G1->P2->Render(G1->renderer,xpos,ypos,G1->P2->Player_Texture);


	
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
							if(G1->P1!=NULL){
								G1->P1->Player_Events(&e);
						
					   		}
					   }
					
                    

				G1->D1->Dog_Update(G1->renderer);
				if(G1->P1 !=NULL){
					G1->P1->Go(G1->renderer);
					
					if(G1->P1->Check_Player_Collision(G1->D1->Dog_Curr_Position)==true){
							G1->P1=NULL;
					}	
				}
				G1->P2->Go(G1->renderer);
				SDL_RenderPresent( G1->renderer );
				}
				
				

				}
			
				
            }
    G1->close_Game();



    return 0;
}
