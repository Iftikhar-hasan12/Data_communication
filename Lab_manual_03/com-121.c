#include<stdio.h>
char* ToBin(char data[]);
int main()
{


    char ip[200];
    char stuf[200];
    char destuf[200];
    printf("Enter Decimal number : ");
    scanf(" %[^\n]",ip);

    char*token = strtok(ip,".");
    while(token!=NULL)
    {


        printf(" %d",ToDec(token));

        token =strtok(NULL,".");
    }

}

char* ToBin(char data[])
{
    int n=atoi(data);
    static char bin[9];
    for(int i=0; i<8; i++)
    {
        bin[i]='0';


    }

    int k=7;
    int rem;
    for(int i = n; i!=0; i = i/2 )
    {

        rem = i%2;
        bin[k--]=rem+'0';
    }



    bin[8]='\0';






    return bin;
}



int ToDec(char data[])
{

int n = atoi(data);

int base=1, rem, dec=0;

for(int i=n; i!=0; i= i/10)
{
    rem = i%10;
    dec = dec + (base*rem);
    base = base *2;

}





return dec;

}





//------
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




//-------
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







//-----------

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






//-----------
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



