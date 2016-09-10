// ---- Program Info Start----
//FileName:     exam1.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-10 20:41:33
// ---- Program Info End  ----

#include <iostream>
#include <cstring>

using namespace std;

void getNext( char * pat, int * next, int n ){
      next[0] = -1;
      int i=-1, j=0;
      while (j < n - 1){
            if (i == -1 || pat[j] == pat[i]){
            	++i,++j;
            	next[j] = i;
        	}
        	else
            	i = next[i];
      }
}
int kmp(char* txt, char* pat)
{
      int i = 0, j=0, nTxt = strlen(txt), nPat = strlen(pat);
      int next[nPat];
      getNext(pat, next, nPat);
      while (i < nTxt && j < nPat){
            if (j == -1 || txt[i] == pat[j]){
                  i++, j++;
            }
            else
                  j = next[j];
      }
      if (j == nPat)
            return i - j;
      else
            return -1;
}
void inverseStr( char * str, char * istr, int n ){
      for(int i=0; i<n; ++i){
            istr[i] = str[n-i-1];
      }
}
int getDirection( char * str1, char * str2, char * str3){
	  int n = strlen(str1), n2=strlen(str2), n3=strlen(str3);
      char istr[n+1];
      inverseStr( str1, istr, n);

      int directFir = kmp(str1, str2);
      int directSec;
      bool forward = false, backward =false;
      if( directFir != -1 ){
             directSec = kmp(str1+directFir+n2, str3);
             if( directSec != -1) forward = true;
      }
      int inversFir = kmp(istr, str2);
      int inversSec;
      if( inversFir != -1){
             inversSec = kmp(istr+inversFir+n2, str3);
             if(inversSec != -1) backward = true;
      }
	  if( forward && backward) return 0;
      if( forward && !backward) return 1;
      if( !forward && backward) return 2;
      if( !forward && !backward) return 3;
      return -1;
}
int main(){
      string str;
      while( cin>>str ){
          int n = str.size();
          char str1[n+1];
          for( int i = 0; i<n; ++i)
            str1[i] = str[i];
          str1[n] = '\0';

          cin>>str;
          int n2 = str.size();
          char str2[n2+1];
          for( int i = 0; i<n2; ++i)
            str2[i] = str[i];
          str2[n2] = '\0';

          cin>>str;
          int n3 = str.size();
          char str3[n3+1];
          for( int i = 0; i<n3; ++i)
            str3[i] = str[i];
          str3[n3] = '\0';

          int res = getDirection( str1, str2, str3);
          switch(res){
            case 0:
                cout<<"both"<<endl;
                break;
            case 1:
                cout<<"forward"<<endl;
                break;
            case 2:
                cout<<"backward"<<endl;
                break;
            case 3:
                cout<<"invalid"<<endl;
                break;
          }
      }
}
