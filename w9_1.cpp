#include <bits/stdc++.h>
using namespace std;

int adj[4][4]={{0,5,7,6},
			 {0,0,8,0},
			 {0,0,0,4},
			 {0,3,0,0}};
int v = 4 ,e = 6;

int main(){
	for(int i=0;i<v;i++){
		cout<<i<<" : ";
		for(int j=0;j<v;j++){
			if(adj[i][j]!=0){
				cout<<j<<"="<<adj[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}
