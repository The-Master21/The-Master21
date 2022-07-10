#include<fstream.h> 
#include<iostream.h> 
#include<stdio.h> 
#include<string.h> 
#include<process.h> 
void write_file() 
{ 
 char name[20][20],temp[20]; 
 fstream f1("file1.txt",ios::out); 
 fstream f2("file2.txt",ios::out); 
 int i,j,m,n; 
 if((!f1)||(!f2)) 
 { 
 cout<<"Unable to open the files!!\n"; 
 exit(0); 
 } 
 cout<<"Enter the number of records in file 1: "; 
 cin>>m; 
 cout<<"Enter the names:\n"; 
 for(i=0;i<m;i++) 
 cin>>name[i]; 
 for(i=0;i<m-1;i++) 
 { 
 for(j=0;j<m-i-1;j++) 
 { 
 if(strcmp(name[j],name[j+1])>0) 
 { 
 strcpy(temp,name[j]); 
 strcpy(name[j],name[j+1]); 
 strcpy(name[j+1],temp); 
 } 
 } 
 } 
 for(i=0;i<m;i++) 
 f1<<name[i]<<endl; 
 cout<<"Enter the number of records in file 2: "; 
 cin>>n; 
 cout<<"Enter the names:\n"; 
 for(i=0;i<n;i++) 
 cin>>name[i]; 
 for(i=0;i<n-1;i++) 
 { 
 for(j=0;j<n-i-1;j++) 
 { 
 if(strcmp(name[j],name[j+1])>0) 
 { 
 strcpy(temp,name[j]); 
 strcpy(name[j],name[j+1]); 
 strcpy(name[j+1],temp); 
 } 
 } 
 } 
 for(i=0;i<n;i++) 
 f2<<name[i]<<endl; 
 f1.close(); 
 f2.close(); 
}  
void main() 
{ 
 fstream f1("file1.txt",ios::in); 
 fstream f2("file2.txt",ios::in); 
 fstream f3("output.txt",ios::out); 
 char l1[100][20],l2[100][20],l3[100][20]; 
 int i=0,j=0,k=0,m=0,n=0; 
 write_file(); 
 if((!f1)||(!f2)||(!f3)) 
 { 
 cout<<"Unable to open the files!!\n"; 
 exit(0); 
 } 
 cout<<"Contents of file 1 are:\n"; 
 while(!f1.eof()) 
 { 
 f1.getline(l1[i],20,'\n'); 
 cout<<l1[i++]<<endl; 
 m++; 
 } 
 cout<<"Contents of file 2 are:\n"; 
 while(!f2.eof()) 
 { 
 f2.getline(l2[j],20,'\n'); 
 cout<<l2[j++]<<endl; 
 n++; 
 } 
 m--; 
 n--; 
 i=0,j=0; 
 while(i<m&&j<n) 
 { 
 if(strcmp(l1[i],l2[j])==0) 
 { 
 strcpy(l3[k],l1[i]); 
 f3<<l3[k]<<endl; 
 i++; 
 j++; 
 k++; 
 } 
 else if(strcmp(l1[i],l2[j])<0) 
 i++; 
 else 
 j++; 
 } 
 if(k==0) 
 cout<<"No common names!!\n"; 
 else 
 { 
 cout<<"The names that are common are:\n"; 
 for(i=0;i<k;i++) 
 cout<<l3[i]<<endl; 
 } 
} 
