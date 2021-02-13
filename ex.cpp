#include <iostream>
using namespace std;
int arr[1001];
int d[1001];
void solve(int n){
	
	for(int i=1;i<=n;i++){
		d[i]=arr[i];
		for(int j=1;j<i;j++){
			if(arr[i]>arr[j]&&d[j]+arr[i]>d[i])
				d[i]=d[j]+arr[i];
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	solve(n);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,d[i]);
	}
	cout<<ans;
}
