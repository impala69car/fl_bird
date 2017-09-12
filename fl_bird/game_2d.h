#pragma once
#include <string>
#include <SDL.h>
using namespace std;
class Game_2d
{
public:
	Game_2d(const string &title, int width, int height);
	~Game_2d();
	void recycle() const;
	void sprint(int day1, int day2,int day3, int day4,int day5,int day6,int day7);
	void sr();
	
	void Flappybird(SDL_Event &event);
	void ClosedWin(SDL_Event &event);
	inline bool gameOver() const { return false; };
public:
	bool _closed;
	bool _mainmenu;
private:
	bool init();
private:
	string _title;
	int wgame;
	int hgame;

	SDL_Window *_game_2d;
protected:
	SDL_Renderer *_renderer;
};