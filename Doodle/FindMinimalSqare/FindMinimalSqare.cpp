// ---- Program Info Start----
//FileName:     FindMinimalSqare.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-23 16:57:22
// ---- Program Info End  ----

#include <iostream>

using namespace std;

int findSqrt( int val ){
    int lo = 0, hi = val;
    while( lo < hi ){
        int mid = ( lo + hi ) / 2;
        int s = mid*mid, sn = (mid+1)*(mid+1);
        if( s == val ) return mid;
        if( s > val )
            hi = mid - 1;
        if( s < val ){
            if( sn > val ) return mid;
            lo = mid + 1;
        }
    }
    return lo;
}

int findMinSqare( int val ){
    if( val == 0 )
        return 0;
    int min[val+1];
    min[0] = 0;

    for( int i=1; i<=val; ++i ){
        int s = findSqrt( i );
        min[i] = min[i-s*s] + 1;
        for( int j=s-1; j>0; --j ){
            if( min[i] > min[i-j*j]+1 ){
                min[i] = min[i-j*j]+1;
            }
        }
    }
    return min[val];
}

int main(int argc, char *argv[])
{
    for( int i=0; i<=25; ++i ){
        cout<<findMinSqare( i )<<",";
    }
    return 0;
}
