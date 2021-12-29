#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int ans=(a[0]+a[1])/2;
    printf("%d ",ans);

    for(int i=1;i<n-1;i++){
        ans=(a[i-1]+a[i]+a[i+1])/3;
        printf("%d ",ans);
    }

    ans=(a[n-2]+a[n-1])/2;
    printf("%d\n",ans);

    return 0;
}