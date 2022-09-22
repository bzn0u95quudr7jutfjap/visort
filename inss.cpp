#include <vector>
using namespace std;
#include "util.hpp"

void inss(vector<TYPE>& v){
	for(int i = 1; i < v.size(); i++){
		for(int j = 0; j < i; j++){
			if(cmp(v,j,i)<0){
				for(int k = j+1; k < i; k++){
					swapNonGraphic(v,k,i);
				}
				swap(v,j+1,j);
				j = i;
			}
		}
	}
}
