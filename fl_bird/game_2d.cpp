#include "game_2d.h"
#include "mainmenu.h"
#include <SDL_image.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
Game_2d::Game_2d(const string &title, int width,int height) :
	_title(title), wgame(width),hgame(height)
{
	_closed = !init();
}

Game_2d::~Game_2d()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_game_2d);
	IMG_Quit();
	SDL_Quit();
}
bool Game_2d::init()
{
	if(IMG_Init(IMG_INIT_PNG)!=IMG_INIT_PNG)
	{
		return false;
	}
	_game_2d = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		wgame,hgame,0);
	_renderer = SDL_CreateRenderer(_game_2d, -1,SDL_RENDERER_ACCELERATED);
	return true;
}
void Game_2d::Flappybird(SDL_Event &event)
{
	if(event.key.keysym.sym==SDLK_F1)
	{
		_mainmenu = true;
	}
}
void Game_2d::ClosedWin(SDL_Event &event)
{
	if(event.key.keysym.sym==SDLK_ESCAPE)
	{
		_closed = true;
	}
	else if(event.key.keysym.sym==SDLK_TAB)
	{
		_mainmenu = false;
	}
}
void Game_2d::recycle() const
{
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer,0,0,200,255);
	SDL_RenderClear(_renderer);
}

void Game_2d::sprint(int day1, int day2,int day3, int day4,int day5,int day6,int day7)
{
	std::cout<<"Temperature summer!.\n";
	string filen = "pogoda.txt";
	ofstream fout(filen);
	cout<<day1<<endl;
	fout<<day1<<endl;
	fout<<day2<<endl;
	cout<<day2<<endl;
	fout<<day3<<endl;
	cout<<day3<<endl;
	fout<<day4<<endl;
	cout<<day4<<endl;
	fout<<day5<<endl;
	cout<<day5<<endl;
	fout<<day6<<endl;
	cout<<day6<<endl;
	fout<<day7<<endl;
	cout<<day7<<endl;
}
