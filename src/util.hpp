#pragma once

#include <SDL2/SDL.h>
#include <vector>

using std::vector;

typedef SDL_Rect TYPE;

void printSDL();
int cmp(TYPE&, TYPE&);
int cmpNonGraphic(TYPE&, TYPE&);
bool isOrdered(vector<TYPE>& v);
void swapNonGraphic(TYPE&, TYPE&);
void swap(TYPE&, TYPE&);

bool isLess(TYPE&,TYPE&);
bool isLessEqual(TYPE&,TYPE&);
bool isGreater(TYPE&,TYPE&);
bool isGreaterEqual(TYPE&,TYPE&);

extern int MS_DELAY;
extern SDL_Window * window;
extern SDL_Renderer * renderer;
extern vector<TYPE> blocks;

