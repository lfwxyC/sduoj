#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    stack<pair<string,string>> s;
    int a[11],sum[11],cnt=0,maxPower=0,loopCnt=0,endCnt=0,minus=-2;
    int total[11];
    bool flag=true;
    
    for(int i=0;i<11;i++){
        a[i]=0;
        sum[i]=0;
        total[i]=0;
    }

    while(cin>>str)
    {
        if(str=="LOOP"||str=="OP"){ // ��ջ 
            string c;
            cin>>c;
            
            if(str=="LOOP"){
            	// ���ѭ������Ƕ�ײ��е�ѭ�� 
            	if(endCnt&&flag){
            		// ����һ��ѭ���Ľ������sum�б��棬���a 
            		for(int i=0;i<11;i++){
            			sum[i]+=a[i];
            			a[i]=0;
					}
					
					minus=loopCnt-endCnt; // ��¼���е�ѭ����λ�� 
					flag=false;
				}
            	
            	loopCnt++;
			}
            
            if(c=="n"){
                cnt++; // n���ݴ�+1 
                maxPower=cnt;
            }
            s.push(make_pair(str,c));
        }
        
        else if(str=="END"){ // ��ջ 
        	endCnt++;
        	
            while(!s.empty()&&s.top().first=="OP"){ // ��������OP��ֱ������LOOPֹͣ 
            	int num=stoi(s.top().second);
                a[cnt]+=num; // OP���еĴ�����Ϊcnt�η���ϵ�� 
                s.pop();
            }

            if(!s.empty()&&s.top().first=="LOOP"){
                if(s.top().second!="n"){
                	for(int i=0;i<11;i++){
                		int num=stoi(s.top().second);
                		a[i]*=num; // ÿһ�����LOOP�Ĵ��� 
					}
                }

                else{
                    cnt--; // �ݴ�-1 
                }
                s.pop();
            }

			if(loopCnt-endCnt==minus){ // ���е�ѭ����������sum�б���Ľ���ŵ�a�У����sum 
				for(int i=0;i<11;i++){
					a[i]+=sum[i];
					sum[i]=0;
				}
				flag=true;
			}

			else if(loopCnt==endCnt){ // ѭ��ȫ�������������ѭ���Ľ���������ս��total�У����a 
				for(int i=0;i<11;i++){
					total[i]+=a[i];
					a[i]=0;
				}
				
				loopCnt=0;
				endCnt=0;
				minus=-2;
			}

           	if(loopCnt+1==endCnt){ // ��������BEGINƥ���END,�������ս��total,ֹͣ���� 
           		for(int i=0;i<11;i++){
					total[i]+=a[i];
					a[i]=0;
				}
                break;
            }
        }
    }
    
    printf("Runtime = ");

	// ������Ҫ������� 
    int addCnt=0;
    for(int i=0;i<11;i++){
        if(total[i]){
            addCnt++;
        }
    }

	// ����ʱ��Ϊ0 
    if(addCnt==0){
        printf("0\n");
    }

    else{
        for(int i=10;i>=2;i--){
            if(total[i]){
            	// ϵ����Ϊ1 
                if(total[i]!=1){
                    printf("%d*n^%d",total[i],i);
                }
				// ϵ��Ϊ1 
				else{
                    printf("n^%d",i);
                }

                if(addCnt-1){ // �����滹����Ҫ��������ӡ"+" 
                    printf("+");
                    addCnt--;
                }
            }
        }
        
        // �ݴ�Ϊ1 
        if(total[1]){
        	if(total[1]!=1){
        		printf("%d*n",total[1]);
			}else{
				printf("n");
			}
		}
		
		if(addCnt-1){
			printf("+");
		}
        
        // �ݴ�Ϊ0 
        if(total[0]){
            printf("%d\n",total[0]);
        }
    } 
    
    return 0;
}
