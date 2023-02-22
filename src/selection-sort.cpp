#include <vector>
#include <iostream>
#include "util.hpp"
using namespace std;

int idx_min(vector<TYPE>& v, int i, int j){
	int idx = i;
	for(int k = i ; k < j; k++){
		if(cmp(v[idx],v[k]) < 0){
			idx = k;
		}
	}
	return idx;
}

void selection_sort(vector<TYPE>& v){
	for(int i = 0; i < v.size(); i++){
		swap(v[i],v[idx_min(v,i,v.size())]);
	}
	isOrdered(v);
}
