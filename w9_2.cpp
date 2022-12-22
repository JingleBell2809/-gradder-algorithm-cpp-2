#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > test[101];
int v,e;

void addedges(int m, int n, int dis){
	test[m].push_back(make_pair(n,dis));
}

void print(){
	for(int i=0;i<v;i++){
		cout<<i<<" : ";
		for(int j=0;j<test[i].size();j++){
			cout<<test[i][j].first<<"="<<test[i][j].second<<" ";
		}
		cout<<endl;
	}
}

int main(){
	v=4;
	e=6;
	addedges(0,1,5);
	addedges(0,2,7);
	addedges(0,3,6);
	addedges(1,2,8);
	addedges(2,3,4);
	addedges(3,1,3);
	print();
}
