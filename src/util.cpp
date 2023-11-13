#include "util.hpp"

using namespace std;

typedef void(*SortFun)(vector<TYPE>&);

void bogo_sort(vector<TYPE>& v);
void bubble_sort(vector<TYPE>& v);
void cocktail_sort(vector<TYPE>& v);
void easy_sort(vector<TYPE>& v);
void selection_sort(vector<TYPE>& v);
void insertion_sort(vector<TYPE>& v);
void insertion_sort_recursive(vector<TYPE>& v);
void quick_sort(vector<TYPE>& v);
void quick_sort_iterative(vector<TYPE>& v);
void merge_sort_inplace_recursive(vector<TYPE>& v);
void merge_sort_inplace_iterative(vector<TYPE>& v);
void merge_sort_copy_recursive(vector<TYPE>& v);
void merge_sort_copy_iterative(vector<TYPE>& v);
void merge_sort_copy_iterative_post(vector<TYPE>& v);

int MS_DELAY;
SDL_Window * window = nullptr;
SDL_Renderer * renderer = nullptr;
vector<TYPE> blocks;

void printSDL(){
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderDrawRects(renderer,blocks.data(),blocks.size());
	SDL_RenderFillRects(renderer,blocks.data(),blocks.size());
	SDL_RenderPresent(renderer);
	SDL_Delay(MS_DELAY);
}

void printSDL(TYPE& a, TYPE& b){
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderDrawRects(renderer,blocks.data(),blocks.size());
	SDL_RenderFillRects(renderer,blocks.data(),blocks.size());

	SDL_SetRenderDrawColor(renderer,0,0x88,0xcc,255);
	SDL_RenderFillRect(renderer,&a);
	SDL_SetRenderDrawColor(renderer,0xff,0x0,0x0,255);
	SDL_RenderFillRect(renderer,&b);
	SDL_RenderPresent(renderer);
	SDL_Delay(MS_DELAY);
}

void swapNonGraphic(TYPE& a, TYPE& b){
		int c = a.h;
		a.h = b.h;
		b.h = c;
		c = a.y;
		a.y = b.y;
		b.y = c;
}

void swap(TYPE& a, TYPE& b){
	swapNonGraphic(a,b);
	printSDL(a,b);
}
int cmpNonGraphic(TYPE& a, TYPE& b){
	return a.h - b.h;
}
int cmp(TYPE& a, TYPE& b){
	printSDL(a,b);
	return cmpNonGraphic(a,b);
}

bool isLess(TYPE& a, TYPE&b){		return cmp(a,b)< 0; }
bool isLessEqual(TYPE& a, TYPE&b){	return cmp(a,b)<=0; }
bool isGreater(TYPE& a, TYPE&b){	return cmp(a,b)> 0; }
bool isGreaterEqual(TYPE& a, TYPE&b){	return cmp(a,b)>=0; }

bool isLessNonGraphic(TYPE& a, TYPE& b){ return cmpNonGraphic(a,b)<0; }

bool isOrdered(vector<TYPE>& v){
	bool ordered = 1;
	printSDL();
	SDL_SetRenderDrawColor(renderer,0,255,0,255);
	SDL_RenderFillRect(renderer,&(blocks[0]));
	SDL_RenderPresent(renderer);
	SDL_Delay(MS_DELAY);
	for(int i = 0; i < v.size()-1; i++){
		if(isLessNonGraphic(v[i],v[i+1])){
			SDL_RenderFillRect(renderer,&(blocks[i+1]));
			SDL_RenderPresent(renderer);
			SDL_Delay(MS_DELAY);
		}else{
			i = v.size()+1;
			ordered = 0;
		}
	}
	return ordered;
}

