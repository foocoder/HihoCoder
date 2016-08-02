// ---- Program Info Start----
//FileName:     Exam3.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-02 19:54:08
// ---- Program Info End  ----

#include <iostream>
#include <cstdlib>
using namespace std;

int solutions( int **filed, int n, int m ){
    if(n<4 || m<4)
        return 0;
    int min = 100;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(filed[i][j] < min)
                min = filed[i][j];
    return min;
}

int main(int argc, char *argv[])
{
    int n,m;
    cin>>n>>m;
    int **filed;
    filed = (int **)malloc( n*m*sizeof(int));
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin>>filed[i][j];
    cout<<solutions(filed, n, m);
    free(filed);
    return 0;
}
