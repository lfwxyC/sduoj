#include<bits/stdc++.h>
using namespace std;

void solve(string s,map<string,int> &mp){
    stack<char> q;
    
    for(int i=0;i<s.length();i++){
        int num=0,mul=1;
        string ele="",dig="";

        // 根据"+"分割字符串
        if(s[i]!='+'){
            q.emplace(s[i]);
        }
        if(s[i]=='+'||i==s.length()-1){
            map<string,int> tmp;
            stack<int> z;

            while(!q.empty()){
                // 从栈中读出数字
                if(isdigit(q.top())){
                    dig=q.top()+dig;
                    q.pop();
                    num=stoi(dig);
                }

                else if(q.top()==')'){
                    // 此时的num为()后面的数字
                    if(num){
                        z.emplace(num);
                        mul*=num;

                        num=0;
                        dig="";
                    }
                    else{ // num=0说明系数为1
                        z.emplace(1);
                    }
                    q.pop();
                }

                // 一层括号处理结束
                else if(q.top()=='('){
                    int div=z.top();
                    z.pop();

                    mul/=div;
                    q.pop();
                }

                // 小写字母要和前面的大写字母组合
                else if(islower(q.top())){
                    ele=q.top();
                    q.pop();
                }

                else if(isupper(q.top())){
                    ele=q.top()+ele;
                    q.pop();

                    // 计算元素ele对应的个数
                    if(num){ // 此时的num为元素下标
                        tmp[ele]+=num*mul;
                        num=0;
                        dig="";
                    }
                    else{
                        tmp[ele]+=mul;
                    }
                    ele="";
                }
            }

            for(auto x:tmp){
                // 此时的num为最前面的系数
                if(num){
                    x.second*=num;
                }
                mp[x.first]+=x.second; // 把结果放入mp中
            }
        }
    }
}

void check(map<string,int> leftMp,map<string,int> rightMp){ // 比较左右两边原子个数是否相等
    for(auto x:leftMp){
        if(x.second!=rightMp[x.first]){
            printf("N\n");
            return;
        }
    }
    printf("Y\n");
}

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        string s,leftStr="",rightStr="";
        bool flag=true;
        map<string,int> leftMp,rightMp;
        cin>>s;

        // 根据"="分割字符串
        for(int j=0;j<s.length();j++){
            if(s[j]=='='){
                flag=false;
                continue;
            }

            if(flag){
                leftStr+=s[j];
            }
            else{
                rightStr+=s[j];
            }
        }

        solve(leftStr,leftMp);
        solve(rightStr,rightMp);
        check(leftMp,rightMp);
    }

    return 0;
}