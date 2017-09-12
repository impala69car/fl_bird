#pragma once 
#include "wall.h"
#include "game_2d.h"
class Bird : public Game_2d
{
public:
	Bird(const Game_2d &game_2d,int w, int h, int x, int y, int r,int g,int b,int a);
	
	void draw() const;
	void flying(SDL_Event &event);
	bool collisions(int cx,int yc,int hc);
	void gr();
private:
	int wg, hg, xg, yg, rg, gg, gb, ag;
};