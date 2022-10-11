#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <random>

using std::vector;
using std::random_device;
using std::uniform_int_distribution;

typedef SDL_Rect TYPE;

void shuffle(vector<TYPE>& v, random_device&, uniform_int_distribution<int>&);
void printSDL();
int cmp(vector<TYPE>&v, int i, int j);
//int cmpNonGraphic(vector<TYPE>&v, int i, int j);
bool isOrdered(vector<TYPE>& v);
//void swapNonGraphic(vector<TYPE>& v, int i, int j);
void swap(vector<TYPE>& v, int i, int j);
