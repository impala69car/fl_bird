#pragma once
#include "game_2d.h"
#include <string>
using namespace std;
class Mainmenu : public Game_2d
{
public:
	Mainmenu(const Game_2d &game_2d,int w, int h, int x, int y,const string &path);
	~Mainmenu();
	void draw() const;
	void menuspoint(SDL_Event &event);
	bool click;
private:
	int wg, hg, xg, yg;
	SDL_Texture *mtexture;
};