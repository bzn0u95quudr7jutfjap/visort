#include <vector>
#include "util.hpp"
using namespace std;

void easy_sort(vector<TYPE>& v){
	for(int i = 0; i < v.size() ; i++){
		for(int j = i; j < v.size(); j++){
			if(isGreater(v[i],v[j])){
				swap(v[i],v[j]);
			}
		}
	}
	isOrdered(v);
}
