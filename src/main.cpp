#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
//void qcsm(vector<TYPE>& v);
void insRec(vector<TYPE>& v);

extern SDL_Window * window;
extern SDL_Renderer * renderer;
extern vector<TYPE> blocks;
extern int MS_DELAY;

bool str_equals(const char * s1, const char * s2){
	return strcmp(s1,s2)==0;
}
bool str_equals(const string& s1, const string& s2){
	return s1.compare(s2) == 0;
}

int main(int args, char ** argv){

	signal(SIGINT,[](int sig){ exit(1);});

	int numCols = 12;
	vector<string> algoToUse;
	for(int i = 1; i < args; i++){
		string s(argv[i]);
		string name = s.substr(0,s.find("="));
		string value = s.substr(s.find("=")+1);

		printf("%s \n", argv[i]);
		printf("( %s = %s ) \n",name.c_str(), value.c_str());
				if(str_equals(name,"n")){ numCols = stoi(value);
		}else 	if(str_equals(name,"delay")){ MS_DELAY = stoi(value);
		}else 	if(str_equals(name,"algo")){
			int idx = 0;
			while(idx > -1){
				idx = value.find(",");
				string current = value.substr(0,idx);
				printf("%s \n",current.c_str());
				algoToUse.push_back(current);
				value = value.substr(idx+1);
			}
			for(string s : algoToUse){
				printf("%s ",s.c_str());
			}
		}
	}
	printf("\n");

	int W = 640, H = 480;
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
	for(int i = 0; i < algoToUse.size(); i++){
		shuffle(blocks,rd,dist);
			  if(str_equals(algoToUse[i],"bbs"  )){	bbs(blocks);
		}else if(str_equals(algoToUse[i],"cts"  )){	cts(blocks);
		}else if(str_equals(algoToUse[i],"ezs"  )){	ezs(blocks);
		}else if(str_equals(algoToUse[i],"sels" )){	sels(blocks);
		}else if(str_equals(algoToUse[i],"inss" )){	inss(blocks);
		}else if(str_equals(algoToUse[i],"qcs"  )){	qcs(blocks);
		}else if(str_equals(algoToUse[i],"bgo"  )){	bgo(blocks);
		}else if(str_equals(algoToUse[i],"merge")){	mergesort(blocks);
		}else if(str_equals(algoToUse[i],"insr" )){	insRec(blocks);
		//}else if(strcmp(argv[i],"qcsm")==0){	qcsm(blocks);
		}
	}

	SDL_Delay(1024 + 512);
}
