
#include<stdio.h>
#include<string.h>
char* ToBin(char ch[]);
int main()
{
   // char ip[100];
    printf("Enter : ");
   // scanf("% [^\n]",ip);
     //char ip[40]="11.22.33.4";
     char ip[40]="11.10.001.0";
    char*token = strtok(ip, ".");

    while(token!=NULL)
    {
        printf("%d ",ToDec(token));

        token = strtok(NULL, ".");
    }

}

int ToDec(char ch[])
{
    int n = atoi(ch);
    int len=strlen(ch);
    int base =1;
    int dec =0;

    for(int i=len-1; i>=0 ; i--)
    {
        if(ch[i]=='1')
        {
            dec = base + dec;
        }
        base = base *2;

    }
    return dec;

}







char* ToBin(char ch[])
{
   static char bin[9];
    for(int i=0; i<8; i++)
    {
        bin[i]='0';
    }

    int n = atoi(ch);
    int rem ;
    int k=7;
    for(int i=n; i!=0; i=i/2)
    {
        rem = i%2;
        bin[k]=rem+'0';
        k--;

    }
bin[8]='\0';


    return bin;



}
