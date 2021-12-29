#include<bits/stdc++.h>
using namespace std;

const int lo = -32768; // 下边界
const int hi = 32767; // 上边界

int main()
{
    string s;
    map<int, int> a,b;

    while (getline(cin, s))
    {
        stringstream ss;
        string lastStr;
        bool l = true, r = true;
        int num1=-1e9,num2=1e9;
        
        ss << s;
        while (ss >> s)
        {
            lastStr = s;
            if (s == ">=")
            {
                l = false;               
                ss >> num1;
            }
            else if (s == "<=")
            {
                r = false;               
                ss >> num2;
            }
        }

        if(num1<=num2){
            num1=max(num1,lo);
            a[num1] += 1;

            num2=min(num2,hi);
            a[num2+1] -= 1;
        }

        if (lastStr != "||")
        {
            break;
        }
    }

    int lastNum = 0;
    bool can = true;
    bool cannot = true;
    for (int i =lo; i <= hi; i++)
    {
        b[i] = a[i] + b[i - 1];

        if(b[i]<=0){
            can = false;
        }
        else{
            cannot = false;
        }
    }

    if(can){
        printf("true");
    }
    else if(cannot){
        printf("false");
    }
    else{
        int lastNum = 0, left=lo, right=hi;
        bool judge = false;

        for (int i = lo; i <= hi+1;i++){
            if(lastNum<=0&&b[i]>0){
                left = i;
            }

            else if(lastNum>0&&b[i]<=0){
                right = i-1;

                if(judge){
                    printf(" ||\n");
                }
                else{
                    judge = true;
                }
               
                if (left == lo)
                {
                    printf("x <= %d", right);
                }
                else if(right==hi){
                    printf("x >= %d", left);
                }
                else{
                    printf("x >= %d && x <= %d", left, right);
                }
            }
            lastNum = b[i];
        }
    }
    return 0;
}