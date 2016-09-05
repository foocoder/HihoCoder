// ---- Program Info Start----
//FileName:     exam1.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-05 20:36:09
// ---- Program Info End  ----
#include<iostream>
using namespace std;

int changeNumber( int val, int bit){
      int cnt = 0;
      while( val ){
            cnt += val % bit;
            val /= bit;
      }
      return cnt;
}
int gcd( int n, int m){
	while( m ){
          int r = n % m;
          n = m;
          m = r;
    }
      return n;
}
void getAvg( int val){
      int cnt=0;
      for( int i=2; i<val; ++i){
            cnt += changeNumber(val, i);
      }
      int num = val - 2;
      int big, small;
      cnt > num ? (big = cnt, small = num) : (big = num , small = cnt);
      int s = gcd( big, small);
      cnt /= s;
      num /= s;
      cout << cnt << "/"<<num<<endl;
}
int main(){
	int n;
      while(cin >> n){
            getAvg(n);
      }
}
