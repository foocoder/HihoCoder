// ---- Program Info Start----
//FileName:     FindMostZeroSubArr.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-17 14:48:49
// ---- Program Info End  ----
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> subarraySumClosest(vector<int> nums){
    // write your code here
    int n = nums.size();
    int dp;
    int gap = 0xFFFFFFFF,indexi = -1, indexj=-1;
    for( int i=0; i<n; ++i ){
        dp = nums[i];
        int k = nums[i];
        k = k>0 ? k : -k;
        if(k<gap){
            gap = k;
            indexi = i;
            indexj = i;
        }
        for( int j=i+1; j<n; ++j ){
            dp += nums[j];
            k = dp;
            k = k>0 ? k : -k;
            if( k<gap){
                gap = k;
                indexi = i;
                indexj = j;
            }
        }
    }
    return vector<int>{indexi,indexj};
}

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);
    vector<int> nums;
    int n;
    while( input>>n ){
        nums.push_back(n);
    }
    for( auto i:nums)
        cout<<i<<" ";
    cout<<endl;
    vector<int> rs = subarraySumClosest(nums);
    for( auto i:rs)
        cout<<i<<" ";
    return 0;
}
