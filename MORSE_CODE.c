/*CONVERTING A SENTENCE TO A MORSE CODE.
INFO:DOT IS 1, DASH IS 2, EVERY NEW LETTER PRECEDES BY 3 AND EVERY NEW WORD PRECEDES BY 4.*/

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct store
{
   int out[1000];
   int j;
}STRUCT;

int morse(char ch)                      //Returns morse of the letter.
{  int arr[]={12,2111,2121,211,1,1121,221,1111,11,1222,212,1211,22,21,222,1221,2212,121,111,2,112,1112,122,2112,2122,2211};
   int n=(toupper(ch))-65;
   return arr[n];
}

int converter(char a[1000], STRUCT obj) //Converts string to number formatted morse.
{

    for (int i=0;i<strlen(a);i++)
    {
        if(a[i]==' ')
        {
            obj.out[obj.j]=4;
            obj.j++;
        }
        else
        {
            obj.out[obj.j]=morse(a[i]);
            obj.j++;
            obj.out[obj.j]=3;
            obj.j++;
        }
    }
    
    for(int k=0; k<(obj.j-1);k++)      //Displays the converted string.
    {
        printf("%d",obj.out[k]);
    }
}
int main()
{
    char a[1000];
    STRUCT obj;
    obj.j=0;

    printf("Enter message: ");
    scanf("%[^\n]s",&a);               //Important:inputs string including space.

    converter(a,obj);               
}
