#include <vector>
using namespace std;
#include "util.hpp"

void insertionRecursionBody(vector<TYPE>& v, int len, int idx){
	int i,j;
	if(len<0){
		i = -len;
		j = i+1;
		if(cmp(v,i,j)<0){ swap(v,i,j);}
		if(j>0){ insertionRecursionBody(v,len+1,-1);}
	}else if(len > 0){
		if(len >0 && idx < len){
			insertionRecursionBody(v,-idx,-1);
			insertionRecursionBody(v,len,idx+1);
		}
	}else{
		i = len;
		j = i+1;
		if(cmp(v,i,j)<0){ swap(v,i,j);}
	}
}

void insRec(vector<TYPE>& v){
	insertionRecursionBody(v,v.size()-1,0);
	isOrdered(v);
}
