#include<stdio.h>
int main(){
    int ip,op,bs,sto,n,sl;
    sto = 0;
    printf("Enter the number of queries: \n");
    scanf("%d",&n);
    printf("Enter the input packet size: \n");
    scanf("%d",&ip);
    printf("Enter the output packet size: \n");
    scanf("%d",&op);
    printf("Enter the bucket size: \n");
    scanf("%d",&bs);
    for(int i=0;i<n;i++){
        sl = bs - sto;
        if(ip <= sl){
            sto += ip;
        }
        else{
            printf("Packet loss: %d \n",ip);
        }
        printf("Buffer size %d out of bucket size %d \n",sto,bs);
        sto -= op;
    }
    return 0;
}
