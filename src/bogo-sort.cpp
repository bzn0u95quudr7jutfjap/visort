#include <vector>
#include <random>
#include <algorithm>
#include "util.hpp"

using namespace std;

void bogo_sort(vector<SDL_Rect>& v){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1,v.size());
	while(!isOrdered(v)){
		int rand1 = dist(gen);
		int rand2 = dist(gen);
		swap(v,rand1,rand2);
	}
}
