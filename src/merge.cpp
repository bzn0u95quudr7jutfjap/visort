#include <iostream>
#include <vector>
#include "util.hpp"

void mergerec(vector<TYPE>& v);
vector<TYPE> copyRange(vector<TYPE>& v, int o, int l);

void mergesort(vector<TYPE>& v){
	printSDL();
	mergerec(v);
	isOrdered(v);
}

vector<TYPE> copyRange(vector<TYPE>& v, int o, int l){
	vector<TYPE> copy(l);
	for(int i=o; i<l; i++){
		copy.push_back(v[i]);
	}
	return copy;
}

void mergerec(vector<TYPE>& v){
	std::printf("ewewfwgwjn\n");
	if(v.size() > 1){
		int m = v.size()/2;
		vector<TYPE> v1 = copyRange(v,0,m+1);
		vector<TYPE> v2 = copyRange(v,m+1,v.size()-m+1);
		mergerec(v1);
		mergerec(v2);
		int i=0, j=0, k=0;
		for(int k=0; k<v.size(); k++){
			if(cmp(v1[i],v2[j],i,j)>0){
				v[k]=v1[i];
				i++;
			}else{
				v[k]=v2[j];
				j++;
			}
		}
	}
}
