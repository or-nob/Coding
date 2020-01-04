//eular path
#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int>G[100];
int in[100], out[100];

bool isEularPathExists(){
	int end_cnt = 0, strt_cnt = 0;
	for(int i = 0; i < n; i++){
		if(out[i]-in[i]>1||in[i]-out[i]>1){
			return false;
		}
		else if(out[i]-in[i]==1)end_cnt++;
		else if(in[i]-out[i]==1)strt_cnt++;
	}
	return (end_cnt==0&&strt_cnt==0)||(end_cnt==1&&strt_cnt==1);
}

int strtNode(){
	int node = 0;
	for(int i = 0; i < n; i++){
		if(out[i]-in[i]==1){
			node = i;
		}
		else if(out[i]>1)node = i;
	}
	return 0;
}

vector<int>res;
int visited[100][100];
void dfs(int u){
	while(out[u]!=0){
		out[u]--;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if(visited[u][v]>0){
				visited[u][v]--;
				dfs(v);
			}
		}
	}
	res.push_back(u);
}

int main() {
	cin>>n>>e;
	for(int i = 0; i < e; i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		visited[u][v]++;
		out[u]++;
		in[v]++;
	}
	if(isEularPathExists()){
		int strt_node = strtNode();	
		dfs(strt_node);
		for(int i = res.size()-1; i >= 0; i--){
			cout<<res[i]<<" ";
		}
	}
	return 0;
}