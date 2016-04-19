// ---- Program Info Start----
//FileName:     sliceLand.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-04-19 19:39:03
// ---- Program Info End  ----

#include <iostream>
#include <vector>
using namespace std;

class Partition {
public:
    vector<int> getPartition(const vector<vector<int> >& land, int n, int m) {
        // write code here
        vector<int> speciesA;
        vector<int> speciesB;
        for(int i=0; i<n; ++i){
            speciesA.push_back(0);
            speciesB.push_back(0);
        }
        for(int i=0; i<m ; ++i){
            for(int j=0; j<n; ++j){
                if(land[i][j] == 0){
                    ++speciesA[j];
                }else if(land[i][j] == 1){
                    ++speciesB[j];
                }
            }
        }
        int maxScore = 0;
        int maxIndex = -1;
        for(int i=0; i<=n; ++i){
            int score = 0, j=0;
            for(; j<i; ++j){
                score += speciesA[j];
            }
            for(; j<n; ++j){
                score += speciesB[j];
            }
            if(score > maxScore){
                maxScore = score;
                maxIndex = i;
            }
        }
        vector<int> res;
        res.push_back(maxIndex);
        res.push_back(maxIndex+1);
        return res;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
