#include <iostream>
#include <vector>
#include "util.hpp"

void _merge_sort_inplace_move(vector<TYPE>& v,int i, int j){
	while(i < j){
		swap(v,j-1,j);
		j--;
	}
}

void _merge_sort_inplace_merge(vector<TYPE>& v,int i, int j, int k){
	k = k < v.size() ? k : v.size();
	while(i<j && j<k){
		if(cmp(v,i,j)<0){
			_merge_sort_inplace_move(v,i,j);
			j++;
			i++;
		}else{
			i++;
		}
	}
}

void _merge_sort_inplace_recurion(vector<TYPE>& v, int l, int h){
	if(h-l>=2){
		int m = (h+l)/2;
		_merge_sort_inplace_recurion(v,l,m);
		_merge_sort_inplace_recurion(v,m,h);
		_merge_sort_inplace_merge(v,l,m,h);
	}
}

void merge_sort_inplace_recursive(vector<TYPE>& v){
	printSDL();
	_merge_sort_inplace_recurion(v,0,v.size());
	isOrdered(v);
}

void merge_sort_inplace_iterative(vector<TYPE>& v){
	printSDL();
	for(int len = 1; len < v.size(); len*=2){
		for(int i=0; i < v.size(); i+=len*2){
			_merge_sort_inplace_merge(v,i,i+len,i+len*2);
		}
	}
	isOrdered(v);
}

void _merge_sort_copy_merge(vector<TYPE>& v,int i,int j,int k){
	k = k < v.size() ? k : v.size();
	vector<TYPE> proxy(k-i);
	int idx = i;
	int jdx = j;
	int a = 0;
	while(a < proxy.size() && idx < j && jdx < k){
		proxy[a++]=v[ cmp(v,idx,jdx)>0 ? idx++ : jdx++ ];
	}
	while(a < proxy.size() && idx < j){
		proxy[a++] = v[idx++];
	}
	while(a < proxy.size() && jdx < k){
		proxy[a++] = v[jdx++];
	}
	for(int a=0; a<proxy.size(); a++){
		v[i+a].y = proxy[a].y;
		v[i+a].h = proxy[a].h;
		swap(v,i+a,i+a);
	}
}

void _merge_sort_copy_recurion(vector<TYPE>& v,int l, int h){
	if(h-l>=2){
		int m = (h+l)/2;
		_merge_sort_copy_recurion(v,l,m);
		_merge_sort_copy_recurion(v,m,h);
		_merge_sort_copy_merge(v,l,m,h);
	}
}

void merge_sort_copy_recursive(vector<TYPE>& v){
	printSDL();
	_merge_sort_copy_recurion(v,0,v.size());
	isOrdered(v);
}

void merge_sort_copy_iterative(vector<TYPE>& v){
	printSDL();
	for(int len = 1; len < v.size(); len*=2){
		for(int i=0; i < v.size(); i+=len*2){
			_merge_sort_copy_merge(v,i,i+len,i+len*2);
		}
	}
	isOrdered(v);
}

void merge_sort_copy_iterative_post(vector<TYPE>& v){
	printSDL();
	vector<TYPE> proxy(v.size());
	for(int len = 1; len < v.size(); len*=2){
		for(int a=0; a < v.size(); a+=len*2){
			int b = a;
			int i = a, idx = i;
			int j = i+len, jdx = j;
			int k = i+len*2	< v.size() ? i+len*2 : v.size();
			while(idx < j && jdx < k && a < k){
				proxy[b++] = v[cmp(v,idx,jdx)>0 ? idx++ : jdx++];
			}
			while(b < proxy.size() && idx < j){
				proxy[b++] = v[idx++];
			}
			while(b < proxy.size() && jdx < k){
				proxy[b++] = v[jdx++];
			}
		}
		for(int i=0; i < v.size(); i++){
			v[i].y = proxy[i].y;
			v[i].h = proxy[i].h;
			swap(v,i,i);
		}
	}
	isOrdered(v);
}
