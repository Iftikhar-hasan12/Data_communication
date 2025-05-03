#include<stdio.h>
#include<string.h>
#include<stdbool.h>


int main()
{
    char data[200];
    char stuf[200];
    char destuf[200];

    scanf(" %[^\n]",data);
    char_stuf(data, stuf);

      char_destuf(stuf, destuf);


    printf("Original data : %s",data);

    printf("\nStuffed data : %s",stuf);

    printf("\nDeStuffed data : %s",destuf);



}


bool is_flag(char stuf[], int k)
{
    return strncmp(&stuf[k],"DLE",3)==0;

}



void char_destuf(char stuf[], char destuf[])
{
    int k=0;
    for(int i=0; i< strlen(stuf); i++)
    {
        if(stuf[i]=='D' && stuf[i+1]=='L' && stuf[i+2]=='E')
        {
            i=i+3;

        }
        if(i <strlen(stuf) )
        {
            destuf[k]= stuf[i];
            k++;
        }

    }

}




void char_stuf(char data[], char stuf[] )
{

    char flag[]="DLE";
    int k;
    for(int i=0; i<3; i++)
    {
        stuf[i] = flag[i];
        k=i;

    }
    k++;


    for(int i=0; i<strlen(data); i++)
    {
        if(data[i]=='D' && data[i+1]=='L' && data[i+2]=='E')
        {
            stuf[k] ='D';
            stuf[k+1] ='L';
            stuf[k+2] ='E';
            k=k+3;
        }
        stuf[k] = data[i];
        k++;

    }

    for(int i=0; i<3; i++)
    {
        stuf[k] = flag[i];
        k++;

    }

    stuf[k] = '\0';


}
