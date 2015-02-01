#include <iostream>
#include <string>
# include <stdio.h>
# include <stdlib.h>
using namespace std;

int main()
{
string str;
cin>>str;
int i,j;
int ctr=0,n=0;
int s = str.size();
for( i=s-1;i>=0;--i)
{
if(str[i] == ',')
ctr++;
}
n=ctr+1;
int arr[n];
ctr=n;
for(i=s-1;i>=0;--i)
{
if(str[i] == ',')
{
ctr--;

char a[s-1-i];
for(j=0;j<(s-i-1);++j)
{
a[j] = str[i+j+1];
}
arr[ctr] = atoi(a);
}
}
char a[s-1-i];
for(j=0;j<(s-i-1);++j)
{
a[j] = str[j];
}
arr[0] = atoi(a);

cout<<"Set S:\n";
for(int k=0;k<n-1;k++)
cout<<arr[k]<<" ";
cout<<'\n';
cout<<"Value of limit= "<<arr[n-1];
cout<<"\nSubsets (a,b,c,d) which satisfy a+b+c*d <=limit are:\n";
int StoreSets[10000][4];
int counter=0;
int size_S=n-1;
int e,b,c,d;
  for(i=0;i<size_S;i++){
      e=arr[i];
      for(j=0;j<size_S;j++){
          if(i==j) j=j+1; 
          if(j<size_S) b=arr[j];
          else break;
          for(int k=0;k<size_S;k++){
              if(i==k or j==k) k=k+1;
              if(i==k or j==k) k=k+1;
              if(k<size_S) c=arr[k];
              else break;
              for(int l=0;l<size_S;l++){
                  if(l==i or l==j or l==k) l=l+1;
                  if(l==i or l==j or l==k) l=l+1;
                  if(l==i or l==j or l==k) l=l+1;
                  if(l<size_S) d=arr[l];
                  else break;
                  if(counter==0){ 
                                  StoreSets[counter][0]=e;
                                  StoreSets[counter][1]=b;
                                  StoreSets[counter][2]=c;
                                  StoreSets[counter][3]=d;
                                  counter=counter+1;
                  if(e+b+c*d<=arr[n-1]){
                      cout<<"<"<<e<<","<<b<<","<<c<<","<<d<<">\n";
                      } 
                  }
                  else{
                      int done=0;
                       for(int l=0;l<counter;l++){
                       if(StoreSets[l][0]==e and StoreSets[l][1]==b and StoreSets[l][2]==c and StoreSets[l][3]==d) {
                           done=1;break;}
                       }
                       if(done==0){
                       StoreSets[counter][0]=e;
                       StoreSets[counter][1]=b;
                       StoreSets[counter][2]=c;
                       StoreSets[counter][3]=d;
                       counter=counter+1;
                       if(e+b+c*d<=arr[n-1]){
                                             cout<<"<"<<e<<","<<b<<","<<c<<","<<d<<">\n";
                                        }
                       }
                       }
                        
                  }
              }
          }
      }
     return 0;
}
