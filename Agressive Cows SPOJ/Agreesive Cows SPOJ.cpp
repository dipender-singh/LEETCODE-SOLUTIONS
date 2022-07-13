/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

Farmer John can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/
#include <bits/stdc++.h>
using namespace std;

bool ispossible(int n , int cows, int post[],int mid){
	int c=1;
	int pehli_cow_ki_location = post[0]; // this will be updated jab mai ek cow ko uske stall mein daal dunga agar 2 cows ke beech mein minimum possible distance ho sakta hai toh uske baad isme jayega us stall ka index jahan humne apni last cow ko rakha hai  
	for(int i = 1 ; i < n ; i++){
		if( (post[i]-pehli_cow_ki_location) >= mid){
			c++;
			pehli_cow_ki_location = post[i];
		}
	}
	if(c>=cows){
		return true;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,cows;
	    cin>>n>>cows;
	    int post[n];
		for(int i = 0 ; i < n  ; i++){
			cin>>post[i];
		}
		sort(post,post+n);
		int low = 1;//minimun distance joki kisi 2 cows ke beech ho sakta hai
		int high = post[n-1]-post[0];//maximum distance jo kisi 2 cows ke beech ho sakta hai
		                             //wo obviously aise calculate hoga ki ek cow ko sabse pehle stall pe khada kara do
		                             //or doosri cow ko sabse last wale stall pe
		while(low<=high){ // binary search ki jo line hogi woh represent karegi minimum possible distance b/w 2 cows matlab ki joh mid calculate hoga kisi bhi 2 cows ke beech mein itna distnace toh hona hi chahiye
			int mid = low+(high-low)/2;
			if(ispossible(n,cows,post,mid)){ // is se hum ye pata laga lenge ki haan 'mid' distance woh distance hai joki 2 cows ke beech mein reh sakta hai or iske jitne gaap pe humari sari cows khadi ho sakti hain  
				low=mid+1;//hum is minimum possible distance ko maximize karenge
			}
			else{
				high=mid-1;//saari cows nahi a pa rhi, jab mid jitna gap har cow ke beech mein hoga toh matlab less cow khadi ho payengi isliye mujhe is gap ko kam karna hoga taaki jada cows khadi ho sakein 
			}
		}
		cout<<high<<endl;
	}
	return 0;
}
