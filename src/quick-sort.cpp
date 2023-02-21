#include <vector>
#include <numeric>
#include <queue>
#include <random>
#include <iostream>
#include "util.hpp"
using namespace std;

void _partition(vector<TYPE>& v, int l, int p, int h){
	while(l < p && p < h){
		while(cmp(v,l,p)>0){l++;}
		while(cmp(v,p,h)>0){h--;}
		if(l < p && p < h){
			swap(v,l,h);
			l++;
			h--;
		}
	}
}

int __place_pivot_in_correct_place(vector<TYPE>& v, int l, int h, int r){
	int p = l;
	for(int i=l; i <= h; i++){ if(cmp(v,i,r)>0){ p++; } }
	swap(v,p,r);
	return p;
}

int _pivot_last(vector<TYPE>& v, int l, int h){
	return __place_pivot_in_correct_place(v,l,h,h);
}

int _pivot_first(vector<TYPE>& v, int l, int h){
	return __place_pivot_in_correct_place(v,l,h,l);
}

int _pivot_random(vector<TYPE>& v, int l, int h){
	random_device rd;
	uniform_int_distribution uid(l,h);
	return __place_pivot_in_correct_place(v,l,h,uid(rd));
}

int _pivot_medium(vector<TYPE>& v, int l, int h){

	typedef int (*vec_func)(vector<TYPE>&,int,int);
	typedef int (*math_func)(int);

	vec_func _idx_min = [](vector<TYPE>& v, int i, int j){
		int idx = i;
		for(int k = i ; k <= j; k++){ if(cmp(v,idx,k) < 0){ idx = k; } }
		return idx;
	};
	vec_func _idx_max = [](vector<TYPE>& v, int i, int j){
		int idx = i;
		for(int k = i ; k <= j; k++){ if(cmp(v,idx,k) > 0){ idx = k; } }
		return idx;
	};

	math_func _abs = [](int a){ return 0<=a?a:-a ; };

	int min = _idx_min(v,l,h);
	int max = _idx_max(v,l,h);
	int avg = (v[max].h + v[min].h)/2;
	int r = l;
	for(int i=l;i<h;i++){
		if(_abs(avg - v[i].h)<_abs(avg - v[r].h)){ r=i; }
	}

	return __place_pivot_in_correct_place(v,l,h,r);
}

void _quick_sort_reursion(vector<TYPE>& v,int l, int h, int (*_pivot)(vector<TYPE>&,int,int)){
	if(l < h){
		int p = _pivot(v,l,h);
		_partition(v,l,p,h);
		_quick_sort_reursion(v,l,p-1,_pivot);
		_quick_sort_reursion(v,p+1,h,_pivot);
	}
}

void quick_sort(vector<TYPE>& v){
	printSDL();
	_quick_sort_reursion(v,0,v.size()-1,_pivot_random);
	isOrdered(v);
}

void quick_sort_iterative(vector<TYPE>& v){
	printSDL();

	queue<int> stack;
	stack.push(0);
	stack.push(v.size()-1);

	while(stack.size()){
		int l = stack.front(); stack.pop();
		int h = stack.front(); stack.pop();
		if( l < h ){
			int p = _pivot_random(v,l,h);
			_partition(v,l,p,h);
			stack.push(l); stack.push(p-1);
			stack.push(p+1); stack.push(h);
		}
	}

	isOrdered(v);
}

