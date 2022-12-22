#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> check(101,1);
vector<int> data;
vector<int> tstack;

void addedges(int m, int n){
	adj[m].push_back(n);
}

void ver_check(int m, int n){
	if(check[m]==1){
		data.push_back(m);
		check[m]=0;
	}
	if(check[n]==1){
		data.push_back(n);
		check[n]=0;
	}
	addedges(m,n);
}

void dfs(int s, vector<int> &visited){
	visited[s]=0;
	for(int i=0;i<adj[s].size();i++){
		if(visited[adj[s][i]]==1){
			dfs(adj[s][i],visited);
		}
	}
//	cout<<s<<" ";
	tstack.push_back(s);
}

void start_dfs(int v){
	vector<int> visited(v,1);
//	cout<<"Start::"<<endl;
	for(int i=0;i<data.size();i++){
		if(visited[data[i]]==1){
			dfs(data[i],visited);
		}
	}
//	cout<<endl<<endl<<endl<<endl;
//	cout<<tstack.size()<<endl<<endl;
	for(int i=tstack.size()-1;i>=0;i--){
		cout<<tstack[i]<<" ";
	}
}

int main(){
	ver_check(5, 2);
	ver_check(5, 0);
	ver_check(4, 0);
	ver_check(4, 1);
	ver_check(2, 3);
	ver_check(3, 1);
	sort(data.begin(),data.end());
	start_dfs(6);
}
