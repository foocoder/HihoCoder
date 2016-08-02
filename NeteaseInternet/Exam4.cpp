// ---- Program Info Start----
//FileName:     Exam4.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-08-02 20:14:49
// ---- Program Info End  ----

#include <iostream>
#include <vector>

using namespace std;

class BigInteger{
    private:
        vector<int> _digitVect;
        int isPositive;
    public:
        BigInteger( int num ){

        }
        BigInteger( const BigInteger& rhs ){
            int size = rhs._digitVect.size();
            isPositive = rhs.isPositive;
            for(int i=0; i<size; ++i){
                _digitVect.push_back(rhs._digitVect[i]);
            }
        }

        BigInteger operator+( const BigInteger& rhs){
            BigInteger tmp = rhs;
            int lsize = _digitVect.size();
            int rsize = tmp._digitVect.size();
            if( lsize<rsize )
                for(int i=0; i<(rsize-lsize); ++i)
                    _digitVect.push_back(0);
            else
                for(int i=0; i<(lsize-rsize); ++i)
                    tmp._digitVect.push_back(0);

            int CF = 0;
            for(int i=0; i<lsize; ++i){
                int bitResult = _digitVect[i] + tmp._digitVect[i] + CF;
                if(bitResult>=10){
                    CF = 1;
                    _digitVect[i] = bitResult - 10;
                }
                else{
                    CF=0;
                    _digitVect[i] = bitResult;
                }
            }
            if(CF)
                _digitVect.push_back(1);
            return *this;
        }

        BigInteger operator-( const BigInteger& rhs){
            BigInteger tmp = rhs;

        }

        bool operator<( const BigInteger& rhs ){

        }

        void changeSigned(){
            isPositive = -1 * isPositive;
        }

        bool isPos(){
            if(isPositive == 1)
                return true;
            if(isPositive == -1)
                return false;
        }
};
