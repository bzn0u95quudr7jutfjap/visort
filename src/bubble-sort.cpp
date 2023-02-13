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
