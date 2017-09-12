#include "game_2d.h"
#include "wall.h"
#include "bird.h"
#include "mainmenu.h"
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;
void closewindow(Game_2d &game_2d)
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		game_2d.Flappybird(event);
	}
}
void flying(Bird &bird,Game_2d &game_2d)
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		SDL_Delay(10);
		bird.flying(event);
		game_2d.Flappybird(event);
	}
	else
	{
		SDL_Delay(10);
		bird.gr();
	}
}
void menuspoint(Mainmenu &menupoint,Game_2d &game_2d)
{
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		menupoint.menuspoint(event);
		game_2d.ClosedWin(event);
	}
}
int main(int argc, char **argv)
{
	int wallcount=0;
	int deadcount = 0;
	int counteen[3] = {0,1,2};
	string files[3];
	files[0] = "leaders1.txt";
	files[1] = "leaders2.txt";
	files[2] = "leaders3.txt";
	std::ofstream fout(files[rand() % counteen[2]+counteen[0]]);
	Game_2d game_2d("flappy bird", 800, 600);
	Wall wall1(game_2d,50,250,800,200,200,0,200,255);
	Wall wall2(game_2d,50,300,1200,250,200,0,200,255);
	Wall wall3(game_2d,50,350,1500,360,200,0,200,255);
	Wall wall4(game_2d,50,350,740,360,200,0,200,255);
	Mainmenu menupoint1(game_2d,150,55,360,200,"menu/newgame.png");
	Bird bird(game_2d,20,20,200,300,200,0,200,255);
	int randH[4];
	randH[0]=250;
	randH[1]=350;
	randH[2] = 300;
	randH[3] = 380;
	bool click=false;
	int input = 0;
	menupoint1.click=false;
	while (!game_2d.gameOver()&&game_2d._closed==false)
	{
		if(menupoint1.click==false)
		{
			menupoint1.draw();
			wallcount=0;
			deadcount=0;
			menuspoint(menupoint1,game_2d);
			if(game_2d._mainmenu==false)
			{
				menupoint1.click=true;
			}
			game_2d.recycle();
		}
		else if(menupoint1.click==true)
		{
		wall1.draw();
		wall2.draw();
		wall3.draw();
		wall4.draw();
		if(wall1.gravity(780,200,rand() % randH[3] + randH[0]))
		{
			wallcount+=1;
		}
		if(wall2.gravity(950,250,rand() % randH[3] + randH[0]))
		{
			wallcount+=1;
		}
		if(wall3.gravity(1200,360,rand() % randH[3] + randH[0]))
		{
			wallcount+=1;
		}
		if(wall4.gravity(1600,200,rand() % randH[3] + randH[0]))
		{
			wallcount+=1;
		}
		if(bird.collisions(wall1.Xcollision(),wall1.Ycollision(),150))
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<wallcount<<std::endl;
			std::cout<<wallcount<<std::endl;	
		}
		if(bird.collisions(wall2.Xcollision(),wall2.Ycollision(),250))
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<wallcount<<std::endl;
			std::cout<<wallcount<<std::endl;
		}
		if(bird.collisions(wall3.Xcollision(),wall3.Ycollision(),350))
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<wallcount<<std::endl;
			std::cout<<wallcount<<std::endl;
		}
		if(bird.collisions(wall4.Xcollision(),wall4.Ycollision(),350))
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<wallcount<<std::endl;
			std::cout<<wallcount<<std::endl;
		}
		bird.draw();
		flying(bird,game_2d);
		if(game_2d._mainmenu==true)
		{
			menupoint1.click=false;
		}
		game_2d.recycle();
		}
	}
	return 0;
}