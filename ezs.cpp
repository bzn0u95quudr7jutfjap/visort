#include <vector>
#include "util.hpp"
using namespace std;

void ezs(vector<TYPE>& v){
	for(int i = 0; i < v.size() ; i++){
		for(int j = i; j < v.size(); j++){
			if(cmp(v,i,j)<0){
				swap(v,i,j);
			}
		}
	}
}
