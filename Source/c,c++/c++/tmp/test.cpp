#include <iostream>
#include <vector>
using namespace std;


int main(void){

	int &&a=5;
	int b=0;
	a=b;
	cout<<a<<endl;
}
