// ---- Program Info Start----
//FileName:     One.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-18 18:51:11
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution{
    vector<vector<int> > digit = {
        {1,1,1,0,1,1,1},/*0*/
        {0,0,1,0,0,1,0},/*1*/
        {1,0,1,1,1,0,1},/*2*/
        {1,0,1,1,0,1,1},/*3*/
        {0,1,1,1,0,1,0},/*4*/
        {1,1,0,1,0,1,1},/*5*/
        {1,1,0,1,1,1,1},/*6*/
        {1,0,1,0,0,1,0},/*7*/
        {1,1,1,1,1,1,1},/*8*/
        {1,1,1,1,0,1,1} /*9*/
    };
    public:
        int LessThanN(vector<vector<int> > &led, int N){
            int K = led.size();
            vector<int> vec = FindDigit(led[0]);
            if(vec.empty() || vec.front() != 0) return 0;
            vector<vector<int> > vecVect;
            for(int i=1; i<K; i++){
                vec = FindDigit(led[i]);
                if(vec.empty()) return 0;
                vecVect.push_back(vec);
            }
            vector<int> countVec1,countVec2;
            int wholeNum = 0;
            bool highPos = false;
            for(int i=0; i<K-1; i++){
                int order = pow(10,K-i-2);
                while(!vecVect[i].empty()){
                    if(wholeNum+vecVect[i].back() * order >N){
                        vecVect[i].pop_back();
                    }
                    else
                        break;
                }
                if(!vecVect[i].empty()) {
                    if(!highPos)
                    {
                        highPos = true;
                        countVec1.push_back(vecVect[i].size()-1);
                        countVec2.push_back(1);
                        wholeNum += vecVect[i].back() * order;
                    }
                    else{
                        countVec1.push_back(vecVect[i].size());
                        countVec2.push_back(vecVect[i].size()-1);
                        wholeNum += vecVect[i].back() * order;
                    }
                }
            }
            int counter1 = 1, counter2 = 1;
            for(int i=0; i<countVec1.size(); i++){
                if(countVec1.size() != 0)
                    counter1 *= countVec1[i];
            }
            for(int i=0; i<countVec2.size(); i++){
                counter2 *= countVec2[i];
            }
            if(wholeNum < N) counter2 ++;
            return counter1 + counter2;
        }

        vector<int> FindDigit(vector<int> & ledDigit){
            vector <int> result;
            for(int i=0; i<10; ++i){
                bool flag = false;
                for(auto j : ledDigit){
                    if(digit[i][j-1] == 0) {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    result.push_back(i);
            }
            return result;
        }
};
int main(int argc, char *argv[])
{
    Solution test;
    int num;
    cin>>num;
    cin.get();
    for(int i=0; i<num; i++){
        int K,N;
        cin>>K>>N;
        cin.get();
        string line[K];
        for(int j=0; j<K; j++)
            getline(cin,line[j]);
        vector<vector<int> > led;
        for(int j=0; j<K; j++)
        {
            istringstream sline(line[j]);
            int number;
            vector<int> vec;
            while(sline>>number){
                vec.push_back(number);
            }
            led.push_back(vec);
        }
        cout<<test.LessThanN(led,N)<<endl;
    }
    return 0;
}
