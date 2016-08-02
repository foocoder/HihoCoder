// ---- Program Info Start----
//FileName:     Exam2.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-02 19:35:27
// ---- Program Info End  ----

#include <iostream>
#include <cmath>

using namespace std;

long long solutions( long long h ){
    long long s = sqrt(h);
    if( s*(s+1) >= h)
        return s-1;
    else
        return s;
}

int main(int argc, char *argv[])
{
    long long h;
    cin>>h;
    cout<<solutions(h);
    return 0;
}
