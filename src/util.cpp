#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstring>
#include <random>
#include <SDL2/SDL.h>
#include "util.hpp"

using namespace std;

SDL_Window * window = nullptr;
SDL_Renderer * renderer = nullptr;
vector<TYPE> blocks;

void swapNonGraphic(vector<TYPE>& v, int i, int j){
		TYPE& a = v[i];
		TYPE& b = v[j];
		int c = a.h;
		a.h = b.h;
		b.h = c;
		c = a.y;
		a.y = b.y;
		b.y = c;
}

void shuffle(vector<TYPE>& v, random_device& rd, uniform_int_distribution<int>& uid){
	for(int i = 0; i < v.size(); i++){
		swapNonGraphic(v,i,uid(rd));
	}
}

void printSDL(){
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderDrawRects(renderer,blocks.data(),blocks.size());
	SDL_RenderFillRects(renderer,blocks.data(),blocks.size());
	SDL_RenderPresent(renderer);
	SDL_Delay(100);
}

void printSDL(int i, int j){
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderDrawRects(renderer,blocks.data(),blocks.size());
	SDL_RenderFillRects(renderer,blocks.data(),blocks.size());

	SDL_SetRenderDrawColor(renderer,0,0x88,0xcc,255);
	SDL_RenderFillRect(renderer,&(blocks[i]));
	SDL_SetRenderDrawColor(renderer,0xff,0x0,0x0,255);
	SDL_RenderFillRect(renderer,&(blocks[j]));
	SDL_RenderPresent(renderer);
	SDL_Delay(100);
}

int cmp(vector<TYPE>& v, int i, int j){
	return v[j].h - v[i].h;
}

bool isOrdered(vector<TYPE>& v){
	bool ordered = 1;
	for(int i = 0; i < v.size()-1; i++){
		if(cmp(v,i,i+1)<0){
			i = v.size()+1;
			ordered = 0;
		}
	}
	return ordered;
}

void swap(vector<TYPE>& v, int i, int j){
	swapNonGraphic(v,i,j);
	printSDL(i,j);
}