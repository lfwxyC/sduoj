#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int r,y,g,n,ans=0;
    cin>>r>>y>>g>>n;

    for(int i=0;i<n;i++){
        int k,t;
        cin>>k>>t;

        switch (k)
        {
        case 0:
            ans+=t;
            break;
        case 1:
            ans+=t;
            break;
        case 2:
            ans+=t+r;
            break;
        case 3:
            break;
        default:
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}