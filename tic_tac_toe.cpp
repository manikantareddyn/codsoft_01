#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cout<<"Enter size to print square: ";
	cin>>n;
	for(int i=0;i<n+1;i++){
		cout<<setw(10);
		if(i!=0)
		cout<<"|";
	for(int j=0;j<n;j++){
		if(i==0)
			cout<<" ";
		cout<<"_";
		if(i!=0)
			cout<<"|";
		}
	cout<<endl;
}
}
