// ---- Program Info Start----
//FileName:     MaxMultipicateInMatrix.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-17 09:27:29
// ---- Program Info End  ----
#include<cstdio>

int main(){
    int n,m;

    while(~scanf("%d %d", &n, &m)){
        int mat[n][m];
        int row[n], col[m];
        int row0[n], col0[m];
        int k;
        for(int i=0; i<m; ++i) {
            col[i] = 1;
            col0[i] = 0;
        }
        for(int i=0; i<n; ++i) {
            row[i] = 1;
            row0[i] = 0;
        }

        for(int i=0; i<n; ++i){
            for( int j=0; j<m; ++j){
                scanf("%d", &mat[i][j]);
                if(!mat[i][j]){
                    row0[i] ++;
                    col0[j] ++;
                }
            }
        }


        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int k= mat[i][j];
                row[i] *= k==0?1:k ;
                col[j] *= k==0?1:k ;
            }
        }
        long long max = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int k = mat[i][j];
                long long t;
                if(k==0){
                    //Assert{ row0[i] >= 1 && col0[j]>=1}
                    if( row0[i] == 1 && col0[j] == 1)
                        t = row[i] * col[j];
                    else
                        t = 0;
                }
                else{
                    //Assert{ row0[i] >=0 && col0[j] >= 0 }
                    if( row0[i] == 0 && col0[j] == 0)
                        t = row[i] * col[j] /(k*k);
                    else
                        t = 0;
                }
                if(t > max) max = t;
            }
        }
        printf("%ld\n", max);
    }
    return 0;
}
