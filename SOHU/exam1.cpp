// ---- Program Info Start----
//FileName:     exam1.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-21 16:14:41
// ---- Program Info End  ----

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
      string str;
      int m;
      while(getline(cin, str)){
            cin>>m;
            int n =str.size();
            vector<int> digits;
            while( n-- ){
                  digits.push_back( str[n] - '0');
            }
            vector<int> aux = digits;
            sort(aux.begin(), aux.end());
            int size=digits.size();
            if(size == m) {cout<<0<<endl; continue;}
            int cnt = 0;
            while( m--){
                  int rmElem;
                  if( digits[size-1] < digits[size-2] ){
                        rmElem = digits[size-1];
                        if(rmElem == aux[cnt]) cnt++;
                  }
                  else{
                        rmElem = aux[cnt++];
                  }
                  vector<int>::iterator it = find(digits.begin(), digits.end(), rmElem);
                  digits.erase(it);
                  size -- ;
            }
            long long out = 0;
            size = digits.size();
            for( int i=size-1; i>=0; --i ){
                 cout<<digits[i];
            }
            cout<<endl;
            cin.get();
      }
}
