# include <iostream>
# include <stdio.h>
# include <string>
# include <stdlib.h>
#include <algorithm>
using namespace std;

int StoreSets[1000][4];
int counter=0;
// this function prints all 4 possible combinations of a,b,c,d which satisfy the given condition (i.e. a,b,c,d and b,a,c,d and a,b,d,c and b,a,d,c)
void printSatisfyingSets(int a, int b, int c, int d, int limit){
if(a+b+c*d<=limit){
  if(a!=b and c!=d){
    cout<<"("<<a<<","<<b<<","<<c<<","<<d<<")\n";
    cout<<"("<<b<<","<<a<<","<<c<<","<<d<<")\n";
    cout<<"("<<b<<","<<a<<","<<d<<","<<c<<")\n";
    cout<<"("<<a<<","<<b<<","<<d<<","<<c<<")\n";
    }
  else if(a==b and c==d){
    cout<<"("<<a<<","<<b<<","<<c<<","<<d<<")\n";
       }
  else if(a==b and c!=d){
    cout<<"("<<a<<","<<b<<","<<c<<","<<d<<")\n";
    cout<<"("<<a<<","<<b<<","<<d<<","<<c<<")\n";}
  else if(a!=b and c==d){
    cout<<"("<<a<<","<<b<<","<<c<<","<<d<<")\n";
    cout<<"("<<b<<","<<a<<","<<c<<","<<d<<")\n";   
       }
    }
}

// This function finds those subsets (a,b,c,d) which satisfy the given condition
void CheckIfSatisfyCondition(int sets[],int limit,int k){
    int sortedset[4];
    sortedset[0]=sets[0];sortedset[1]=sets[1];sortedset[2]=sets[2];sortedset[3]=sets[3];
    sort(sortedset,sortedset+4);
    if(counter==0){ 
        StoreSets[counter][0]=sortedset[0];
        StoreSets[counter][1]=sortedset[1];
        StoreSets[counter][2]=sortedset[2];
        StoreSets[counter][3]=sortedset[3];
        counter=counter+1;
                }
    else{
         for(int l=0;l<counter;l++){
                 if(StoreSets[l][0]==sortedset[0] and StoreSets[l][1]==sortedset[1] and StoreSets[l][2]==sortedset[2] and StoreSets[l][3]==sortedset[3]) return;
                 }
         StoreSets[counter][0]=sortedset[0];
         StoreSets[counter][1]=sortedset[1];
         StoreSets[counter][2]=sortedset[2];
         StoreSets[counter][3]=sortedset[3];
         counter=counter+1;
         }
    //cout<<sets[0]<<" "<<sets[1]<<" "<<sets[2]<<" "<<sets[3]<<"\n";
    //cout<<sortedset[0]<<" "<<sortedset[1]<<" "<<sortedset[2]<<" "<<sortedset[3]<<"\n";
    
    int a,b,c,d;
    a=sortedset[0];b=sortedset[1];c=sortedset[2];d=sortedset[3];
    if(a==b and b==c and c==d){
    printSatisfyingSets(a,b,c,d,limit);
    return;            
        }
    else if((a==b and b==c and c!=d) or (a!=b and b==c and c==d) ){
    printSatisfyingSets(a,b,c,d,limit);
    int temp=d;d=a;a=temp;
    printSatisfyingSets(a,b,c,d,limit);
        }
    else if(a==b and c==d and b!=c){
    printSatisfyingSets(a,b,c,d,limit);
    int temp=d;d=a;a=temp;
    printSatisfyingSets(a,b,c,d,limit);
    a=sortedset[2];b=sortedset[3];c=sortedset[0];d=sortedset[1];
    printSatisfyingSets(a,b,c,d,limit);
        }
    else if(a==b and b!=c and c!=d){
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[2];c=sortedset[0];d=sortedset[3];
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[3];c=sortedset[2];d=sortedset[0];
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[2];b=sortedset[3];c=sortedset[0];d=sortedset[1];
    printSatisfyingSets(a,b,c,d,limit);
        }
        
    else if(a!=b and b!=c and c==d){
    printSatisfyingSets(a,b,c,d,limit);
    
    c=sortedset[0];a=sortedset[2];
    printSatisfyingSets(a,b,c,d,limit);
    
    c=sortedset[1];a=sortedset[0];b=sortedset[2];
    printSatisfyingSets(a,b,c,d,limit);
    
    c=sortedset[1];d=sortedset[0];a=sortedset[2];b=sortedset[3];
    printSatisfyingSets(a,b,c,d,limit);
        }
        
    else if(a!=b and b==c and c!=d){
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[1];b=sortedset[2];c=sortedset[0];
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[0];b=sortedset[3];c=sortedset[1];d=sortedset[2];
    printSatisfyingSets(a,b,c,d,limit);
    
        }
    else if(a!=b and b!=c and c!=d){
    a=sortedset[0];b=sortedset[2];c=sortedset[1];d=sortedset[3];
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[1];b=sortedset[2];c=sortedset[0];d=sortedset[3];
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[3];b=sortedset[0];c=sortedset[1];d=sortedset[2];
    printSatisfyingSets(a,b,c,d,limit);
    
    a=sortedset[3];b=sortedset[1];c=sortedset[2];d=sortedset[0];
    printSatisfyingSets(a,b,c,d,limit);
                
    a=sortedset[3];b=sortedset[2];c=sortedset[0];d=sortedset[1];
    printSatisfyingSets(a,b,c,d,limit);        
        }
    return;
}

//This function finds all possible subsets of set S, and then calls checkifsatisfyingcondition function, to find those subsets which satisfy the condtion
void subsets(int A[], int n, int k, int sets[], int index, int indexA, int limit)
{
    if(index == k)
    {
        CheckIfSatisfyCondition(sets,limit,k);
        return;
    }

    if(indexA >= n || n-indexA < k-index)
        return;
 
    sets[index] = A[indexA];
    subsets(A, n, k, sets, index+1, indexA+1,limit);
    subsets(A, n, k, sets, index, indexA+1,limit);
 }
 
int main()
{
//This part takes the input (comma separated)
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

//This part stores the S array, and value of limit/k, and then calls subsets function to find all possible subsets of size 4
int size=n-1;
int A[size];
int limit=arr[n-1];
cout<<"Set S:\n";
for(int l=0;l<size;l++){
    A[l]=arr[l];
    cout<<A[l]<<" ";
    }
cout<<"\nValue of limit="<<limit<<"\n";    

if(n-1<4){
 cout<<"Size of Set S is less than 4. So not possible to form a subset of size=4";   
    }
else{
cout<<"Subsets (a,b,c,d) which satisfy a+b+c*d <=limit are:\n";
int sets[4];
subsets(A, size, 4, sets, 0 , 0, limit);
}
return 0;
}
