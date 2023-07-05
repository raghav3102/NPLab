#include<stdio.h>
#include<string.h>
char res[100];
void sender(){
    int i,len,n;
    char f[100],l[100];
    printf("Enter the number of frames: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the frame %d: \n",i+1);
        scanf("%s",f);
        len = strlen(f);
        sprintf(l,"%d",len);
        printf("Size of frame %d: %d \n",i+1,len);
        strcat(l,f);
        strcat(res,l);
    }
    printf("The final message is : %s \n",res);
}
void receiver(){
    int i,j,l;
    printf("The received frame is: ");
    for(i=0;i<strlen(res);i++){
        l = res[i] - '0';
        for(j=i;j<(i+l);j++){
            printf("%c ",res[j]);
            i = i + l;
        }
    }
    printf("\n");
}
int main(){
    sender();
    receiver();
    return 0;
}
