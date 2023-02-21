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

void bogo_sort(vector<TYPE>& v);
void bubble_sort(vector<TYPE>& v);
void cocktail_sort(vector<TYPE>& v);
void easy_sort(vector<TYPE>& v);
void selection_sort(vector<TYPE>& v);
void insertion_sort(vector<TYPE>& v);
void insertion_sort_recursive(vector<TYPE>& v);
void quick_sort(vector<TYPE>& v);
void merge_sort_inplace_recursive(vector<TYPE>& v);
void merge_sort_inplace_iterative(vector<TYPE>& v);
void merge_sort_copy_recursive(vector<TYPE>& v);
void merge_sort_copy_iterative(vector<TYPE>& v);
void merge_sort_copy_iterative_post(vector<TYPE>& v);

int MS_DELAY = 60;
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
	SDL_Delay(MS_DELAY);
}

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

void swap(vector<TYPE>& v, int i, int j){
	swapNonGraphic(v,i,j);
	printSDL(i,j);
}
int cmpNonGraphic(vector<TYPE>& v, int i, int j){
	return v[j].h - v[i].h;
}
int cmp(vector<TYPE>& v, int i, int j){
	printSDL(i,j);
	return cmpNonGraphic(v,i,j);
}

bool isOrdered(vector<TYPE>& v){
	bool ordered = 1;
	printSDL();
	SDL_SetRenderDrawColor(renderer,0,255,0,255);
	SDL_RenderFillRect(renderer,&(blocks[0]));
	SDL_RenderPresent(renderer);
	SDL_Delay(MS_DELAY);
	for(int i = 0; i < v.size()-1; i++){
		if(cmpNonGraphic(v,i,i+1)<0){
			i = v.size()+1;
			ordered = 0;
		}else{
			SDL_RenderFillRect(renderer,&(blocks[i+1]));
			SDL_RenderPresent(renderer);
			SDL_Delay(MS_DELAY);
		}
	}
	return ordered;
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

	MS_DELAY =			args.find("delay")	== args.end() ? 16			: stoi(args.at("delay"));
	int border =			args.find("border")	== args.end() ? 0			: stoi(args.at("border"));
	int numCols = 			args.find("n")		== args.end() ? 64			: stoi(args.at("n"));
	vector<string> algoToUse =	args.find("algo")	== args.end() ? vector<string>()	: str_split(args.at("algo"),",");
	int W =				args.find("w")		== args.end() ? 640			: stoi(args.at("w"));
	int H =				args.find("h")		== args.end() ? 480			: stoi(args.at("h"));
	string caseToUse =		args.find("case")	== args.end() ? "random"		: args.at("case");

	for(auto [k,v] : args){ cout << "( " << k << " = " << v << " ), "; }
	cout << endl;

	map<string,SortFun> algos = {
		{"bbs",bubble_sort},
		{"cts",cocktail_sort},
		{"ezs",easy_sort},
		{"sels",selection_sort},
		{"inss",insertion_sort},
		{"insr",insertion_sort_recursive},
		{"qcs",quick_sort},
		{"merge",merge_sort_inplace_recursive},
		{"merge-iter",merge_sort_inplace_iterative},
		{"merge-copy",merge_sort_copy_recursive},
		{"merge-copy-iter",merge_sort_copy_iterative},
		{"merge-copy-iter-post",merge_sort_copy_iterative_post}
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
