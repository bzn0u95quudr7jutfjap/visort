#include <vector>
#include <iostream>
#include "util.hpp"
using namespace std;

//COPIATO DA GEEKOFGEEKS
void qcs_b(vector<TYPE>& v,int l, int h){
	if(l < h){
		int pi;
		{
			pi = l;
			int c = 0;
			for(int i = l+1; i <= h; i++){
				if(cmp(v,i,pi)>=0){
					c++;
				}
			}
			pi = l+c;
			swap(v,pi,l);
		}
		{
			int i = l, j = h;
			while(i < pi && j > pi){
				while(cmp(v,i,pi) > 0){ i++; }
				while(cmp(v,j,pi) < 0){ j--; }
				if(i < pi && pi < j){
					swap(v,i,j);
					i++; j--;
				}
			}
		}
		qcs_b(v,l,pi-1);
		qcs_b(v,pi+1,h);
	}
}

void quick_sort(vector<TYPE>& v){
	qcs_b(v,0,v.size()-1);
	isOrdered(v);
}
