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
#include <cstring>
#include <sstream>

using namespace std;

class Solution{
    vector<vector<int> > digit = {{1,2,3,5,6,7},
        {3,6},
        {1,3,4,5,7},
        {1,3,4,6,7},
        {2,3,4,6},
        {1,2,4,6,7},
        {1,2,4,5,6,7},
        {1,3,6},
        {1,2,3,4,5,6,7},
        {1,2,3,4,6,7}
    };
    public:
        int LessThanN(vector<vector<int> > &led, int N){
            int K = led.size();
            sort(led[0].begin(),led[0].end());
            vector<int> vec = FindDigit(led[0]);
            if(vec[0] != 0) return 0;
            vector<vector<int> > vecVect;
            int counter = 1;
            for(int i=1; i<K; i++){
                sort(led[i].begin(),led[i].end());
                vec = FindDigit(led[i]);
                if(vec.empty()) return 0;
                //counter *= vec.size();
                vecVect.push_back(vec);
            }
            vector<int> num;
            int wholeNum = 0;
            for(int i=0; i<K-1; i++){
                int order = pow(10,K-i-2);
                while(!vecVect[i].empty()){
                    if(wholeNum+vecVect[i].back() * order >N){
                        vecVect[i].pop_back();
                    }
                    else
                        break;
                }
                if(vecVect[i].empty())
                    num.push_back(1);
                else{
                    num.push_back(vecVect[i].size() > 1 ? vecVect[i].size() -1 : 1);
                    wholeNum = vecVect[i].back() * order;
                }
            }
            for(int i=0; i<K-1; i++){
                counter *= vecVect[i].size() == 0?1:vecVect[i].size();
            }
            return counter;
        }

        vector<int> FindDigit(vector<int> & ledDigit){
            vector <int> result;
            for(int i=0; i<10; i++){
                vector<int> d = digit[i];
                bool flag = false;
                for(auto j : ledDigit){
                    vector<int>::iterator it = find(d.begin(), d.end(), j);
                    if(it==d.end())
                        flag = true;
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
