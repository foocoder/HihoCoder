// ---- Program Info Start----
//FileName:     pock.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-17 20:02:29
// ---- Program Info End  ----

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void getSeq( vector<int> & seq, int n, int k ){
    vector<int> aux = seq;
    int gap;
    int tmp = pow(2,k);
    if( tmp < n )
        gap = tmp;
    else{
        tmp = 2;
        for( int i=1; i<k ; ++i){
            tmp = tmp + tmp;
            if( tmp >=n )
                tmp++;
            tmp %= n;
        }
        gap = tmp;
    }
    int index = 0;
    for( int i=1; i<n; ++i ){
        index = (index + gap);
        if( index >= n ) index ++;
        index = index % n;
        seq[index] = aux[i];
    }
    for( int i=0; i<n; ++i ){
        if(i!=n-1)
            cout<<seq[i]<<" ";
        else
            cout<<seq[i]<<endl;
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>> pocks;
    vector<int> vecM,vecK;
    for(int i=0; i<n; ++i){
        int m,k,a;
        vector<int> tmp;
        cin>>m>>k;
        vecM.push_back(2*m);
        vecK.push_back(k);
        for( int j=0; j<2*m; ++j ){
            cin>>a;
            tmp.push_back(a);
        }
        pocks.push_back( tmp );
    }
    for( int i=0; i<n; ++i ){
        getSeq( pocks[i], vecM[i], vecK[i] );
    }
    return 0;
}
