
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
   char data[200];
   char stuf[200];
   char destuf[200];
   printf("Enter Data : ");
   scanf(" %[^\n]", data);
   printf("Original Data : %s",data);
   bit_stuf(data, stuf);
   printf("\nStuffed Data : %s", stuf);
   bit_destuf(stuf, destuf);
   printf("\nDestuffed Data : %s",destuf);


}





void bit_stuf(char data[], char stuf[])
{
    stuf[0] = 'F';
    int k=1;
    for(int i=0; i<strlen(data); i++)
    {
        if(data[i]=='F' )
        {
            stuf[k]='E';
            k++;

        }
        stuf[k]=data[i];
        k++;


    }
    stuf[k]='F';
    stuf[k+1]='\0';



}



void bit_destuf(char stuf[], char destuf[])
{
    int k=0;

    for(int i=1; i<strlen(stuf)-1; i++)
    {
        if(stuf[i]=='E' && stuf[i+1]=='F'  )

        {
            destuf[k]= 'F';
            k++;
            i++;

        }else {

         destuf[k]= stuf[i];
            k++;

        }
    }

    destuf[k]='\0';

}

