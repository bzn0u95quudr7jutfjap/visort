#pragma once

#include <SDL2/SDL.h>
#include <vector>

using std::vector;

typedef SDL_Rect TYPE;

void printSDL();
int cmp(vector<TYPE>&v, int i, int j);
//int cmpNonGraphic(vector<TYPE>&v, int i, int j);
bool isOrdered(vector<TYPE>& v);
void swapNonGraphic(vector<TYPE>& v, int i, int j);
void swap(vector<TYPE>& v, int i, int j);
