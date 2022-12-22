#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> que;

void addedges(int m, int n){
	adj[m].push_back(n);
}

void BFS(vector<int> visited){
	while(que.size()!=0){
		int s = que[0];
		cout<<s<<" ";
		que.erase(que.begin());
		visited[s];
		for(int i=0; i<adj[s].size(); i++){
			if(visited[adj[s][i]]!=0){
				que.push_back(adj[s][i]);
				visited[adj[s][i]]=0;
			}
		}
	}
}

void start_bfs(int m, int v){
	vector<int> visited(v,1);
	que.push_back(m);
	visited[m]=0;
	BFS(visited);
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
	start_bfs(0,5);
}
