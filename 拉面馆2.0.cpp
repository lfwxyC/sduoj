#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    int s[m],client[m]; // s[]:���˵���ʱ��,client[]:����ϲ�������� 
    vector<int> t(n),ing(n); // t:�����õ�ʱ��,ing:������� 
    
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d",&x);

		ing[i]=0;
		// �ö�����λ��ʾ���ϵ����� 
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

		// �Ӻ���ǰ�����棬��һ������������j��Ϊ��˿͵���ʱ������� 
        for( j=tsize-1;j>=0;j--){
        	
			// �����������������Ȳ�ɾ���� 
			if((client[i]&ing[j])==client[i]){
				printf("%d\n", s[i] - t[j]);
                t.erase(t.begin()+j);
                ing.erase(ing.begin()+j);
                break;
			}   
        }
		
		// û�������������� 
        if (j < 0)
        {
            printf("Angry\n");
        }
    }

    return 0;
}
