#include <vector>
#include <iostream>
#include "util.hpp"

using namespace std;

void bubble_sort(vector<TYPE>& v){
	while(!isOrdered(v)){
		for(int i = 0; i < v.size()-1; i++){
			int j = i+1;
			if(cmp(v,i,j)<0){
				swap(v,i,j);
			}
		}
	}
}

void bubble_sort_optimized(vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		for(int j=1;j<v.size()-i;j++){
			if(cmp(v,j-1,j)<0){
				swap(v,j-1,j);
			}
		}
	}
	isOrdered(v);
}
