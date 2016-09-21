// ---- Program Info Start----
//FileName:     exam2.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-21 20:40:37
// ---- Program Info End  ----

#include <cstdio>
using namespace std;
int main(int argc, char *argv[])
{
    for( int i=0; i<16; ++i){
        for( int j=0; j<16; ++j){
            printf("%2d", i^j);
            //cout<<setprecision(2)<<(i^j);
            if(j==15)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
