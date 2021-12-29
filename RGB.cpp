#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,r=0,g=0,b=0;
    scanf("%d",&n);

    string s;
    cin>>s;

    for (char c:s)
    {
        switch (c)
        {
        case 'R':
            r++;
            break;
        case 'G':
            g++;
            break;
        case 'B':
            b++;
            break;
        default:
            break;
        }
    }
    
    int ans=min(min(r,g),b);
    printf("%d\n",ans);

	return 0;
}
