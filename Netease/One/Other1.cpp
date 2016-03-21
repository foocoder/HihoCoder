#include<iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;

#define MASK     0x3FF

struct SExpress
{
    int less;   //可表示的小于等于当前数位上数的个数
    int total;  //总可表示的数的个数
    int haseuqal;   //是否有等于当前数位上数的可表示数
};

//求要显示数字各位上的数值
void getWeis(vector<uchar> &wei, int num)
{
    //索引s到0 存数值的低位到高位
    int s = wei.size();
    for (int i = s - 1; i >= 0; --i)
    {
        wei[i] = num % 10;
        num = num / 10;
    }
}

//求该位可表示的数字个数
SExpress getExpress(uchar n, uint light)
{
    SExpress exp = {0, 0, false};
    for (int i = 0; i < 10; ++i)
    {
        bool b = light & 0x1;
        if (b)
        {
            if (i <= n) ++exp.less;
            exp.haseuqal = (i == n ? 1 : 0);
            ++exp.total;
        }
        light >>= 1;
    }
    return exp;
}


int main()
{
    vector<uint> erjiguan({ 0, 0x3ED, 0x371, 0x39F, 0x37C, 0x145, 0x3FB, 0x36D });

    int test_point_count;
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> test_point_count;
    for (int m = 0; m < test_point_count; ++m)
    {
        //s 样例数，num为显示的数值
        int s, num;
        getline(cin, line);
        stringstream ss1(line);
        ss1 >> s >> num;
        vector<uint> samples(s, MASK);
        //读样例
        for (int i = 0; i < s; ++i)
        {
            //string line;
            getline(cin, line);
            stringstream ss2(line);
            //读二极管亮度
            int no;
            while (ss2 >> no)
            {
                samples[i] &= erjiguan[no];
            }
        }


        vector<uchar> wei(s, 0);
        getWeis(wei, num);

        //如果高位为0（伪高位），则检查是否能表示0，直到第一个不为0的高位（真高位）
        int k = 0;
        bool flag = true;
        for (k = 0; k < s && wei[k]==0; ++k)
        {
            if (samples[k] & 0x1 == 0)
            {
                flag = false;
                break;
            }
        }

        if (!flag || k >= s)
        {
            cout << (flag ? 1 : 0) << endl;
            continue;
        }
        //求真高位能表示的数的个数
        SExpress exp = getExpress(wei[k], samples[k]);
        //当前无法表示真高位
        if (exp.less == 0)
        {
            cout << 0 << endl;
            continue;
        }

        //总个数计算： 比如num为50
        //1. 比5小时的总表示个数a
        //2. 真高位为5时，可表示的数的总个数b
        //3. 总个数=a+b
        exp.total = exp.less - exp.haseuqal;
        exp.less = exp.haseuqal;
        SExpress tmp;
        for (k=k+1; k < s; ++k)
        {
            tmp = getExpress(wei[k], samples[k]);
            exp.total *= tmp.total;
            exp.less *= tmp.less;
        }
        cout << exp.total + exp.less << endl;
    }
}
