#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
vector<int> v[100001];
int n;
bool check[100001];
bool visit[100001];
int cnt;
		
void dfs(int start){
	visit[start]=true;
	
	int next=v[start][0];
	if(visit[next]==false) dfs(next);
	else if(check[next]==false){
		for(int i=next;i!=start;i=v[i][0]){
			
			cnt++;
			//cout<<"i = "<<i<<" next= "<<next<<endl;
		}
		cnt++;
	}
	
	check[start]=true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int u;
			cin>>u;
			v[i].push_back(u);
		}
		
		cnt=0;
		
		for(int i=1;i<=n;i++){
			if(visit[i]==false){
				dfs(i);
				
			}
		}
		
		cout<<n-cnt<<endl;
		
		memset(check,0,sizeof(check));
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=n;i++) v[i].clear();
	}
}
