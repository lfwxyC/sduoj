#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    if(s.length()<6){
        printf("0\n");
    }
    else{
        int last=-1,now,cnt=0;
	
	    for(int i=0;i<s.length();i++){
            if(islower(s[i])){
                now=0;
            }
            else if(isupper(s[i])){
                now=1;
            }
            else if(isdigit(s[i]))
			{
                now=2;
            }

            if(last!=now){
                cnt++;
            }
            last=now;
	    }
	
	    printf("%d\n",cnt);
    }
    
    return 0;
}
