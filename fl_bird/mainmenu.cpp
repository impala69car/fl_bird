#include "mainmenu.h"
#include "game_2d.h"
#include <SDL_image.h>
#include <iostream>
using namespace std;
Mainmenu::Mainmenu(const Game_2d &game_2d,int w, int h, int x, int y,const string &path) :
Game_2d(game_2d),wg(w),hg(h),xg(x),yg(y)
{
	SDL_Surface *load = IMG_Load(path.c_str());
	mtexture = SDL_CreateTextureFromSurface(_renderer, load);
	SDL_FreeSurface(load);
}
Mainmenu::~Mainmenu()
{
	SDL_DestroyTexture(mtexture);
}
void Mainmenu::draw() const
{
	SDL_Rect menupoint;
	menupoint.w = wg;
	menupoint.h = hg;
	menupoint.x = xg;
	menupoint.y = yg;
	if(mtexture)
	{
		SDL_RenderCopy(_renderer,mtexture,nullptr, &menupoint);
	}
}
void Mainmenu::menuspoint(SDL_Event &event)
{
	if(event.key.keysym.sym==SDLK_SPACE)
	{
		click=true;
	}
}