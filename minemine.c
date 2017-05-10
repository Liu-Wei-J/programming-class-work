#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ups(char *s){
	int i,n;
	n=strlen(s);
	for(i=0;i<n;i++){
		if(96<s[i]&&s[i]<123){
			s[i]-=32;
		}
	}
}

int enter(int *point,int state[6][6],char table[6][6]){
	
int i,n;
char w[10];


	while(1){
		printf("input the position:");
    	scanf("%s",w);
    	ups(w);
    	n=strlen(w);
    
    	if(n!=2){
			printf("your input unconform to the format\n\n");
			continue;
		}
		else if(64<w[0]&&w[0]<70&&'0'<w[1]&&w[1]<'6'){	//ok
			break;
		}
	
		else{
			printf("your input unconform to the format\n\n");
			continue;		
		}
	}
	
	if(table[w[1]-'0'][w[0]-'A'+1]=='B'){
		return 3;	//find bob
	}	
	
    else if(state[w[1]-'0'][w[0]-'A'+1]==0){
    	state[w[1]-'0'][w[0]-'A'+1]=1;
    	*point+=1;
    	if(*point == 20)
			return 0;
			
    	return 1;
	}
	else
		return 1;


	
	if(*point == 20)
		return 0;	//win the game


 	
		
}


void show_table(int state[6][6],char table[6][6]){
    int i,j;
    system("CLS");
    
    printf("\t");
    for(i=1;i<6;i++){
        printf("%c\t",'A'-1+i);
    }
    printf("\n");

    
    for(i=1;i<6;i++){

        printf("%c\t",'0'+i);	
        for(j=1;j<6;j++){
            if(state[i][j]==1)
                printf("%c\t",table[i][j]);
            else
                printf("X\t");
        }
        printf("\n");
    }
    
}


void END(int end,int state[6][6],char table[6][6]){
	int i,j;
/*
end:
1	unend
0	win
3	bomb
*/
	if(end==3){
		set_state(state,table,3);
		show_table(state,table);
		printf("you get the bomb \(QvQ\)");
		exit(3);
				
	}
	
	
	
	if(end==0){
		set_state(state,table,1);
		show_table(state,table);
		printf("you win!! <\(_ _\)>");
		exit(0);
	}
	
}

void set_table(char bob[6][6]){
    int i,j,r,n=0;
    srand(time(NULL));
    while(1){
        
        r=rand()%25;
        if(bob[r/5+1][r%5+1] != 'B'){
            bob[r/5+1][r%5+1]='B';
            n++;
        }

        if(n==5)
            break;
    }
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(bob[i][j] != 'B'){
                int k=0,i1,j1;
                for(i1=0;i1<3;i1++){
                    for(j1=0;j1<3;j1++){
                        if(bob[i-1+i1][j-1+j1]=='B')
                            k++;
                    }
                }
                bob[i][j]='0'+k;
            }
        }
    }




}


void set_state(int state[6][6],char table[6][6],int show){	
/*
show:
1	show
2	unshow
3	show bob
*/
    int i,j;
    if(show==3){
    	for(i=0;i<6;i++){
        	for(j=0;j<6;j++){
        		if(table[i][j]=='B'){
        			state[i][j]=1;
				}
			} 	
    	}
	}
    else{
    	for(i=0;i<6;i++){
        	for(j=0;j<6;j++)
            	state[i][j]=show;
    	}
    	
	}

}

int main(){
	
    int state[6][6],point=0,end=1;
    char table[6][6];
    set_state(state,table,0);	//the state mean show table or not
    set_table(table);	//put bob on table
    //show table 
    //enter position
    	//error
    	//contenu
    	//bob
    	//win
 /*
end:
1	unend
0	win
3	bomb
*/
    do{	
		
    	show_table(state,table);
    	end=enter(&point,state,table);
    	printf("\nend=%d,\tpoint=%d\n",end,point);
    	system("pause");
    	
    	
	}while(end==1);
    
    END(end,state,table);
    
	
        
}
