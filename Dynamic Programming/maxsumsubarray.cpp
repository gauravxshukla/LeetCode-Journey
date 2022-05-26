//Kadane's Algo

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a={2, -4, 3, -1, 2};
    int local_max = 0,n=a.size();
    int global_max = INT_MIN;
    
    for(int i = 0; i < n;i++){   
	    local_max = max(a[i], a[i] + local_max);
	    if(local_max > global_max){
	        global_max = local_max; 
	    }
	}
	cout<<global_max;
	return 0;
}
