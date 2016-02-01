#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int status = 0;
        stringstream ss;
        for(vector<int>::iterator it = nums.begin() ;it < nums.end();it++){
            if(status == 0){
                ss<<*it;
                if(it < nums.end()-1){
                    if(*(it+1) == *it + 1){
                        status = 1;
                        ss<<"->";
												cout<<"part 1"<<endl;
                    }else{
                        res.push_back(ss.str());
												cout<<"part 2"<<endl;
												cout<<ss.str()<<endl;
												ss.str("");
                    }
                }else{
                    res.push_back(ss.str());
										cout<<"part 3 "<<endl;
										cout<<ss.str()<<endl;
										ss.str("");
                }
            }else if(status == 1){
                if(it < nums.end()-1){
                    if(*(it+1) != *it + 1){
                        ss<<*it;
                        status = 0;
                        res.push_back(ss.str());
												cout<<"part 4"<<endl;
												cout<<ss.str()<<endl;
												ss.str("");
                    }
                }else{
                    ss<<*it;
                    res.push_back(ss.str());
										cout<<"part 5"<<endl;
										cout<<ss.str()<<endl;
										ss.str("");
                }
                
            }
        }
        for(vector<string>::iterator it = res.begin();it!=res.end();it++){
            cout<<*it<<endl;
        }
        return res;
        
    }
};


int main(){
    Solution *so  = new Solution();
    static const int arr[] = {0,1,2,4,5,7};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    so->summaryRanges(nums);
    return 0;
}
