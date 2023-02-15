#include <vector>
using namespace std;
#include "util.hpp"

void insertion_sort(vector<TYPE>& v){
	for(int i = 1; i < v.size(); i++){
		for(int j=i-1; j>=0 && cmp(v,j,j+1)<0; j--){
			swap(v,j,j+1);
		}
	}
	isOrdered(v);
}
