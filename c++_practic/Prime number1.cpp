#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 10000000
typedef long long LL;
bool b[MAX+1];
long long su[MAX+1];
int cnt=0;
void init(){
    long long i,j;
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(i=2;i*i<=MAX;i++){
        if(b[i]){
            su[cnt++]=i;
            }
            for(j=1;j<cnt&&su[j]*i<=MAX;j++){
                b[su[j]*i]=0;
                if(i%su[j]==0)
                    break;
            }
        }
    }
    int isprime(LL n){
        if(n<2)
            return 0;
        int i;
        for(i=0;su[i]<sqrt(n);i++){
            if(n%su[i]==0)
                return 0;
        }
        return 1;
    }
int main(){
    LL x,y,z;
    int i,n;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x>>y>>z;
        if(isprime(x+y-z)){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
        }
    return 0;
    }