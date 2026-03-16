# 枚举
1. 暴力枚举
2. 递归枚举(gcd
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
)
3. 回溯法
4. 二进制枚举
