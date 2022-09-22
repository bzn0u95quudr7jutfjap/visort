#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <cstring>
#include <SDL2/SDL.h>

using namespace std;

#include "util.hpp"
#include "qcs.hpp"
#include "cts.hpp"
#include "ezs.hpp"
#include "bbs.hpp"
#include "bgo.hpp"
#include "sels.hpp"
#include "inss.hpp"

extern SDL_Window * window;
extern SDL_Renderer * renderer;
extern vector<TYPE> blocks;

const int border = 4;

int main(int args, char ** argv){

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(W,H,0,&window,&renderer);
	//SDL_RenderSetScale(renderer,2,2);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	int numCols = args > 1 ?  atoi(argv[1]) : 12;
	for(int i = 0 ; i < numCols; i++){
		TYPE r;
		r.w=-border + (W/numCols);
		r.h=-border + (H/numCols)*(i+1);
		r.x=(border/2) + (W/numCols)*i;
		r.y=-(border/2) + (H-r.h);
		blocks.push_back(r);
	}

	random_device rd;
    uniform_int_distribution<int> dist(0,numCols-1);

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
		}
	}

	SDL_Delay(2000);
}
