#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
			int a[100][100];
			int m ,n;
			m = obstacleGrid.size();
			n = obstacleGrid[0].size();
			if(1 != obstacleGrid[m-1][n-1])
			    a[m-1][n-1] = 1;
			else
				a[m-1][n-1]=0;
			for(int i =1;i<m;i++){
				if(1 == obstacleGrid[m-i-1][n-1])
					a[m-i-1][n-1]=0;
				else
					a[m-i-1][n-1] = a[m-i][n-1];
			}

			for(int j=1;j<n;j++){
				if(1== obstacleGrid[m-1][n-j-1]){
					a[m-1][n-j-1]=0;
				}else{
					a[m-1][n-j-1] = a[m-1][n-j] ;
				}
			}

			for(int i=1;i<m;i++){
				for(int j=1;j<n;j++){
					if(1==obstacleGrid[m-i-1][n-j-1])
						a[m-i-1][n-j-1] = 0;
					else
						a[m-i-1][n-j-1] = a[m-i][n-j-1] + a[m-i-1][n-j];
				}
			}

			return a[0][0];
		}
};

int main(){
	vector<vector<int> > a(1,vector<int>(1));
	a[0][0]=1;
	Solution *s = new Solution();
	cout<<s->uniquePathsWithObstacles(a)<<endl;
	return 0;

}
