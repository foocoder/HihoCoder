// ---- Program Info Start----
//FileName:     exam2.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-17 20:08:54
// ---- Program Info End  ----

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
      int n;
      while( cin >> n){
            int mat[n][n];
            char c;
            for( int i=0; i<n; ++i){
                  for( int j=0; j<n; ++j){
                        cin>>mat[i][j];
                        cin.get(c);
                  }
            }
            //Prim
            vector<int> inGroup, outGroup;
            vector<int> cost(n,0);
            inGroup.reserve(n);
            outGroup.reserve(n);
            inGroup.push_back(0);
            for( int i=1; i<n; ++i){
                  outGroup.push_back(i);
                  cost[i] = mat[0][i];
            }
            int cnt = 0;
            for( int i=1; i<n; ++i){
                  int min = 0x7FFFFFFF;
                  int idx = -1;
                  for( int i:outGroup){
                        if( cost[i] < min ){
                              min = cost[i];
                              idx = i;
                        }
                  }
                  cnt += min;
                  vector<int>::iterator iter = find(outGroup.begin(), outGroup.end(), idx);
                  outGroup.erase(iter);
                  for( int i:outGroup){
                        if( cost[i] > mat[idx][i])
                              cost[i] = mat[idx][i];
                  }
            }
            cout<<cnt<<endl;
      }
}
