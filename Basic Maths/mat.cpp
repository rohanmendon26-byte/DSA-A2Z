//count the digits
int countDigits(int n){
	// Write your code here.
	int count=0;
	while(n>0){
		count+=1;
		n=n/10;
	}
	return count;
}
//******************************************

//Reverse of a number
#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
	cin>>n;
	int rev=0;
	while(n>0){
		int lastdigit=n%10;
		rev=(rev*10)+lastdigit;
		n=n/10;
	}
}
//******************************************

//Reverse of a number using leetcode
class Solution {
public:
    long rev=0;
    int reverse(int x) {
        while(x!=0){
        int ld = x % 10;
         if (rev > INT_MAX/10 || (rev == INT_MAX/10 && ld > 7))
                return 0;

        if (rev < INT_MIN/10 || (rev == INT_MIN/10 && ld < -8))
                return 0;

        rev=(rev * 10)+ld;
        x=x/10; 
        }
    return rev;
    }
};

//******************************************

//pallindrome
bool palindrome(int n)
{
    // Write your code here
	int dup=n;
	int rev=0;
	while(n>0){
		int lastdigit=n%10;
		rev=(rev*10)+lastdigit;
		n=n/10;
	}
    return dup==rev;
}

//******************************************
 //Armstrong number
 #include <bits/stdc++.h> 
bool isArmstrong(int num) {
    // Write your code here
   int dup = num;
    int sum = 0;
    // Count number of digits
    int digits = 0;
    int temp = num;
    while(temp > 0){
        digits++;
        temp /= 10;
    }
    // Calculate Armstrong sum
    while(num > 0){
        int ld = num % 10;
        sum += pow(ld, digits);
        num /= 10;
    }
    return sum == dup;
}
//******************************************

//print all divisors using brute force
#include <bits/stdc++.h>
using namespace std;

int* printDivisors(int n, int &size){
    
    // First count divisors
    size = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            size++;
        }
    }
    // Allocate memory
    int* arr = new int[size];

    // Store divisors
    int index = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            arr[index++] = i;
        }
    }
    return arr;
}
//******************************************


//print all divisors using STL in c++
int* printDivisors(int n, int &size){
    vector<int> v;

    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            if(i != n / i){
                v.push_back(n / i);
            }
        }
    }

    sort(v.begin(), v.end());

    size = v.size();
    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        arr[i] = v[i];
    }

    return arr;
}
//******************************************

//Prime number
int main() {
	// Write your code here
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			cnt++;
			if((n/i)!=i)
			   cnt++;
		}	
	}
	if(cnt==2){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
}

//******************************************

//GCD
int main() {
	// Write your code here
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			cnt++;
			if((n/i)!=i)
			   cnt++;
		}	
	}
	if(cnt==2){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
}



