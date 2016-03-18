// ---- Program Info Start----
//FileName:     ComplicatedExpression.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-16 20:39:21
// ---- Program Info End  ----

#include <iostream>
#include <stack>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

class Solution{
    public:
        string ComplicatedCalculate(const char * expression ){
            string result = "invalid expression";
            stack<char> operatorStack;
            stack<int> digitStack;
            stack<int> tmpResultStack;
            stack<stack<int> > stackStack;
            if(*expression == '(')
            {
                operatorStack.push(*expression);
                stackStack.push(tmpResultStack);
            }
            else
                return result;
            while(*++expression != '\0'){
                char character = * expression;
                if(IsSymbol(character)){
                    operatorStack.push(character);
                }
                if(IsNumber(character)){
                    digitStack.push(character-'0');
                }
                if(character == '('){
                    operatorStack.push(character);
                    if(!digitStack.empty())
                        tmpResultStack.push(changeNumber(digitStack));
                    stackStack.push(tmpResultStack);
                    while(!tmpResultStack.empty()){
                        tmpResultStack.pop();
                    }
                }
                if(character == ')'){
                    if(operatorStack.empty() || !IsSymbol(operatorStack.top())){
                        return result;
                    }
                    else{
                        //Pop Symbol Stack
                        if(!digitStack.empty())
                            tmpResultStack.push(changeNumber(digitStack));
                        if(tmpResultStack.empty())
                            return result;
                        int tmpResult = 0;
                        //Process Symbol Operator
                        switch(operatorStack.top()){
                            case '+':// 1, 2, or multi
                                while(!tmpResultStack.empty()){
                                    tmpResult +=tmpResultStack.top();
                                    tmpResultStack.pop();
                                }
                                break;
                            case '*':// 2 or multi
                                tmpResult = 1;
                                if(tmpResultStack.size()<2)
                                    return result;
                                while(!tmpResultStack.empty()){
                                    tmpResult *=tmpResultStack.top();
                                    tmpResultStack.pop();
                                }
                                break;
                            case '-':// 1 or 2
                                if(tmpResultStack.size()>2)
                                    return result;
                                tmpResult = -1 * tmpResultStack.top();
                                tmpResultStack.pop();
                                if(!tmpResultStack.empty()) {
                                    tmpResult += tmpResultStack.top();
                                    tmpResultStack.pop();
                                }
                                break;
                            default:
                                return result;
                        }
                        tmpResultStack = stackStack.top();
                        stackStack.pop();
                        tmpResultStack.push(tmpResult);
                        operatorStack.pop();//pop operator;
                        if(!operatorStack.empty() && operatorStack.top() == '(')
                            operatorStack.pop();//pop (;
                        else
                            return result;
                    }
                }
                if(character == ' '){
                    //Do Nothing
                    if(!digitStack.empty())
                        tmpResultStack.push(changeNumber(digitStack));
                }
            }
            if(tmpResultStack.size() != 1)
                return result;
            else
            {
                ostringstream oss;
                oss<<tmpResultStack.top();
                return oss.str();
            }
        }

        bool IsSymbol( char character ){
            return character == '+' || character == '-' || character == '*';
        }
        bool IsNumber( char character ){
            return character>='0' && character <='9';
        }
        int changeNumber( stack<int> & digitStack ){
            int result = 0, order = 1;
            while(!digitStack.empty()){
                result += digitStack.top() * order;
                digitStack.pop();
                order *= 10;
            }
            return result;
        }
};

int main(int argc, char *argv[])
{
    ifstream infile("Test");
    if(!infile)
        return -1;
    string line;
    while(getline(infile, line))
    {
        Solution test;
        cout<<test.ComplicatedCalculate(line.c_str())<<endl;
    }
    return 0;
}
