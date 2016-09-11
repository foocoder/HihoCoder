// ---- Program Info Start----
//FileName:     exam1.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-11 20:48:00
// ---- Program Info End  ----

#include <iostream>
#include <vector>
using namespace std;

void getbin( int n, int s, int e, int acc, vector<int>&bin){
    if( acc == 6 )
        return;
    int mid = (s+e) /2;
    if( mid == n ){
        bin.push_back(1);
        return ;
    }
    if( mid>n ){
        bin.push_back(0);
        getbin(n, s, mid-1, acc+1, bin);
    }
    if( mid<n){
        bin.push_back(1);
        getbin(n, mid, e, acc+1, bin);
    }
}

int main(int argc, char *argv[])
{
    int n;
    while(cin>>n)
    {
        vector<int> bin;
        getbin(n+90, 0, 180, 0, bin);
        int m =bin.size();
        for( int i=0; i<m; ++i )
            cout<<bin[i];
        cout<<endl;
    }
    return 0;
}
