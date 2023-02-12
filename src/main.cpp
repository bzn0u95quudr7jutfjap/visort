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
void mergesort_iter(vector<TYPE>& v);
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

vector<string> str_split(string s, const string& del){
	vector<string> ris;
	int idx;
	while((idx = s.find(del)) != -1){
		ris.push_back(s.substr(0,idx));
		s = s.substr(idx+1);
	}
	if(s.compare("")!=0){ ris.push_back(s); }
	return ris;
}

int main(int argc, char ** argv){
	signal(SIGINT,[](int sig){ exit(1);});

	map<string,string> args;
	for(int i=1; i < argc; i++){
		vector<string> arg = str_split(argv[i],"=");
		args[arg[0]]=arg[1];
	}

	MS_DELAY =			args.find("delay")	== args.end() ? 60			: stoi(args.at("delay"));
	int border =			args.find("border")	== args.end() ? 4			: stoi(args.at("border"));
	int numCols = 			args.find("n")		== args.end() ? 12			: stoi(args.at("n"));
	vector<string> algoToUse =	args.find("algo")	== args.end() ? vector<string>()	: str_split(args.at("algo"),",");

	for(auto [k,v] : args){ cout << "( " << k << " = " << v << " ), "; }
	cout << endl;

	int W = 640, H = 480;
	{
		const int blockWidth = (W -(border*numCols)) /numCols;
		const int blockHeight = (H -(border*2)) /numCols;
		H = blockHeight*numCols + border*2;
		for(int i = 0 ; i < numCols; i++){
			blocks.push_back({ .x=border*(i+1)+blockWidth*i, .y=H-border-blockHeight*(i+1), .w=blockWidth, .h=blockHeight*(i+1) });
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
	
	//for(int i=0,j=blocks.size()-1; i < j; i++,j--){ swapNonGraphic(blocks,i,j); }

	printSDL();
	for(int i = 0; i < algoToUse.size(); i++){
		shuffle(blocks,rd,dist);


		if(		str_equals(algoToUse[i],"bbs"  )){		bbs(blocks);
		}else if(	str_equals(algoToUse[i],"cts"  )){		cts(blocks);
		}else if(	str_equals(algoToUse[i],"ezs"  )){		ezs(blocks);
		}else if(	str_equals(algoToUse[i],"sels" )){		sels(blocks);
		}else if(	str_equals(algoToUse[i],"inss" )){		inss(blocks);
		}else if(	str_equals(algoToUse[i],"qcs"  )){		qcs(blocks);
		}else if(	str_equals(algoToUse[i],"bgo"  )){		bgo(blocks);
		}else if(	str_equals(algoToUse[i],"merge")){		mergesort(blocks);
		}else if(	str_equals(algoToUse[i],"merge-iter")){		mergesort_iter(blocks);
		}else if(	str_equals(algoToUse[i],"insr" )){		insRec(blocks);
		//}else if(strcmp(argv[i],"qcsm")==0){	qcsm(blocks);
		}
	}

	SDL_Delay(1024 + 512);
}
