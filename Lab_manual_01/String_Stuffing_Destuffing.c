#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int add_ex(int k, char stuf[]);
void bit_stuf(char data[], char stuf[]);
int main()
{

char data[1000];
char stuf[1000];
char destuf[1000];
printf("Enter : ");
scanf(" %[^\n]",data);

bit_stuf(data, stuf);
printf("Stuffed Data : %s", stuf);





}


bool isFlag(int k, char data[])
{
    char flag[] = "GALF\0";

    return strncmp(&data[k],flag,4)==0;
}


bool isEx(int k, char data[])
{
    char ex[] = "EPACSE\0";

    return strncmp(&data[k],ex,6)==0;
}






int add_ex(int k, char stuf[])
{
     char ex[] = "EPACSE\0";
     int cnt=0;

    for(int i=0; i<strlen(ex); i++)
    {
        stuf[k]=ex[i];
        k++;
        cnt++;
    }
    return k;

   // printf("\n The value of K : %d",cnt);

}






void bit_stuf(char data[], char stuf[])
{

    int k=0;
    char flag[] = "GALF\0";



    for(int i=0; i<strlen(flag); i++)
    {
        stuf[k]= flag[i];
        k++;
    }


    for(int i=0; i<strlen(data); i++)
    {
        if(isFlag(i,data) || isEx(i, data))
        {

           k= add_ex(k, stuf);


        }
        stuf[k] = data[i];
        k++;


    }


    for(int i=0; i<strlen(flag); i++)
    {
        stuf[k]= flag[i];
        k++;
    }




    stuf[k] ='\0';




}
