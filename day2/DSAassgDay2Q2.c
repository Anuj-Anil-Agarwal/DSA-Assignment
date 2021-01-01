
//Write the program for printing the array after rotating it k times towards left, where k would be taken as user input.

#include <stdio.h>
int n=10;
int Array[10]={10,20,30,40,50,60,70,80,90,100};


void rotateA()
{
    int i,temp=Array[0];
    if(n<=0)
    {
         printf("\n Array is empty");
    }
    else
    {    
        for(i=1;i<n;i++)
            Array[i-1]=Array[i];
        Array[i-1]=temp;
    }
}



void displayArray()
{
    int i;
    if(n<=0)
    {
         printf("\n Array is empty");
    }
    else
    {
        printf("\n Elements of Array are \n");
        for(i=0;i<n;i++)
            printf(" %d ",Array[i]);
    }
}

int main() {

   int k,i;
   char c='y';
   // Array[10]
    displayArray();
    
    
  
    do{
        
        //taking value of k from user
        printf("\n Enter no of rotation to be perform ");
        scanf("%d",&k);
 
        //rotation
        for(i=0;i<k;i++)
        {
            rotateA();
        }
    
        printf("\n array has rotated %d times ",k);
        displayArray();
        //choice
        printf("\n Want to continue if NO enter e to exit ");
        scanf("%c",&c);
   
    }
    while(c!='e');
    
    return 0;
}
