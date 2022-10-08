#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <random>
#include <cstring>
#include <csignal>
#include <SDL2/SDL.h>

using namespace std;

#include "util.hpp"

void qcs(vector<TYPE>& v);
void cts(vector<TYPE>& v);
void ezs(vector<TYPE>& v);
void bbs(vector<TYPE>& v);
void bgo(vector<TYPE>& v);
void sels(vector<TYPE>& v);
void inss(vector<TYPE>& v);
void mergesort(vector<TYPE>& v);

extern SDL_Window * window;
extern SDL_Renderer * renderer;
extern vector<TYPE> blocks;

int main(int args, char ** argv){

	signal(SIGINT,[](int sig){ exit(1);});

	int W = 640, H = 480;
	const int numCols = atoi(argv[1]);
	{
		const int border = 4;
		const int blockWidth = (W -(border*numCols)) /numCols;
		const int blockHeight = (H -(border*2)) /numCols;
		H = blockHeight*numCols + border*2;
		for(int i = 0 ; i < numCols; i++){
			TYPE r;
			r.w=blockWidth;
			r.h=blockHeight*(i+1);
			r.y=H -border -r.h;
			r.x=border*(i+1) +blockWidth*i;
			blocks.push_back(r);
		}
		W = (blockWidth+border)*numCols+border;
	}

	random_device rd;
    uniform_int_distribution<int> dist(0,numCols-1);

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(W,H,0,&window,&renderer);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	printSDL();
	for(int i = 2; i < args; i++){
		shuffle(blocks,rd,dist);
		if(strcmp(argv[i],"bbs")==0){			bbs(blocks);
		}else if(strcmp(argv[i],"cts")==0){		cts(blocks);
		}else if(strcmp(argv[i],"ezs")==0){		ezs(blocks);
		}else if(strcmp(argv[i],"sels")==0){	sels(blocks);
		}else if(strcmp(argv[i],"inss")==0){	inss(blocks);
		}else if(strcmp(argv[i],"qcs")==0){		qcs(blocks);
		}else if(strcmp(argv[i],"bgo")==0){		bgo(blocks);
		}else if(strcmp(argv[i],"merge")==0){		mergesort(blocks);
		}
	}

	SDL_Delay(2000);
}
