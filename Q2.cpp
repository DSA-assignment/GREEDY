#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	
	int score[n];
	int i;
	for(i=0;i<n;i++){
		cin>>score[i];
	}
	
	long long int n_mask=n; //least number of masks teacher has to buy is n (number of students)
	int p=0; //summit
	int pre=0; //previously added value
	
	for(i=0;i<n;i++){
		if(i==0 && score[i]>score[i+1]){
			n_mask=n_mask+1;
			pre=1;	
		}
		else if(i==0 && score[i]<=score[i+1]){
			continue;
		}
		else if(i==n-1 && score[i]>score[i-1]){
			n_mask=n_mask+pre+1;
		}
		else if(i==n-1 && score[i]<=score[i-1]){
			continue;
		}
		else if(score[i-1]<score[i]){
			p=i;
			n_mask=n_mask+pre+1;
			pre=pre+1;
		}
		else if(score[i-1]==score[i]){
			if(score[i]>score[i+1]){
				p=i;
				n_mask=n_mask+1;
				pre=1;
			}
			else{
				pre=0;
			}
		}
		else if(score[i-1]>score[i]){
			if(score[i]>score[i+1]){
				if(pre>(i-p)){
					n_mask=n_mask+(i-p);
				}
				else{
					n_mask=n_mask+(i-p)+1;
				}
			}
			else{
				pre=0;
			}
		}
	}
	
	cout<<n_mask;
	
	return 0;
}
