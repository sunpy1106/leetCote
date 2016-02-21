#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int minSubArrayLen(int s,vector<int> & nums){
			int len = nums.size();
			int sum = 0;
			vector< vector<int> > Sum(len,vector<int>(len));
			for(int i = 0;i<len;i++){
				Sum[i][0]=0;
				sum += nums[i];
			}
			if(sum < s)
				return 0;
			for(int l = 1;l<len;l++){
				for(int i =0; i+l < len ;i++){
					Sum[i][l] = Sum[i][l-1] + nums[i+l-1];
					if(Sum[i][l] >= s){
						return l;
					}
				}	
			}
			return 0;
		}

		int minSubArrayLenByBinarySearch(int s,vector<int> &nums){
			int len = nums.size();
			return subArraySum(1,len,s,nums);

		}

		int subArraySum(int min,int max,int s,vector<int> & nums){
			int sum ;
			//cout<<"Now check "<< min <<","<<max<<endl;
			if(min >= max){
				for(int i=0;i<=nums.size()-max;i++){
					sum = 0;
					for(int j=0;j<max;j++)
						sum += nums[i+j];
					//cout<<"sum = "<<sum<<",s = "<<s<<endl;
					if(sum >= s){
						return max;
					}
				}
				return 0;
			}else{
				bool candivide = false;
				for(int i=0;i<=nums.size()-max;i++){
					sum = 0;
					candivide = false;
					for(int j=0;j<max;j++)
						sum += nums[i+j];
					//cout<<"sum = "<<sum<<",s = "<<s<<endl;
					if(sum >= s){
						candivide = true;
						break;
					}
				}
				if(candivide == true ){
					int res = subArraySum(min,(min+max)/2,s,nums);
					if(res > 0)
						return res;
					else{
						return subArraySum((min+max)/2+1,max,s,nums);
					}
				}else{
					return 0;
				}
			}
		}
};

int main(){
	int n;
	static const int arr[] = {2,3,1,2,4,3};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
	n=7;
	Solution *s = new Solution();
	cout<< s->minSubArrayLen(n,nums)<<endl;
	cout<< s->minSubArrayLenByBinarySearch(n,nums)<<endl;
	return 0;
}
