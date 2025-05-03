#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isFlag(int k, char stuf[]);
void bit_destuf(char stuf[], char destuf[]);
void bit_stuf(char data[], char stuf[]);

int main()
{
    char data[200]= "1011010111111010\0";
    char stuf[200];
    char destuf[200];
    int size = strlen(data);


    bit_stuf(data, stuf);
    printf("Original Data : %s", data);
    printf("\nStuffed Data : %s", stuf);
    bit_destuf(stuf, destuf);
    printf("\nDe_Stuffed Data : %s", destuf);


}

bool isFlag(int k, char stuf[])
{

    char flag[] ="01111110";
    return strncmp(&stuf[k], flag,8)==0;

}


void bit_destuf(char stuf[], char destuf[])
{
int count=0;
int k=0;
    for(int i=0; i<strlen(stuf); i++)
    {
        if(isFlag(i,stuf) && (7 < (strlen(stuf) - i ) ) )
        {
            i= i+7;
            // continue ;

        }
        else
        {


            if(stuf[i]=='1')
            {

                count++;
                destuf[k] = '1';
                k++;
            }
            else
            {
                count=0;
                destuf[k] = '0';
                k++;

            }
            if(count==5)
            {
                count=0;
                //destuf[k] = '0';
                i++;


            }



        }





    }


destuf[k] = '\0';



}

















void bit_stuf(char data[], char stuf[])
{
    char flag[] ="01111110";
    int count=0;
    int k=0;
    for(int i=0; i<8; i++)
    {
        stuf[i] = flag[i];
        k=i;

    }
k++;

    for(int i=0; i<strlen(data); i++)
    {

        if( data[i]=='1')
        {
            count++;
            stuf[k]='1';
            k++;
        }
        else
        {

            count=0;
            stuf[k]='0';
            k++;

        }


        if(count==5)
        {
            count=0;
            stuf[k]='0';
            k++;
        }

    }

    for(int i=0; i<8; i++)
    {
        stuf[k] = flag[i];
        k++;

    }

stuf[k]='\0';



}
