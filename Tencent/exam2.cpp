// ---- Program Info Start----
//FileName:     exam2.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-11 20:57:25
// ---- Program Info End  ----

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isZhishu( int n){
    int s = sqrt(n);
    for( int i=2; i<=s; ++i){
        if( n%i == 0 ) return false;
    }
    return true;
}
void getZhishu( int n, vector<int> & zhishu){
    for( int i=2; i<=n; ++i ){
        if( isZhishu(i) )
        {
            zhishu.push_back(i);
            cout<<i<<",";
        }
    }
    cout<<endl;
}
int getRes( int n ){
    if( n==1 ) return 0;
    if( n==2 ) return 1;
    vector<int> zhishu;
    getZhishu( n, zhishu);
    int m = zhishu.size();
    int dp[m][n+1];
    dp[0][2] = 1;
    for( int i=1; i<m; ++i ){
        dp[i][2] = 1;
    }
    for( int i=3;i<=n; ++i ){
        dp[0][i] = i&1;
    }
    for( int i=1; i<m; ++i ){
        int p = zhishu[i];
        for( int j=3; j<=n; ++j){
            if(j-p>=2){
                dp[i][j] = dp[i-1][j] + dp[i][j-p];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m-1][n];
}
int main(int argc, char *argv[])
{
    int n;
    for(int i=1; i<=10; ++i)
        cout<<i<<","<<getRes(i)<<endl;
    return 0;
}
