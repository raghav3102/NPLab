//C Program to implement Bit Stuffing, encoding and decoding concept in DDL

#include<stdio.h>
#include<string.h>
void main()
{
    int n, i;
    printf("Enter size of frame");
    scanf("%d",&n);
    int frame[n];
    printf("Enter the frame\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&frame[i]);
    }
    int count=0;
    for(i=0;i<n;i++)
    {
        if(count==5&&frame[i]==1)
        {
            printf("01");
            count=1;
        }
        else if(count<5&&frame[i]==1)
        {
            count++;
            printf("1");
        }
        else if(frame[i]==0)
        {
            printf("0");
            count=0;
        }
    }
}
