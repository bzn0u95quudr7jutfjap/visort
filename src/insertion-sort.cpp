#include <vector>
using namespace std;
#include "util.hpp"

void insertion_sort(vector<TYPE>& v){
	for(int i = 1; i < v.size(); i++){
		for(int j=i-1; j>=0 && isGreater(v[j],v[j+1]); j--){
			swap(v[j],v[j+1]);
		}
	}
	isOrdered(v);
}
