#include <stdio.h>

int main(){
	
	int n,i,j,k,temp,arr[1000],count=0;
	
	scanf("%d",&n);		//no of shipping products
	
	
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);  //the weight sequence of products
	}
	
	printf("\n");
	for(i=0;i<n;i++){			// sort the weight sequence of products
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}	
		}
	}
	
	for(i=0;i<n;i++){
		 k=arr[i]+4;
	
		while(arr[i]<=k){
			i++;
	}
	i=i-1;
	count ++;
	
	}
	printf("%d",count);  //no of containers

	return 0;
}


