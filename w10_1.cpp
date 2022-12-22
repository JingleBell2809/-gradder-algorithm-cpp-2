#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int ans[100][100];
int v,e;

void addedges(int m, int n){
	graph[m][n]=1;
}

void dfs(int visit, int s, int en, vector<int> &visited,int c){
	if(c>0){
		visited[visit]=0;
		if(visit==en){
//			cout<<s<<" "<<en<<endl;
			ans[s][en]=1;
		}
	}else{
		c++;
	}
	for(int i=0;i<v;i++){
		if(visited[i]==1 && graph[visit][i]==1){
			dfs(i,s,en,visited,c);
		}
	}
}

int Start_dfs(int start, int tend){
	vector<int> visited(v,1);
	int count=0;
	dfs(start,start,tend,visited,count);
}

void tran(){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(graph[i][j]==1){
//				cout<<"graph["<<i<<"]["<<j<<"]"<<endl;
				ans[i][j]=1;
			}else{
				Start_dfs(i,j);
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
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
