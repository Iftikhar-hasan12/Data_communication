#include<stdio.h>

char * ToBin(char ip[]);
int main()
{

    char ip[100];
    printf("Enter  Decimal Digit : ");
    scanf(" %[^\n]", ip);

    char *token = strtok(ip, ".");

    while(token!=NULL)
    {

        printf(" %d",ToBin(token));
        token = strtok(NULL,".");

    }


}




char * ToBin(char ip[])
{

    static char bin[9];
    int n= atoi(ip);

    for(int i=0; i<8; i++)
    {
        bin[i]= '0';
    }
    bin[8]='\0';

    int rem ;
    int k=7;
    for(int i=n; i!=0; i=i/2)
    {
        rem = i%2;
        bin[k--]= rem+'0';
    }
    return bin;



}
