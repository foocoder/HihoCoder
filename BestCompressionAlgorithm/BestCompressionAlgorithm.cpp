// ---- Program Info Start----
//FileName:     BestCompressionAlgorithm.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-16 19:16:54
// ---- Program Info End  ----

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

class Solution{
    public:
        int GetLengthOfOriginalString(const char * compressedStr){
            if(compressedStr == NULL) return 0;
            stack<int> counterStack;
            stack<int> digitStack;
            int counter = 0, digitNum = 0;
            bool parentheseFlag = false;
            for(int i=0; compressedStr[i] != '\0'; i++){
                char currentChar = compressedStr[i];
                digitNum = 0;
                if(currentChar >= '0' && currentChar <= '9')//0-9
                {//Consider Number bigger than 10
                    digitStack.push(currentChar - '0');
                }
                if(!digitStack.empty()){
                    int order = 1;
                    while(!digitStack.empty()){
                        digitNum += digitStack.top() * order;
                        digitStack.pop();
                        order *= 10;
                    }
                    //Calculate the digit after ')'
                    if(parentheseFlag)
                    {
                        counter *= digitNum;
                        if(!counterStack.empty())
                        {
                            counter += counterStack.top();
                            counterStack.pop();
                        }
                        parentheseFlag = false;
                    }
                    else
                    {
                        counter += digitNum - 1;
                    }
                }
                if(currentChar >= 'A' && currentChar <= 'Z')//A-Z
                {
                    counter += 1;
                }
                if(currentChar == '(')
                {
                    counterStack.push(counter);
                    counter = 0;
                }
                if(currentChar == ')')
                {
                    parentheseFlag = true;
                }
            }
            return counter;
        }
};

int main(int argc, char *argv[])
{
    int num;
    cin>>num;
    cin.get();
    string line[num];
    for(int i=0; i<num; i++){
        getline(cin, line[i]);
    }
    Solution test;
    for(int i=0; i<num; i++)
        cout<<test.GetLengthOfOriginalString(line[i].c_str())<<endl;
    return 0;
}
