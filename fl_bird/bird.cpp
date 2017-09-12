#include "wall.h"
#include "bird.h"
#include "game_2d.h"
#include <iostream>
#include <fstream>
#include <ctime>
Bird::Bird(const Game_2d &game_2d, int w, int h, int x, int y, int r, int g, int b, int a) :
	Game_2d(game_2d), wg(w), hg(h), xg(x), yg(y), rg(r), gg(g), gb(b), ag(a)
{

}
void Bird::draw() const{
	SDL_Rect bird;
	bird.w = wg;
	bird.h = hg;
	bird.x = xg;
	bird.y = yg;
	SDL_SetRenderDrawColor(_renderer, 200, 0, 200,255);
	SDL_RenderFillRect(_renderer,&bird);
}
void Bird::flying(SDL_Event &event)
{
	if(yg<25)
	{
		yg+=10;
	}
	else
	{
		if(event.key.keysym.sym==SDLK_SPACE)
		{
			if(yg<100)
			{
				yg-=3;
			}
			else
			{
				yg-=30;
			}
		}
	}
}
void Bird::gr()
{
	yg+=10;
}
bool Bird::collisions(int cx, int yc,int hc)
{
	int msec = 0;
	if(xg+wg<cx||xg>cx+50||yg+hg<yc||yg>yc+hc)
	{
		return false;
	}
	else
	{
		xg=100;
		yg=100;
		return true;
	}
}