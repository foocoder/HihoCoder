// ---- Program Info Start----
//FileName:     findLocalMin.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-25 15:58:40
// ---- Program Info End  ----

#include <iostream>
#include <vector>
using namespace std;

int getLessIndex(vector<int> arr) {
    int n = arr.size();
    if( n == 0 ) return -1;
    if( n == 1 ) return arr[0];
    int lo = 0, hi = n-1;
    if( arr[lo] < arr[lo+1]) return arr[lo];
    if( arr[hi] < arr[hi-1]) return arr[hi];
    int mid;
    //Assert : len >= 3
    while( lo < hi ){
        //Assert : arr[lo] > arr[lo+1]
        //Assert : arr[hi] > arr[hi-1]
        //Assert : mid <= hi && mid >= lo
        mid = lo + (hi-lo) / 2;
        int mval = arr[mid], lval = arr[mid-1], rval = arr[mid+1];
        if( mval < lval && mval < rval ) return mval;
        if( mval > lval && rval > mval )
            hi = mid;
        if( mval < lval && rval < mval )
            lo = mid;
        if( mval > lval && mval > rval )
            lo = mid;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> arr = {3,2,9,2,1,4,0,10,9,0,8,3,5,6,7,1,9,2,4,0,7};
    cout<<getLessIndex( arr );
    return 0;
}
