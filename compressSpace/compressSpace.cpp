// ---- Program Info Start----
//FileName:     compressSpace.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-07-08 14:25:21
// ---- Program Info End  ----

#include <iostream>

using namespace std;

void compressSpace(char * s){
    char a;
    char * p = s;
    while(*s != '\0'){
        //while((a = *s++) != ' ' && a != '\0');
        //if(a == '\0') break;
        //p = s-1;
        while((a = (*s++ = *p++)) != ' ' && a != '\0');
        if(a == '\0') break;
        while((a = *p++) == ' ');
        if(a == '\0') {
            *s = a;
            break;
        }
        p--;
    }
}

int main(int argc, char *argv[])
{
    char a[] = "abc   c s dd ad  sd  sf  dd    ";
    compressSpace(a);
    cout<<a;
    return 0;
}
