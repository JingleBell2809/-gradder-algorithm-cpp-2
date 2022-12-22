#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > adj[101];
vector<int> visited(101,1);
vector<int> que;
vector<int> sto;
vector<int> tfirst;
vector<int> tend;

void addedges(int m, int n, int dis){
	adj[m].push_back(make_pair(n,dis));
}

void check_node(int m, int n, int dis){
	if(visited[m]==1){
		visited[m]=0;
		que.push_back(m);
	}
	if(visited[n]==1){
		visited[n]=0;
		que.push_back(n);
	}
	addedges(m,n,dis);
}

void prim(){
	int min,s_node,e_node;
	for(int k=0;k<que.size()-1;k++){
		min=999999;
		s_node=-1;
		e_node=-1;
		for(int i=0;i<sto.size();i++){
//			cout<<"sto[i] : "<<sto[i]<<" ; ";
			for(int j=0;j<adj[sto[i]].size();j++){
//				cout<<adj[sto[i]][j].first<<" = "<<adj[sto[i]][j].second<<" | ";
				if(min>=adj[sto[i]][j].second && visited[adj[sto[i]][j].first]==1){
					min=adj[sto[i]][j].second;
					s_node=sto[i];
					e_node=adj[sto[i]][j].first;
				}
			}
//			cout<<endl;
		}
//		cout<<s_node<<" "<<e_node;
//		cout<<" "<<adj[que[s_node]][e_node].second;
//		cout<<endl;
		visited[e_node]=0;
		sto.push_back(e_node);
		tfirst.push_back(s_node);
		tend.push_back(e_node);
	}
}

int main(){
	check_node(0, 1, 4);
	check_node(0, 7, 8);
	check_node(1, 0, 4);
	check_node(1, 2, 8);
	check_node(1, 7, 11);
	check_node(2, 1, 8);
	check_node(2, 3, 7);
	check_node(2, 5, 4);
	check_node(2, 8, 2);
	check_node(3, 2, 7);
	check_node(3, 4, 9);
	check_node(3, 5, 14);
	check_node(4, 3, 9);
	check_node(4, 5, 10);
	check_node(5, 2, 4);
	check_node(5, 3, 14);
	check_node(5, 4, 10);
	check_node(5, 6, 2);
	check_node(6, 5, 2);
	check_node(6, 7, 1);
	check_node(6, 8, 6);
	check_node(7, 0, 8);
	check_node(7, 1, 11);
	check_node(7, 6, 1);
	check_node(7, 8, 7);
	check_node(8, 2, 2);
	check_node(8, 6, 6);
	check_node(8, 7, 7);
	sort(que.begin(),que.end());
	for(int i=0;i<que.size();i++){
		visited[que[i]]=1;
	}
	sto.push_back(0);
	visited[0]=0;
	prim();
	int n=9,min;
	for(int i=0;i<tend.size()-1;i++){
		min = i;
		for(int j=i+1;j<tend.size();j++){
			if(tend[min]>tend[j]){
				min = j;
			}
		}
		int t = tend[min];
		tend[min] = tend[i];
		tend[i] = t;
		t = tfirst[min];
		tfirst[min] = tfirst[i];
		tfirst[i] = t;
	}
	for(int i=0;i<tend.size();i++){
		cout<<tfirst[i]<<" "<<tend[i]<<endl;
	}
}
