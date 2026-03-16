#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <utility>
#include <iomanip>


using namespace std;
int main(){
    int i,j,n=0;
    for(i=1;i<1<<14;i++){
        int x;
        int shop=0;
        x=2;
        for(j=0;j<14;j++){
            if(i&1<<j)//0为false，其余非零值均为真
            {x=x*2;
            shop++;}
            else
            x=x-1;
        }
        if(shop==5&&x==1){
            n++;
        }
    }
    cout<<n;
}