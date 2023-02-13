
#include <iostream>
#include <vector>
#include "util.hpp"

using std::cout;

void mergesort_iter_move(vector<TYPE>& v,int i, int j){
	while(i < j){
		swap(v,j-1,j);
		j--;
	}
}

void mergesort_iter_merge(vector<TYPE>& v,int i, int j, int k){
	k = k < v.size() ? k : v.size();
	while(i<j && j<k){
		if(cmp(v,i,j)<0){
			mergesort_iter_move(v,i,j);
			j++;
			i++;
		}else{
			i++;
		}
	}
}

void mergesort_inplace_iterative(vector<TYPE>& v){
	printSDL();

	for(int len = 1; len < v.size(); len*=2){
		for(int i=0; i < v.size(); i+=len*2){
			mergesort_iter_merge(v,i,i+len,i+len*2);
		}
	}

	isOrdered(v);
}
