#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int show_table(int state[6][6],char table[6][6]){
    int i,j;
    char w[3];
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
    printf("input the position:");
    scanf("%s",w);

    state[w[1]-'0'][w[0]-'A'+1]=1;

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


void set_state(int state[6][6]){
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++)
            state[i][j]=0;
    }
}

int main(){
    int state[6][6];
    char table[6][6];
    set_state(state);
    set_table(table);

    while(1)
        show_table(state,table);
}
