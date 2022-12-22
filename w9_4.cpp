#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];

void addedges(int m, int n){
	adj[m].push_back(n);
}

void DFS(int m, vector<int> &visited){
	cout<<m<<" ";
	visited[m]=0;
	for(int i=0; i<adj[m].size(); i++){
		if(visited[adj[m][i]]!=0){
			DFS(adj[m][i],visited);
		}
	}
}

void start_dfs(int m,int v){
	vector<int> visited(v,1);
	DFS(m,visited);
}

int main(){
	addedges(0,1);
	addedges(0,4);
	addedges(1,2);
	addedges(2,0);
	addedges(2,3);
	addedges(2,4);
	addedges(3,2);
	addedges(3,3);
	addedges(3,4);
	addedges(4,1);
	addedges(4,3);
	start_dfs(0,5);
}
