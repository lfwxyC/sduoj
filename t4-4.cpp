#include<bits/stdc++.h>
using namespace std;

bool check(int i,int j,int n,int a[]){
      int last=0;
      for(int k=0;k<n;k++){
            if(i<=a[k]&&a[k]<=j){
                  continue;
            }

            if(a[k]<last){
                  return false;
            }

            last=a[k];
      }
      return true;
}

int main(){
      int n,x;
      scanf("%d%d",&n,&x);

      int a[n];
      for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
      }

      int ans=0;
      for(int i=1;i<=x;i++){
            int lo=i,hi=x+1;

            while(lo<hi){
                int mid=(lo+hi)/2;

                if(check(i,mid,n,a)){
                    hi=mid;
                }else{
                    lo=mid+1;
                }
            }

            ans+=x-lo+1;
      }

      printf("%d",ans);
      return 0;
}