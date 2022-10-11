#include <iostream>
#include <vector>
#include "util.hpp"

using std::printf;

void mergerec(vector<TYPE>& v, int l, int h){
	if(h-l>=1){
		int m = (h+l)/2;
		mergerec(v,l,m);
		mergerec(v,m+1,h);
		for(int i = l, j=m+1; i<j && j<=h;){
			if(cmp(v,i,j)<0){
				for(int z=j; z>i; z--){
					swap(v,z,z-1);
				}
				j++;
			}
			i++;
		}
	}
}

void mergesort(vector<TYPE>& v){
	printSDL();
	mergerec(v,0,v.size()-1);
	isOrdered(v);
}
