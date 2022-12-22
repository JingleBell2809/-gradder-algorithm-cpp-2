#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> check(101,0);
vector<int> data;

void addedges(int m, int n){
	adj[m].push_back(n);
}

void ver_check(int m, int n){
	if(check[m]==0){
		data.push_back(m);
		check[m]=1;
	}
	if(check[n]==0){
		data.push_back(n);
		check[n]=1;
	}
	addedges(m,n);
}

void dfs(int s, vector<int> &visited){
	cout<<s<<" ";
	visited[s]=0;
	for(int i=0;i<adj[s].size();i++){
		if(visited[adj[s][i]]==1){
			dfs(adj[s][i],visited);
		}
	}
}

void start_dfs(int v){
	sort(data.begin(),data.end());
	vector<int> visited(v,1);
	int line = 1;
	for(int i=0;i<data.size();i++){
		if(visited[data[i]]==1){
			cout<<"L = "<<line<<" : ";
			dfs(data[i],visited);
			cout<<endl;
			line+=1;
		}
	}
	
}

int main(){
	ver_check(0, 1);
	ver_check(0, 2);
	ver_check(1, 0);
	ver_check(1, 2);
	ver_check(2, 0);
	ver_check(2, 1);
	ver_check(3, 4);
	ver_check(3, 5);
	ver_check(4, 3);
	ver_check(4, 5);
	ver_check(5, 3);
	ver_check(5, 4);
	ver_check(6, 7);
	ver_check(6, 8);
	ver_check(7, 6);
	ver_check(7, 8);
	ver_check(8, 6);
	ver_check(8, 7);
	start_dfs(9);
}
