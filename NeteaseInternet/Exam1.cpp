// ---- Program Info Start----
//FileName:     Exam1.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-02 19:20:19
// ---- Program Info End  ----

#include <iostream>

using namespace std;

inline int abs(int num){
    return num > 0? num : -num;
}

int Solutions( int * num, int n ){
    int total = 0, avg;
    for(int i=0; i<n; ++i){
        total += num[i];
    }
    if( total%n )
        return -1;
    avg = total / n;
    int couter = 0;
    for(int i=0; i<n; ++i){
        int tmp = abs( num[i] - avg );
        if( tmp%2 )
            return -1;
        couter += tmp;
    }
    return couter / 4;

}
int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    int num[n];
    int total = 0, avg;
    for(int i=0; i<n; ++i){
        cin>>num[i];
        total += num[i];
    }
    avg = total / n;
    cout<< Solutions(num, n);
    return 0;
}
