#include <iostream>
#include <string> 
using namespace std;

 int f(int i,int k)
 {
 	int sum=0;
 	if(k==1)
	{	 
 	    return 1;
	}
		  	else{
 		for(int j=i+1;j<=26;j++)
		 {
 			sum+=f(j,k-1);
		 }
		return sum;
	 }
 } 
    int g(int k); 
 	int sum=0;
 	for(int i=1;i<=26;i++)
	 {
 		sum+=f(i,k);
	 }
	 return sum;
    int calulate(string s)
	{
 	int sum=0;
 	int k=s.length();
 	for(int i=1;i<k;i++)
	 { 
 		sum+=g(i); 
	 }	
	 int h=s[0]-'a'+1; 	 
	 for(int i=1;i<h;i++)
	 {
	 sum+=f(i,k); 
	 }	  
	 for(int i=1,temp=h;i<k;i++)
	 { 
 	    int n=s[i]-'a'+1;
	 	int length=k-i;
		 for(int j=temp+1;j<n;j++)
		 { 
		 	sum+=f(j,length);
		 	temp=n;
		 } 
	 } 
	  return sum+1;
 }
int main(int argc, char** argv) 
{
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{ 
    cin>>s;  
    cout<<calulate(s);  	
	}
	return 0;
}

