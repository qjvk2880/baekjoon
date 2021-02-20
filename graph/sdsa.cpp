#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int d[25][25];/*={{0,1,1,0,1,0,0},
			   {0,1,1,0,1,0,1},
			   {1,1,1,0,1,0,1},
			   {0,0,0,0,1,1,1},
			   {0,1,0,0,0,0,0},
			   {0,1,1,1,1,1,0},
			   {0,1,1,1,0,0,0}};*/
bool check[25][25];
vector<int> numofhouse;
int n;
int danji;
bool inside(int x,int y){
	return x>=0&&x<n&&y>=0&&y<n;
}

void bfs(int i,int j,int danji){

	queue<pair<int,int>> q;
	check[i][j]=1;
	q.push(make_pair(i,j));

	int cnt=1;
	while(!q.empty()){
		i=q.front().first;
		j=q.front().second;
		q.pop();
		
		//cout<<y<<" x "<<x<<" y "<<cnt<<" cnt "<<endl;
		for(int k=0;k<4;k++){
			int x=i+dx[k];
			int y=j+dy[k];
			//cout<<next_x<<" x "<<next_y<<" y "<<endl;
		
   		if(inside(x,y)){
         if(d[x][y]==1&&check[x][y]==0){
			  	check[x][y]=1;
			   	q.push(make_pair(x,y));
	  			cnt++;
				
				}
			}
		}
	}
	numofhouse.push_back(cnt);

	
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&d[i][j]);
    }
}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]==1&&check[i][j]==false){
				danji++;
				bfs(i,j,danji);
				
			}
		}
	}
  sort(numofhouse.begin(),numofhouse.end());
	cout<<numofhouse.size()<<endl;
  for(int x:numofhouse)
  cout<<x<<endl;
}

