#include<stdio.h>
#include<string.h>
char frame[100];
void encode(){
    int i,j,len,count;
    len = strlen(frame);
    for(i=0,count=0;i<len;i++){
        if(frame[i] == '1')
        count++;
        else
        count = 0;
        if(count == 5){
            for(j=len;j>i;j--){
                frame[j] = frame[j-1];
            }
            frame[i+1] = '0';
            count = 0;
            len++;
        }
    }
    printf("Encoded frame after bitstuffing: %s \n",frame);
}
void decode(){
    int i,j,len;
    char f2[100];
    len = strlen(frame);
    for(i=0,j=0;i<len;i++){
        if(frame[i] == '1')
        f2[j++] = frame[i];
        else if(frame[i] == '0' && frame[i-1] == '1' && frame[i-2] == '1' && frame[i-3] == '1' && frame[i-4] == '1' && frame[i-5] == '1')
        continue;
        else
        f2[j++] = frame[i];
    }
    f2[j] = '\0';
    printf("Frame after decoding: %s \n",f2);
}
int main(){
    printf("Enter the frame: \n");
    scanf("%s",frame);
    encode();
    decode();
}
