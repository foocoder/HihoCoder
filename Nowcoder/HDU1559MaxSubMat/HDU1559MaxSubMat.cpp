// ---- Program Info Start----
//FileName:     HDU1559MaxSubMat.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-17 10:17:59
// ---- Program Info End  ----

#include<cstdio>

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; ++i){
        int m,n,x,y;
        scanf("%d %d %d %d",&m,&n,&x,&y);
        if(x > m || y > n){
            printf("0\n");
            continue;
        }
        int mat[m][n];
        for( int k=0; k<m; ++k){
            for( int j=0; j<n; ++j){
                scanf("%d", &mat[k][j]);
            }
        }
        int aux[m][n];
        aux[0][0] = mat[0][0];
        for( int k=1; k<m; ++k ){
            aux[0][k] = aux[0][k-1]+mat[0][k];
        }
        for( int k=1; k<n; ++k){
            aux[k][0] = aux[k-1][0] + mat[k][0];
        }
        for( int k=1; k<m; ++k ){
            for( int j=1; j<n; ++j){
                aux[k][j] = aux[k-1][j] + aux[k][j-1]+mat[k][j] - aux[k-1][j-1];
            }
        }
        int dp[m][n];
        for( int k = 0; k<m; ++k )
            for( int j=0; j<n; ++j )
            	dp[k][j] = 0;
        dp[x-1][y-1] = aux[x-1][y-1];
        int max = dp[x-1][y-1];
        for( int k=y; k<n; ++k){
            dp[x-1][k] = aux[x-1][k]-aux[x-1][k-y];
            if( dp[x-1][k] > max )
                max = dp[x-1][k];
        }
        for( int k=x; k<m; ++k){
            dp[k][y-1] = aux[k][y-1]-aux[k-x][y-1];
            if(dp[k][y-1] > max)
                max = dp[k][y-1];
        }
        for( int k=x; k<m; ++k){
            for( int j=y; j<n; ++j){
                dp[k][j] = aux[k][j] - aux[k-x][j] - aux[k][j-y] + aux[k-x][j-y];
                if(dp[k][j] > max)
                    max = dp[k][j];
            }
        }
        printf("%d\n",max);
    }
}
