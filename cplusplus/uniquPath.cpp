#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int uniquePaths(int m,int n){
			int a[100][100];
			for(int j = 0;j < n;j++){
				a[m-1][j] = 1;
			}
			for(int i = 0;i<m;i++){
				a[i][n-1]=1;
			}
			for(int i = 1;i<m;i++){
				for (int j =1 ;j<n;j++){
					a[m-1-i][n-1-j]= a[m-i][n-j-1] + a[m-i-1][n-j];
				}
			}
			return a[0][0];
		}


};

int main(){
	Solution *s = new Solution();
	cout<<s->uniquePaths(8,8)<<endl;
	return 0;
}
