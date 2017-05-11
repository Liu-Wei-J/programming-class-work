#include<stdlib.h>
#include<stdio.h>

void print(int *ptr);
void dilation(int *ptr);

int main(void){
    int a[25]={0},i;
    srand(time(NULL));

    for(i=0;i<25;i++){
        a[i]=(rand()%3/2);
    }
    print(a);
    dilation(a);
    print(a);


}

void print(int *ptr){
    int i;

    for(i=0;i<25;i++){
        printf("%d\t",ptr[i]);
        if(i%5==4){
            printf("\n");
        }
    }
    printf("\n\n\n");
    return;
}

void dilation(int *ptr){
    int i,a[25]={0};
    for(i=0;i<25;i++){
        if(ptr[i]==1){
            a[i]=1;
            if(i>4)
              a[i-5]=1;
            if(i<20)
                a[i+5]=1;
            if(i%5>0)
                a[i-1]=1;
            if(i%5<4)
                a[i+1]=1;
        }
    }
    for(i=0;i<25;i++){
        ptr[i]=a[i];
    }
}
