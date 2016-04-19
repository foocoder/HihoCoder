// ---- Program Info Start----
//FileName:     invertStr.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-04-19 19:05:29
// ---- Program Info End  ----

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

class Transform{
    public:
        string trans1(string s, int n){
            istringstream ss(s);
            string strWord;
            stack<string> strStack;
            while(ss>>strWord){
                int nWordSize = strWord.length();
                for(int i=0; i<nWordSize; ++i){
                    if(strWord[i] >= 'a' && strWord[i] <= 'z'){
                        strWord[i] += 'A' - 'a';
                        continue;
                    }
                    if(strWord[i] >= 'A' && strWord[i] <= 'Z'){
                        strWord[i] += 'a' - 'A';
                        continue;
                    }
                }
                strStack.push(strWord);
            }
            string res;
            while(!strStack.empty()){
                res.append(strStack.top());
                strStack.pop();
                res.append(" ");
            }
            res.erase(res.length()-1);
            return res;
        }
        string trans(string s, int n){
            string res;
            for(int i=n-1; i>=0; --i){
                char a = s[i];
                if(a >='a' && a<= 'z'){
                    a += 'A' - 'a';
                }else if(a >= 'A' && a<= 'Z'){
                    a += 'a' - 'A';
                }
                res.push_back(a);
            }
            return res;
        }
};

int main(int argc, char *argv[])
{
    Transform test;
    string s("This is a sample");
    cout<<test.trans(s, 16);
    return 0;
}
