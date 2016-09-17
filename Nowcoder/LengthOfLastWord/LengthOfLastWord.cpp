// ---- Program Info Start----
//FileName:     LengthOfLastWord.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-09-17 07:57:10
// ---- Program Info End  ----

#include <cstdio>

int main(int argc, char *argv[])
{
    char str[5000] = {0};
    while(~scanf("%[^\n]", str)){
        getchar();
        char * p = str;
        int cnt = 0;
        while( *p != 0 ){
            if( *p == ' ' ){
                cnt = 0;
            }
            else{
                cnt ++;
            }
            p++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
