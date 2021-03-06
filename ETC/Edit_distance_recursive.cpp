#include<iostream>
#include<cstdio>
#include<string>
#include<stdio.h>

using namespace std;

int editDist(string str1, string str2, int m, int n);

int main(){
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1,str2,str1.length(),str2.length());
    return 0;
}

int editDist(string str1, string str2, int m, int n){
    if(m==0) return n;
    if(n==0) return m;
    if(str1[m-1]==str2[n-1])
        return editDist(str1,str2,m-1,n-1);
    
    return (1 + min ( min(editDist(str1,str2,m,n-1),       //Insert
                     editDist(str1,str2,m-1,n)),       //Remove
                     editDist(str1,str2,m-1,n-1)      //Replace
                   ));     
}