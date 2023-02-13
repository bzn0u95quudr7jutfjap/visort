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

typedef void(*SortFun)(vector<TYPE>&);

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
	int W =				args.find("w")		== args.end() ? 640			: stoi(args.at("w"));
	int H =				args.find("h")		== args.end() ? 480			: stoi(args.at("h"));
	string caseToUse =		args.find("case")	== args.end() ? "random"		: args.at("case");

	for(auto [k,v] : args){ cout << "( " << k << " = " << v << " ), "; }
	cout << endl;

	map<string,SortFun> algos = {
		{"bbs",bbs},
		{"cts",cts},
		{"ezs",ezs},
		{"sels",sels},
		{"inss",inss},
		{"insr",insRec},
		{"qcs",qcs},
		{"merge",mergesort},
		{"merge-iter",mergesort_iter}
	};

	map<string,SortFun> cases = {
		{"best",	[](vector<TYPE>& v){}},
		{"worst",	[](vector<TYPE>& v){
			for(int i=0,j=v.size()-1;i<j;i++,j--){
				swapNonGraphic(v,i,j);
			}
		}},
		{"random",	[](vector<TYPE>& v){
			static random_device rd;
			static uniform_int_distribution<int> uid(0,v.size()-1);
			for(int i = 0; i < v.size(); i++){
				swapNonGraphic(v,i,uid(rd));
			}
		}}
	};

	const int blockWidth = (W -(border*numCols)) /numCols;
	const int blockHeight = (H -(border*2)) /numCols;
	H = blockHeight*numCols + border*2;
	for(int i = 0 ; i < numCols; i++){
		blocks.push_back({ .x=border*(i+1)+blockWidth*i, .y=H-border-blockHeight*(i+1), .w=blockWidth, .h=blockHeight*(i+1) });
	}
	W = (blockWidth+border)*numCols+border;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(W,H,0,&window,&renderer);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	printSDL();

	for_each(algoToUse.begin(),algoToUse.end(),[&](const string& a){
		cases.at(caseToUse)(blocks);
		algos.at(a)(blocks);
		SDL_Delay(1024 + 512);
	});

	SDL_Delay(1024 + 512);
}
