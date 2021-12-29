#include<bits/stdc++.h>
using namespace std;

void myComplex(int loopNum,int mul,int b[]){
	string str;
	int a[11];
	
	for(int i=0;i<11;i++){
		a[i]=0;
	}
	
	while(cin>>str){
		if(str=="LOOP"){
			char c;
			cin>>c;
			
			if(c=='n'){
				myComplex(loopNum+1,1,a);
			}
			else{
				myComplex(loopNum,c-'0',a);
			}
		}
		else if(str=="OP"){
			char c;
			cin>>c;
			
			a[loopNum]+=c-'0';
		}
		else if(str=="END"){
			break;
		}
	}
	
	for(int i=loopNum;i<11;i++){
		a[i]*=mul;
		b[i]+=a[i];
	}
}

int main(){
	string str;
	int coefficient[11];
	
	for(int i=0;i<11;i++){
		coefficient[i]=0;
	}
	
	while(cin>>str){
		if(str=="LOOP"){
			string c;
			cin>>c;
			
			if(c=="n"){
				myComplex(1,1,coefficient);
			}else{
				int num=stoi(c);
				myComplex(0,num,coefficient);
			}
		}
		else if(str=="OP"){
			int c;
			scanf("%d",&c);
			
			coefficient[0]+=c;
		}
		else if(str=="END"){
			break;
		}
	}
	
	printf("Runtime = ");

    int addCnt=0;
    for(int i=0;i<11;i++){
        if(coefficient[i]){
            addCnt++;
        }
    }

    if(addCnt==0){
        printf("0");
    }
    else{
    	bool flag=true;
        for(int i=10;i>=2;i--){
            if(coefficient[i]){
            	if(flag){
            		flag=false;
            		
            		if(coefficient[i]!=1){
	                    printf("%d*n^%d",coefficient[i],i);
	                }else{
	                    printf("n^%d",i);
	                }
				}
                else{
                	if(coefficient[i]!=1){
	                    printf("+%d*n^%d",coefficient[i],i);
	                }else{
	                    printf("+n^%d",i);
	                }
				}
            }
        }
        
        if(coefficient[1]){
        	if(flag){
        		flag=false;
        		
        		if(coefficient[1]!=1){
	        		printf("%d*n",coefficient[1]);
				}else{
					printf("n");
				}
			}else{
				if(coefficient[1]!=1){
	        		printf("+%d*n",coefficient[1]);
				}else{
					printf("+n");
				}
			}
		}
	
        if(coefficient[0]){
        	if(flag){
        		printf("%d",coefficient[0]);
			}
            else{
            	printf("+%d",coefficient[0]);
			}
        }
    } 
    
    return 0;
}
