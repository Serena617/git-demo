#include <iostream>
#include <vector>
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	vector<int>v;
	for(int n=0;n<5;++n){
		v.push_back(n);}
		vector<int>::iterator i;
        i=v.begin();
        i+=2;
        cout<<*i<<endl;//i就相当于一个光标，指针，只能指着一个元素，现在不输出，光标的位置就又被定义到开始了
	for(i=v.begin();i!=v.end();++i){
		cout<<*i<<" ";}
        
		cout<<endl;
		for(vector<int>::reverse_iterator j=v.rbegin();j!=v.rend();++j){
			cout<<*j<<" ";
		}
	return 0;
}