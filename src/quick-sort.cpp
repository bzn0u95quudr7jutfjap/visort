#include <vector>
#include <queue>
#include <iostream>
#include "util.hpp"
using namespace std;

int _partition_last_element(vector<TYPE>& v, int l, int h){
	int i_p = h;
	int c = 0;
	for(int i=l; i < h; i++){ if(cmp(v,i,i_p)>=0){ c++; } }
	i_p = l+c;
	swap(v,i_p,h);
	int i=l, j=h;
	while(i < i_p && j > i_p){
		while(cmp(v,i,i_p) > 0){ i++; }
		while(cmp(v,j,i_p) < 0){ j--; }
		if(i < i_p && i_p < j){
			swap(v,i,j);
			i++; j--;
		}
	}
	return i_p;
}

void qcs_b(vector<TYPE>& v,int l, int h){
	if(l < h){
		int i_p = _partition_last_element(v,l,h);
		qcs_b(v,l,i_p-1);
		qcs_b(v,i_p+1,h);
	}
}

void quick_sort(vector<TYPE>& v){
	qcs_b(v,0,v.size()-1);
	//_quick_sort_medium_recursion(v,0,v.size()-1);
	isOrdered(v);
}

//void quick_sort(vector<TYPE>& v){
//	queue<size_t> stack;
//	stack.push(0);
//	stack.push(v.size()-1);
//
//	while(stack.size()){
//		size_t l = stack.front(); stack.pop();
//		size_t h = stack.front(); stack.pop();
//		if(l<h){
//			int i_p = _partition_last_element(v,l,h);
//			if(l < i_p-1){
//				stack.push(0 <= l ? l : 0);
//				stack.push(i_p-1 < v.size() ? i_p-1 : v.size()-1 );
//			}
//			if(i_p+1 < h){
//				stack.push(0 <= i_p+1 ? i_p+1 : 0 );
//				stack.push(h < v.size() ? h : v.size());
//			}
//		}
//	}
//	isOrdered(v);
//}

//int _idx_min(vector<TYPE>& v, int i, int j){
//	int idx = i;
//	for(int k = i ; k <= j; k++){ if(cmp(v,idx,k) < 0){ idx = k; } }
//	return idx;
//}
//int _idx_max(vector<TYPE>& v, int i, int j){
//	int idx = i;
//	for(int k = i ; k <= j; k++){ if(cmp(v,idx,k) > 0){ idx = k; } }
//	return idx;
//}

//int _abs(int a){ return 0<=a?a:-a ; }
//
//int _partition_medium(vector<TYPE>& v,const int l,const int h){
//	int i_mn=_idx_min(v,l,h), i_mx=_idx_max(v,l,h);
//	swap(v,l,i_mn);
//	swap(v,h,i_mx);
//	int avg = (v[l].h + v[h].h)/2;
//	int i_p = l+1;
//	for(int i=l+1;i<h;i++){
//		if(_abs(avg - v[i].h)<_abs(avg - v[i_p].h)){
//			i_p=i;
//		}
//	}
//	int c = 0;
//	for(int i=l+1;i<h;i++){
//		if(cmp(v,i,i_p)>=0){
//			c++;
//		}
//	}
//	swap(v,i_p,c+l);
//	i_p=c+l;
//	int i=l+1, j=h;
//	while(i < i_p && i_p < j){
//		while(cmp(v,i,i_p) > 0){ i++; }
//		while(cmp(v,j,i_p) < 0){ j--; }
//		if(i < i_p && i_p < j){
//			swap(v,i,j);
//			i++; j--;
//		}
//	}
//	return i_p;
//}

//void _quick_sort_medium_recursion(vector<TYPE>& v,int l, int h){
//	if(h-l>=3){
//		int i_p = _partition_medium(v,l,h);
//		_quick_sort_medium_recursion(v,l,i_p-1);
//		_quick_sort_medium_recursion(v,i_p+1,h);
//	}
//}

//void insertion_sort(vector<TYPE>& v);
//
//void quick_sort(vector<TYPE>& v){
//	//qcs_b(v,0,v.size()-1);
//	_quick_sort_medium_recursion(v,0,v.size()-1);
//	//insertion_sort(v);
//	isOrdered(v);
//}
//
//void quick_sort_medium(vector<TYPE>& v){
//	_quick_sort_medium_recursion(v,0,v.size()-1);
//	isOrdered(v);
//}
