#include<stdio.h>
#include<stdlib.h>


void main(){
	int T;
	scanf("%d", &T);
	for(int t=1;t<=T;t++){
		int n,res = -1, mid, high, low, key;
		

		scanf("%d %d", &n, &key);
		int array[n];
		printf("%d ------- %d\n",n, key);
		low = 0;
		high = n-1;
		printf("%d ------- %d\n",low, high);
		for(int i = 0; i<n;i++){
			scanf("%d", &array[i]);
		}
		
		while(low<=high){
			mid = (low+high)/2;
			if(array[mid] == key){
				res = 1;
				break;
			}
			else if(array[mid]<key){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		
		
		printf("%d\n", res);
	}
	
}
