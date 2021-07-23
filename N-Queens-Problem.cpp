#include <bits/stdc++.h>
using namespace std;
#define CHESS_BOARD_SIZE 8
bool check(int x1,int y1,int x2,int y2){
	if(x1==x2 || y1==y2 || abs(x2-x1)==abs(y2-y1)){
		return false;
	}
	return true;
}
int NQueens(vector<pair<int,int> > a,int index){
	if(index>=CHESS_BOARD_SIZE){
		return 1;
	}
	int temp=0;
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		bool flag=1;
		for(int j=0;j<a.size();j++){
			if(!check(a[j].first,a[j].second,index,i)){
				flag=0;
				break;
			}
		}
		if(flag){
			a.push_back(make_pair(index,i));
			temp+=NQueens(a,index+1);
			a.pop_back();
		}
	}
	return temp;
}
int main(){
	int temp=0,index=0;
	vector<pair<int,int> > a;
	for(int j=0;j<CHESS_BOARD_SIZE;j++){
		a.push_back(make_pair(0,j));
		temp+=NQueens(a,index+1);
		a.pop_back();
	}
	cout<<temp;
	return 0;
}

