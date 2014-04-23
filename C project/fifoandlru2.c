#include<stdio.h>
int fr[5];
int fs[5];
void main()
{
int numbers[28] = { 0, 1, 2, 3, 2, 4, 5, 3, 4, 1, 6, 3, 7, 8, 7, 8, 4, 9, 7, 8, 1, 2, 9, 5, 4, 5, 0, 2};
int i = 0;
int j,k,l;
int index = 0;
int flag1 = 0, flag2 = 0;
int frame[5],frsize;
int pfcount=0;

int n = 27;
int choice;
int extra = n + 1;
printf("Please Enter 1 or 2 for your choice\n");
printf(" Enter 1 for FiFo\n");
printf(" Enter 2 for LRU\n");
scanf("%d",&choice);
while( choice != 1 && choice != 2)
{
printf("Please Enter 1 or 2 for your choice\n");
printf(" Enter 1 for FiFo\n");
printf(" Enter 2 for LRU\n");
scanf("%d",&choice);
}
            
printf("\n ENTER THE NUMBER OF FRAMES BETWEEN 1 AND 5:\n");
scanf("%d",&frsize);
while( frsize != 1 && frsize != 2 && frsize != 3 && frsize != 4 && frsize != 5)
{
printf("\n ENTER THE NUMBER OF FRAMES BETWEEN 1 AND 5:\n");
scanf("%d",&frsize);
}
            
if ( choice == 1) 
{         
for(i=0;i<frsize;i++)
     {
       frame[i]=-1;
     }                    

                        flag2=0;
                       
for(i=1;i<=n;i++)
                        {
                                    
                                    flag1 =0;
                                    for(k=0;k<frsize;k++)
if(frame[k] == numbers[i])
                                                flag1 =1;
                                    if (flag1 ==0)
                                    {
                                                
                                                frame[flag2]=numbers[i];
                                                flag2=(flag2+1)%frsize;
                                                pfcount++;
                                                
}                                               for(k=0;k<frsize;k++)
                                                printf("\t%d",frame[k]);
                                    printf("\n");
}
                        printf("Page Fault is %d",pfcount);
                       
}

if ( choice == 2)
{
      for(i=0;i<frsize;i++)
     {
       fr[i]=-1;
     }   
     for( j = 0; j < extra; j++)
       {
       flag1=0,flag2=0;
       for(i=0;i<3;i++)
       {
       if(fr[i]==numbers[j])
       {
       flag1 = 1;
       flag2 = 1;
       break;
       }}
       if(flag1==0)
       { 
       for(i=0;i<frsize;i++)
       {
       
       if(fr[i]==-1)
       {
       fr[i]=numbers[j];
       flag2=1;
       pfcount++;
       break;
       }
       }
       }
       if(flag2==0)
       {
       for(i=0;i<frsize;i++)
       {
          fs[i]=0;
          }
       for(k=j-1,l=1;l<=frsize-1;l++,k--)
       {
       for(i=0;i<frsize;i++)
       {
       if(fr[i]==numbers[k])
       fs[i]=1;
       }
       }
       for(i=0;i<frsize;i++)
       {
       if(fs[i]==0)
       index=i;
       }
       
       fr[index]=numbers[j];
       pfcount++;
       }
       printf("\n");
       for(i=0;i<frsize;i++)
       printf("\t%d",fr[i]);
       }
     printf("\n Page Fault is :%d",pfcount);
     
} 
               printf("\nENTER SOMETHING TO CLOSE THE PROGRAM");
                       scanf("%d",&choice);        
}
