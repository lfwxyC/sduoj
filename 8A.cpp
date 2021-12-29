#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    string s,str="";
    cin>>n>>s;

    for(int i=0;i<n;i++){
        if(s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){ // 把所有元音变成a
            str+='a';
        }else{
            str+=s[i];
        }

        if(i<n-1){
            str+='#'; // 每两个字符用#分隔
        }
    }

    int ssize=2*n-1;
    for(int i=0;i<ssize;i++){ // 以每个字符为中心，向两边扩展
        int j=1,cnt=0;

        if(str[i]!='#'){
            cnt++;
        }

        while(i-j>=0&&i+j<ssize){
            if(str[i-j]!=str[i+j]){
                break;
            }

            if(str[i-j]!='#'){
                cnt+=2;
            }

            j++;
        }
        ans=max(ans,cnt);
    }

    printf("%d",ans);
    return 0;
}