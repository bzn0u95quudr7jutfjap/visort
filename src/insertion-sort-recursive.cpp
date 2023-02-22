#include <vector>
using namespace std;
#include "util.hpp"

void insertionRecursionBody(vector<TYPE>& v, int len, int idx){
	if(len<=0){
		int i = -len;
		int j = i+1;
		if(cmp(v[i],v[j])<0){ swap(v[i],v[j]);}
		if(j>0 && len != 0){ insertionRecursionBody(v,len+1,-1);}
	}else if(idx < len){
			insertionRecursionBody(v,-idx,-1);
			insertionRecursionBody(v,len,idx+1);
	}
}

void insertion_sort_recursive(vector<TYPE>& v){
	insertionRecursionBody(v,v.size()-1,0);
	isOrdered(v);
}
