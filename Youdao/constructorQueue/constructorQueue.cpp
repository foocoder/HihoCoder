// ---- Program Info Start----
//FileName:     constructorQueue.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-17 19:29:47
// ---- Program Info End  ----

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, int> dict;

void constructQueue( int n ){
    queue<int> Q;
    dict tmp;
    for( int i=1; i<=n; ++i ){
        Q.push( i );
    }
    int cnt = 1;
    while( !Q.empty()){
        int x = Q.front();
        Q.pop();
        Q.push(x);
        x = Q.front();
        tmp.emplace( x, cnt++ );
        Q.pop();
    }
    for( int i=1; i<=n; ++i ){
        cout<<tmp[i]<<" ";
    }
    cout<<"\b"<<endl;
}

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0; i<n; ++i){
        cin>>num[i];
    }
    for(int i=0; i<n; ++i){
        constructQueue(num[i]);
    }

    return 0;
}
