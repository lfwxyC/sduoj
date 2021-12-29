#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    int s[m],client[m]; // s[]:客人到店时间,client[]:客人喜爱的配料 
    vector<int> t(n),ing(n); // t:面做好的时间,ing:面的配料 
    
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d",&x);

		ing[i]=0;
		// 用二进制位表示配料的有无 
        for(int j=0;j<x;j++){
            scanf("%d",&y);
        	ing[i]|=1<<(y-1);
        }
    }

    for(int i=0;i<m;i++){
        scanf("%d",&s[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int x,y;
        scanf("%d",&x);

		client[i]=0;
        for(int j=0;j<x;j++){
            scanf("%d",&y);
            client[i]|=1<<(y-1);
        }
    }
    
    for(int i=0;i<m;i++){
        int j,tsize=t.size();

		// 从后往前遍历面，第一个满足条件的j即为距顾客到店时间最近的 
        for( j=tsize-1;j>=0;j--){
        	
			// 满足条件，输出满意度并删除面 
			if((client[i]&ing[j])==client[i]){
				printf("%d\n", s[i] - t[j]);
                t.erase(t.begin()+j);
                ing.erase(ing.begin()+j);
                break;
			}   
        }
		
		// 没有满足条件的面 
        if (j < 0)
        {
            printf("Angry\n");
        }
    }

    return 0;
}
