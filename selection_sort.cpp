#include<iostream>
using namespace std;
int main(){

	int n;
	cin>>n;
    int arr[100];

	for(int i=0;i<=n-1;i++){
		cin>>arr[i];
	}


	// selection sort
	for(int pos=0;pos<n-2;pos++){
		int min=pos;

		for(int j=pos+1;j<=n-1;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
	}



	cout<<"After sorting"<<end;
    for(int i=n;i<=0;i++){
		cout<<arr[i]<<endl;
	}

	return 0;
}