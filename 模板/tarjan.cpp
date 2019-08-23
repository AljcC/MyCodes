#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int f[30][1000];
int Path[30][1000];
int P[300];
int D[300];
int Answer[30];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
   int i,j,k;
    int t1,t2;
    int n,m;
    int nMinP_D;
    int iCase;
    iCase=0;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)break;
        iCase++;
        for(i=1;i<=n;i++)
           scanf("%d %d",&P[i],&D[i]);
        memset(f,-1,sizeof(f));
        memset(Path,0,sizeof(Path));
        nMinP_D=m*20;
        f[0][nMinP_D]=0;
         for(j=0;j<m;j++)
        {
            for(k=0;k<=nMinP_D*2;k++)
               if(f[j][k]>=0)
               {
                   for(i=1;i<=n;i++)
                       if(f[j][k]+P[i]+D[i]>f[j+1][k+P[i]-D[i]])
                       {
                           t1=j;t2=k;
                           while(t1>0&&Path[t1][t2]!=i)
                           {
                               t2-=P[Path[t1][t2]]-D[Path[t1][t2]];
                               t1--;
                           }
                           if(t1==0)
                           {
                               f[j+1][k+P[i]-D[i]]=f[j][k]+P[i]+D[i];
                               Path[j+1][k+P[i]-D[i]]=i;
                           }
                       }
               }
        }
        i=nMinP_D;
        j=0;
        while(f[m][i+j]<0&&f[m][i-j]<0)  j++;
        if(f[m][i+j]>f[m][i-j])  k=i+j;
        else k=i-j;
        printf("Jury #%d\n",iCase);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",(k-nMinP_D+f[m][k])/2,(f[m][k]-k+nMinP_D)/2);
        for(i=1;i<=m;i++)
        {
            Answer[i]=Path[m-i+1][k];
            k-=P[Answer[i]]-D[Answer[i]];
        }
        qsort(Answer+1,m,sizeof(int),cmp);
        for(i=1;i<=m;i++)
          printf(" %d",Answer[i]);
        printf("\n\n");

    }
    return 0;
}
