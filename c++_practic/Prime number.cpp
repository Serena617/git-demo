#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int number=1;
        n=round(pow(10,n))/log(pow(10,n));
        int r=n/10;
        while(r){
            r=r/10;
            number++;
        }
        cout<<number<<endl;
    }
    return 0;
}