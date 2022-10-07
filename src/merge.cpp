#include <iostream>
#include <vector>
#include "util.hpp"

using std::printf;

void mergerec(vector<TYPE>& v);
vector<TYPE> copyRange(vector<TYPE>& v, int o, int l);

void mergesort(vector<TYPE>& v){
	printSDL();
	mergerec(v);
	isOrdered(v);
}

vector<TYPE> copyRange(vector<TYPE>& v, int o, int l){
	vector<TYPE> copy;
	for(int i=o; i<l; i++){
		copy.push_back(v[i]);
	}
	return copy;
}

void mergerec(vector<TYPE>& v){
	printf(" size main vec : %d \n",v.size());
	if(v.size() > 1){
		int m = v.size()/2;
		vector<TYPE> v1 = copyRange(v,0,m);
		vector<TYPE> v2 = copyRange(v,m+1,v.size()-m+1);
			printf(" middle punkt : %d \n",m);
			printf(" size v1 vec : %d \n",v1.size());
			printf(" size v2 vec : %d \n",v2.size());
		mergerec(v1);
		mergerec(v2);
		int i=0, j=0, k=0;
		for(int k=0; k<v.size() && i<v1.size() && j<v2.size(); k++){
			if(cmp(v1[i],v2[j],i,j)>0){
				swap(v[k],v1[i],k,i);
				i++;
			}else{
				swap(v[k],v2[j],k,j);
				j++;
			}
		}
	}
}
