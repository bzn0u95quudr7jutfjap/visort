#include <iostream>
#include <vector>
#include "util.hpp"

void _mergesort_move(vector<TYPE>& v,int i, int j){
	while(i < j){
		swap(v,j-1,j);
		j--;
	}
}

void _mergesort_merge_inplace(vector<TYPE>& v,int i, int j, int k){
	k = k < v.size() ? k : v.size();
	while(i<j && j<k){
		if(cmp(v,i,j)<0){
			_mergesort_move(v,i,j);
			j++;
			i++;
		}else{
			i++;
		}
	}
}

void _merge_sort_recurion(vector<TYPE>& v, int l, int h){
	if(h-l>=2){
		int m = (h+l)/2;
		_merge_sort_recurion(v,l,m);
		_merge_sort_recurion(v,m,h);
		_mergesort_merge_inplace(v,l,m,h);
	}
}

void merge_sort_inplace_recursive(vector<TYPE>& v){
	printSDL();
	_merge_sort_recurion(v,0,v.size());
	isOrdered(v);
}

void merge_sort_inplace_iterative(vector<TYPE>& v){
	printSDL();
	for(int len = 1; len < v.size(); len*=2){
		for(int i=0; i < v.size(); i+=len*2){
			_mergesort_merge_inplace(v,i,i+len,i+len*2);
		}
	}
	isOrdered(v);
}
