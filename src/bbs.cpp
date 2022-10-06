#include <vector>
#include <iostream>
#include "util.hpp"

using namespace std;

void bbs(vector<TYPE>& v){
	bool to_order = true;
	while(to_order){
		to_order=false;
		for(int i = 0; i < v.size()-1; i++){
			int j = i+1;
			if(cmp(v,i,j)<0){
				swap(v,i,j);
				to_order = true;
			}
		}
	}
}
