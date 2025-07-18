//brute force approach 
// merge two array simply and then find the median ,if it is odd simply arr[n/2] is the element and if it is even (arr[n/2]+arr[n/2-1])/2


//better approach 
// in this we don't merge array we use pointer and find the n/2 and n/2 -1 element and return the element according to total element i.e odd or even
// both approach are disscused in notes and striver course

//optimal approach

#include<bits/stdc++.h>
double median(vector<int>& a, vector<int>& b) {
	int n1=a.size();
	int n2=b.size();
	if(n1>n2)	return median(b, a);
	int low=0, high=n1; //taking lenght of lowest array size
	int left=(n1+n2+1)/2;
	int n=n1+n2;

	while(low<=high){
		int mid1=(low+high)>>1;
		int mid2=left-mid1;
		int l1=INT_MIN,l2=INT_MIN;
		int r1=INT_MAX,r2=INT_MAX;
		if(mid1<n1)	r1=a[mid1];
		if(mid2<n2)	r2=b[mid2];
		if(mid1-1>=0)	l1=a[mid1-1];
		if(mid2-1>=0)	l2=b[mid2-1];
		if(l1<=r2 && l2<=r1){
			if(n%2==1)	return max(l1,l2);
			return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
		}
		else if(l1>r2) high=mid1-1;
		else low=mid1+1;	
	}
	return 0;

}

int main(){
    
}