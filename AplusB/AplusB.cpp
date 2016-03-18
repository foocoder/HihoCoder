// ---- Program Info Start----
//FileName:     AplusB.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-16 20:55:37
// ---- Program Info End  ----

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string line;
    vector<int> vec;
    while(getline(cin, line)){
        istringstream streamLine(line);
        int number1, number2;
        streamLine>>number1>>number2;
        vec.push_back(number1+number2);
    }
    for(auto i : vec){
        cout<< i << endl;
    }
    return 0;
}
