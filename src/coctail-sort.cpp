#include <vector>
#include "util.hpp"
using namespace std;

//void cocktail_sort(vector<TYPE>& v){
//	while(!isOrdered(v)){
//		for(int i = 0; i < v.size()-1; i++){
//			int j = i+1;
//			if(isGreater(v[i],v[j])){
//				swap(v[i],v[j]);
//			}
//		}
//		for(int i = v.size()-2; i >=0 ; i--){
//			int j = i+1;
//			if(isGreater(v[i],v[j])){
//				swap(v[i],v[j]);
//			}
//		}
//	}
//}

void cocktail_sort(vector<TYPE>& v){
	for(int i=0,j=v.size();i<j;i++,j--){
		for(int k=i+1;k<j;k++){
			if(isGreater(v[k-1],v[k])){
				swap(v[k-1],v[k]);
			}
		}
		for(int k=j-1;k>i;k--){
			if(isGreater(v[k-1],v[k])){
				swap(v[k-1],v[k]);
			}
		}
	}
	isOrdered(v);
}
