// ---- Program Info Start----
//FileName:     two.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-20 19:11:24
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    int a[40];
    int counter;
    public:
        int GetNumbersOfScheme(vector<int> &seq, int seq_size){
            if(seq_size <= 1) return seq_size;
            if(seq_size == 2) return 3;
            counter = seq_size + (seq_size * (seq_size-1))/2;
            sort(seq.begin(), seq.end());
            for(int i=3; i<=seq_size; i++){
                a[0] = i;
                combineArray(seq_size, i, seq);
            }
            return counter;
        }
        void combineRecure(int n, int m, vector<int> & seq){
            int i,j;
            for(i = n; i >= m ; i--){
                a[m] = i;
                if(m>1)
                    combineRecure(i-1,m-1,seq);
                else{
                    vector<int> tmp;
                    int sum = 0;
                    for(j=a[0];j>0;j--) {
                        tmp.push_back(seq[a[j]-1]);
                        sum += seq[a[j]-1];
                    }
                    int s = tmp.size();
                    double med, avg = (double)sum / s;
                    if(s & 1){
                        med = tmp[s/2];
                    }
                    else{
                        med = (double)(tmp[s/2]+tmp[s/2-1])/2;
                        cout<<"med"<<med<<endl;
                    }
                    if(med - avg >= -1e-9)
                        counter++;
                }
            }
        }
        void combineArray(int n, int m, vector<int> & seq){
            vector<int> arr(n);
            for(int i=0; i<m; i++)
                arr[i] = 1;
            int one, zero;
            do{
                for(int i=0; i<n-1; i++){
                    if(arr[i] == 1 && arr[i+1] == 0){
                        for(int j=0; j<one; j++){
                            arr[j] = 1;
                        }
                        for(int j=one; j<one+zero; j++){
                            arr[j] = 0;
                        }
                        arr[i] = 0;
                        arr[i+1] = 1;
                        break;
                    }
                    arr[i] == 1?one++:zero++;
                }
                vector<int> tmp;
                int sum = 0;
                for(int i=0; i<n; i++){
                    if(arr[i]){
                        sum += seq[i];
                        tmp.push_back(seq[i]);
                    }
                }
                int s = tmp.size();
                double med, avg = (double) sum/s;
                cout<<"avg"<<avg<<endl;
                if(s & 1){
                    med = tmp[s/2];
                    cout<<"med"<<med<<endl;
                }
                else{
                    med = (double)(tmp[s/2]+tmp[s/2-1])/2;
                    cout<<"med"<<med<<endl;
                }
                if(med - avg >= -1e-9)
                    counter++;
            }while(!testArr(n,m,arr));
        }
        bool testArr(int n, int m, vector<int> & arr){
            for(int i=n-m; i<n; i++) {
                if(!arr[i])
                    return false;
            }
            return true;
        }
};

int main(int argc, char *argv[])
{
    int num, number;
    cin>>num;
    vector<int> seq;
    for(int i=0; i<num; i++) {
        cin>>number;
        seq.push_back(number);
    }
    Solution test;
    cout<<test.GetNumbersOfScheme(seq, num)<<endl;
    return 0;
}
