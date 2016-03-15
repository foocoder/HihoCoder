// ---- Program Info Start----
//FileName:     AMusingDigits.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-15 21:58:51
// ---- Program Info End  ----

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

class Solution{
    public:
        int AmusingDigits(const char * digitString ){
            stack<char> amusingStack;
            amusingStack.push('6');
            amusingStack.push('0');
            amusingStack.push('7');
            amusingStack.push('9');

            vector<stack<char> > vec;
            vec.push_back(amusingStack);
            for(int i=0; digitString[i] != '\0'; i++){
                if(digitString[i] == '9' || digitString[i] == '7' || digitString[i]=='0' || digitString[i]=='6') {
                    for(vector<stack<char>>::iterator j=vec.begin(); j!=vec.end(); j++){
                        if(!(*j).empty() && digitString[i] == (*j).top()){
                            (*j).pop();
                            break;
                        }
                    }
                    if(vec.back().top() != '9')
                        vec.push_back(amusingStack);
                }
            }
            int result = 0;
            for(auto i : vec){
                if(i.empty()){
                    result ++;
                }
                else
                    break;
            }
            return result;
        }
};

int main(int argc, char *argv[])
{
    int num;
    cin>>num;
    //char *dig[num];
    string dig[num];
    cin.get();
    for(int i=0; i<num; i++){
        //cin.getline(dig[i],50000);
        getline(cin,dig[i]);
        //cout<<i<<"finish"<<endl;
    }
    Solution test;
    for(int i=0; i<num; i++)
        cout<<test.AmusingDigits(dig[i].c_str())<<endl;
        //cout<<dig[i]<<endl;
    return 0;
}
