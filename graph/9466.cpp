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
	if(visit[next]==false) dfs(next); // 방문하지 않았으면 탐색
	else if(check[next]==false){// 방문 했는데 사이클을 만드는 중이다?
		for(int i=next;i!=start;i=v[i][0]){
			//노드 전까지 순환 돈다. dfs이기 때문에 4-7-6-8 순이면 8에서 4까지 간다음에 다시 4에서 for문이 실행된다.
			cnt++;
			
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
			scanf("%d",&u);
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
