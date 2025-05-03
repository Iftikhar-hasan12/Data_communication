#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag =1;
int DecimaltoBin(char *decimalStr)
{
    int decimal = atoi(decimalStr); // Convert string to integer
    int binary = 0, rem = 1;
    while (decimal > 0)
    {
        int remainder = decimal % 2;
        binary = binary + (remainder * rem);
        decimal /= 2;
        rem *= 10;
    }
    return binary;
}

void fun(char *decimalStr, char ch)
{
    int val = atoi(decimalStr);

    if(ch== 'A')
    {
        if( val >= 0 && val <=127)
        {
            printf(" %d belongs to class %c",val,ch);

        }
        else
        {
            printf("Class not match, Denied");
            flag=0;
        }
    }
    else if(ch=='B')
    {
        if( val >= 128 && val <=191)
        {
            printf(" %d belongs to class %c",val,ch);
        }
        else
        {
            printf("Class not match, Denied");
            flag=0;
        }
    }
    else if(ch=='C')
    {
        if( val >= 192 && val <=223)
        {
            printf(" %d belongs to class %c",val,ch);
        }
        else
        {

            printf("Class not match, Denied");
            flag=0;
        }
    }
    else if(ch=='D')
    {
        if( val >= 224 && val <=255)
        {
            printf(" %d belongs to class %c",val,ch);
        }
        else
        {
            printf("Class not match, Denied");

            flag=0;
        }
    }

}

int main()
{
    char binaryIP[36];
    char tokens[4][9];
    int IP[4];
    int i, j, k = 0;
    printf("Enter a dotted Decimal IP address: ");
    fgets(binaryIP, sizeof(binaryIP), stdin);
    binaryIP[strcspn(binaryIP, "\n")] = '\0';
    char val;
    printf("Enter class : ");
    scanf("%c",&val);
    for (i = 0, j = 0; binaryIP[i] != '\0'; i++)
    {
        if (binaryIP[i] == '.')
        {
            tokens[k][j] = '\0';
            k++;
            j = 0;
        }
        else
        {
            tokens[k][j] = binaryIP[i];
            j++;
        }
    }
    tokens[k][j] = '\0';
// assign kortesi ami.....................
    for (i = 0; i < 4; i++)
    {
        IP[i] =DecimaltoBin(tokens[i]);
        if(i==0)
        {
            fun(tokens[i],val);

        }
    }
    if(flag==1)
    {
        printf(" \nBinary IP address: %d.%d.%d.%d\n", IP[0], IP[1], IP[2],
               IP[3]);
    }
    return 0;
}
