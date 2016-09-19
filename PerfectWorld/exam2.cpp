// ---- Program Info Start----
//FileName:     exam2.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-19 20:12:20
// ---- Program Info End  ----

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> solve( int start, int end,const vector<int>& s, const vector<int>&e, const vector<int> &v){
      int n = s.size();
      int map[n][n], path[n][n], dist[n][n];
      for( int i=0; i<n; ++i){
            for( int j=0; j<n; ++j){
                  map[i][j] = -1;
                  path[i][j] = -1;
                  dist[i][j] = -1;
            }
      }
      for( int i=0; i<n; ++i){
            map[s[i]][e[i]] = v[i];
            dist[s[i]][e[i]] = v[i];
      }
      for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
          if(map[i][j]==-1){
               path[i][j] = -1;
          }else{
               path[i][j] = s[i];
          }
        }
      }
      for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
          for(int j=0; j<n; j++) {
            if(!(dist[i][k]==-1||dist[k][j]==-1)&&dist[i][j] > dist[i][k] + dist[k][j]) {
              dist[i][j] = dist[i][k] + dist[k][j];
              path[i][k] = s[i];
              path[i][j] = path[k][j];
            }
          }
        }
      }
      vector<int >res;
    while( path[start][end] !=start){
        res.push_back(path[start][end]);
        end = path[start][end];
    }
    return res;
}
int main(int argc, char *argv[])
{
    string str;
    vector<int> s, e, v;
    int startv, endv;
    while( getline(cin, str) ){
        istringstream iss(str);
        int cnt = 0;
        int start, end, val;
        iss>>start>>end;
        if( (iss>>val) )
        {
            s.push_back(start);
            e.push_back(end);
            v.push_back(val);
        }
        else{
            if(!s.empty()){
                vector<int> res = solve(start, end, s, e, v);
                for( int i:res){
                    cout<<i<<"...";
                }
            }
            s.clear();
            e.clear();
            v.clear();
            startv = start;
            endv = end;
        }
    }
    cout<<startv<<","<<endv<<endl;
    int n = s.size();
    for( int i=0; i<n; ++i){
        cout<<s[i]<<"-"<<e[i]<<"-"<<v[i]<<endl;
    }
    return 0;
}
