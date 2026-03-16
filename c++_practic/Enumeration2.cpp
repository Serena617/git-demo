#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j;
    int n,x,m,minsum=0; //变量名 min 可能与标准库中的 std::min 冲突（尤其包含了 <bits/stdc++.h> 时）。建议改为 minSum 或 totalSum。
    cin>>n>>m;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        minsum=minsum+a[i];
    }
    for(i=1;i<1<<n;i++){
        for(j=0,x=0;j<n;j++){
            if(i&(1<<j)){
                x=x+a[j];
            }
             }
             if(x==m){
            minsum=x;
            break;
        }        
             else if(x>m&&x<minsum){        //代码中 else(x>m&&x<min) 是非法的，else 后不能直接跟条件。应该改为 else if(x>m&&x<minsum)，这样才能正确地判断条件并更新 minsum 的值。
                minsum=x;
             }
    }
    cout<<minsum<<endl;
    return 0;

}