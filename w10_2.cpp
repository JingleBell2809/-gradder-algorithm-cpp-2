#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int v,e;

void addedges(int m, int n){
	graph[m][n]=1;
}

void tran(){
	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				if(graph[i][j]==1 || (graph[i][k]==1 && graph[k][j]==1)){
					graph[i][j]=1;
				}
			}
		}
	}
}

int main(){
	v=4;
	addedges(0, 1);
	addedges(0, 2);
	addedges(1, 2);
	addedges(2, 0);
	addedges(2, 3);
	tran();
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}
