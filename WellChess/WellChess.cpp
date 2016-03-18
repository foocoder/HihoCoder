// ---- Program Info Start----
//FileName:     WellChess.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-18 14:53:04
// ---- Program Info End  ----

#include <iostream>

using namespace std;

class Solution{
    public:
        string GetState(char ** chess){
            if(chess == NULL) return "Invalid";
            int Xcounter=0, Ocounter=0;
            int Xpos[] = {-1,-1,-1,-1,-1};
            int Opos[] = {-1,-1,-1,-1};
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++){
                    if(chess[i][j] == 'X') {
                        Xpos[Xcounter++] = 3*i + j;
                    }
                    if(chess[i][j] == 'O'){
                        Opos[Ocounter++] = 3*i + j;
                    }
                }
            }
            if(Xcounter-Ocounter != 1 && Xcounter-Ocounter != 0)
                return "Invalid";
            bool xFlag = CheckWin(chess, 'X'), oFlag = CheckWin(chess, 'O');
            if(xFlag && oFlag)
                return "Invalid";
            if(xFlag)
                return "X Win";
            if(oFlag)
                return "O Win";
            return "Draw";
        }

        bool CheckWin(char ** chess, char team){
            if(chess[0][0] == team && chess[1][1] == team && chess[2][2] == team)
                return true;
            if(chess[2][0] == team && chess[1][1] == team && chess[0][2] == team)
                return true;
            for(int i=0; i<2; i++) {
                if(chess[i][0] == team && chess[i][1] == team && chess[i][2] == team)
                    return true;
                if(chess[0][i] == team && chess[1][i] == team && chess[2][i] == team)
                    return true;
            }
            return false;
        }

        bool CheckNextWin(char ** chess, char team){
            if(chess[0][0] == team && chess[1][1] == team && chess[2][2] == team)
                return true;
            if(chess[2][0] == team && chess[1][1] == team && chess[0][2] == team)
                return true;
            for(int i=0; i<2; i++) {
                if(chess[i][0] == team && chess[i][1] == team && chess[i][2] == team)
                    return true;
                if(chess[0][i] == team && chess[1][i] == team && chess[2][i] == team)
                    return true;
            }
            return false;
        }
};

int main(int argc, char *argv[])
{
    char *a [] = {"XXO", "OOX","XXO"};
    Solution test;
    cout<<test.GetState(a)<<endl;
    return 0;
}
