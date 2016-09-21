// ---- Program Info Start----
//FileName:     exam1.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-21 20:13:04
// ---- Program Info End  ----

#include<cstdio>
#include<algorithm>
#include<cstdlib>
int main(){
      int n;
      while( ~scanf("%d", &n)){
            int * arr = (int *) malloc( n*sizeof(int));
            for( int i=0; i<n; ++i )
                  scanf("%d", & arr[i]);
            int max = 0, min = 100;
            for( int i=0; i<n; ++i ){
                  if( max < arr[i]) max = arr[i];
                  if( min > arr[i]) min = arr[i];
            }
			if( max - min <= 10){
                  int tmp = n%3 ==0 ? 0:3-n%3;
                  printf("%d\n", tmp);
            }else if( max - min <=20 ){
                  std::sort(arr, arr+n);
                  int cnt = n;
                  for( int i=1; i<n; ++i ){
                        if(arr[i] - arr[i-1] > 10) cnt++;
                  }
                  int tmp = cnt%3==0?0:3-cnt%3;
                  printf("%d\n", (tmp)+(cnt-n));
            }else{
                  std::sort(arr, arr+n);
                  int cnt = n;
                  for( int i=1; i<n; ++i ){
                        int gap = arr[i] - arr[i-1];
                        if( gap > 10 && gap <=20 ) cnt++;
                        else if( gap > 20 ) cnt += (gap-1)/10;
                  }
                  int tmp = cnt%3==0?0:3-cnt%3;
                  printf("%d\n", (tmp)+(cnt-n));
            }
            free(arr);
      }
      return 0;
}
