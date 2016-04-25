// ---- Program Info Start----
//FileName:     numer2chinese.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-04-25 19:43:02
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> digitChinese = {"ling", "yi", "er", "san", "si",
                             "wu", "liu", "qi", "ba", "jiu"};
vector<string> digitWei = {"", "shi", "bai"};
string processNumber(int num){
    vector<int> digitVec;
    while(num/10){
        digitVec.push_back(num % 10);
        num /= 10;
    }
    digitVec.push_back(num % 10);
    string strResult = "";
    int nSize = digitVec.size();
    for(int i=0; i<nSize; ++i){
        int digit = digitVec[nSize-i-1];
        if(digit){
            if(digit !=1 || (nSize-i-1) !=1 || nSize != 2)
            strResult.append(digitChinese[digit]);
            if(nSize !=3 || digitVec[0] !=0 || i!=1)
            strResult.append(digitWei[nSize-i-1]);
        }
        else if(!digit && i == 1 && nSize == 3 && digitVec[0] != 0 || nSize ==1){
            strResult.append(digitChinese[digit]);
        }
    }
    return strResult;
}

vector<string> num2chinese(vector<int> numbers){
    int nNumSize = numbers.size();
    vector<string> strChinese;
    if(nNumSize == 0) return strChinese;
    for(int i=0; i<nNumSize; ++i){
        strChinese.push_back(processNumber(numbers[i]));
    }
    return strChinese;
}

int main(int argc, char *argv[])
{
    int number;
    vector<int> numbers;
    string str;
    while(getline(cin, str)){
        istringstream ss(str);
        ss>>number;
        numbers.push_back(number);
    }
    vector<string> strCh = num2chinese(numbers);
    for(auto s:strch){
        cout<<s<<endl;
    }
    return 0;
}
