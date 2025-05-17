#include<stdio.h>

char * ToBin(char ip[]);
int main()
{

    char ip[100];
    printf("Enter Binary digit : ");
    scanf(" %[^\n]", ip);

    char *token = strtok(ip, ".");

    while(token!=NULL)
    {

        printf(" %d",ToDec(token));
        token = strtok(NULL,".");

    }


}

int ToDec(char ip[])
{
    int bin = atoi(ip);
    int rem, base =1, dec =0;

    for(int i = bin; i!=0; i=i/10)
    {
        rem = i%10;
        dec = dec + (rem * base );
        base = base *2;

    }

    return dec;


}

