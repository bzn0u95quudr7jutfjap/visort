
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

void mergesort_iter(vector<TYPE>& v){
	printSDL();

	// 20 elementi
	//mergesort_iter_merge(v, 0, 1, 2);
	//mergesort_iter_merge(v, 2, 3, 4);
	//mergesort_iter_merge(v, 4, 5, 6);
	//mergesort_iter_merge(v, 6, 7, 8);
	//mergesort_iter_merge(v, 8, 9,10);
	//mergesort_iter_merge(v,10,11,12);
	//mergesort_iter_merge(v,12,13,14);
	//mergesort_iter_merge(v,14,15,16);
	//mergesort_iter_merge(v,16,17,18);
	//mergesort_iter_merge(v,18,19,20);

	//mergesort_iter_merge(v, 0, 2, 4);
	//mergesort_iter_merge(v, 4, 6, 8);
	//mergesort_iter_merge(v, 8,10,12);
	//mergesort_iter_merge(v,12,14,16);
	//mergesort_iter_merge(v,16,18,20);

	//mergesort_iter_merge(v, 0, 4, 8);
	//mergesort_iter_merge(v, 8,12,16);
	//mergesort_iter_merge(v,16,20,20);

	//mergesort_iter_merge(v,0,8,16);
	//mergesort_iter_merge(v,16,20,20);

	//mergesort_iter_merge(v,0,16,20);

	for(int len = 1; len < v.size(); len*=2){
		for(int i=0; i < v.size(); i+=len*2){
			mergesort_iter_merge(v,i,i+len,i+len*2);
		}
	}

	isOrdered(v);
}
