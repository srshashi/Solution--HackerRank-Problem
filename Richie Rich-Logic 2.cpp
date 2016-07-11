/*
** Hackerrank
** May-world Codesprint 2016: Richie Rich
** Moderate Level
** Logic #2

** Inputs: n k arr
** n :length of array
** k :number of digits that can be changed
** arr : string (array) of digits (original number)
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

// if the number is a palindrome then how can we modify it, given k operations can be done
// modifies the string
void modify_pal(string& arr, int n, int k){
	// if k is even, we can change digit at any palce
	// but if it is odd, n must be odd and only the middle digit will be replaced by '9'
	if(k%2==0){
		for(int i=0;i<n/2;i++){
			if(k<=0)
				break;
			if(arr[i] < '9'){
				arr[i] = arr[n-i-1] = '9';
				k -= 2;
			}
		}
	}
	else if(n%2 == 1 && k > 0)
		arr[n/2] = '9';
}

// if a number is NOT a palindrome, make it a palindrome
// comparing first and last digits, if the first and last digit are not same
// replace the smaller digit with bigger digit and decrement k by 1
void make_pal(string& arr, int n, int k)
{
	for(int i=0;i<n/2;i++)
	{
		if(arr[i] == arr[n-i-1])
			continue;
		else if(arr[i] < arr[n-i-1])
			arr[i] = arr[n-i-1];
		else
			arr[n-i-1] = arr[i];
		k--;
	}
}

// same as make_pal, but
// it is invoked only when k is more than minimum count
void make_big_pal(string& arr, int n, int k, int count)
{
	int posi = 0, pose = n-1;
	while(posi<pose && k>count)
	{
		if(arr[posi] != arr[pose])
		{
			if(arr[posi] == '9')
				arr[pose] = '9';
			else if(arr[pose] == '9')
				arr[posi] = '9';
			else
			{
				arr[posi] = arr[pose] = '9';
				k--;
			}
			k--;
			count--;
		}
		else if(arr[posi] != '9')
		{
			arr[posi] = arr[pose] = '9';
			k-=2;
		}
		posi++;
		pose--;
	}
	if(k>=count and count!= 0)
		make_pal(arr, n, k);
	else modify_pal(arr, n, k);
}

// check if a number can be converted to a palindrome or not, or if it is already one
// if conversion is not possible, i.e., if count > k, it prints -1
void possible_pal(string& arr, int n, int k)
{
	int flag = 0;
	// count number of (pairs) differences to be a palindrome
	int count = 0;
	// for odd n, we don't need to check the middle digit
	for(int i=0; i<n/2; i++)
		if(arr[i] != arr[n-i-1])
		{
			count++;
			// not a palindrome
			flag = 1;
		}
	// the number is a palindrome
	if(flag == 0)
	{
		modify_pal(arr, n, k);
		cout<<arr;
	}
	// the number is not a palindrome, but can be converted to it
	else if(count == k)
	{
		make_pal(arr, n, k);
		cout<<arr;
	}
	else if(count < k)
	{
		make_big_pal(arr, n, k, count);
		cout<<arr;
	}
	// not possible
	else
		cout<<-1;
}

int main()
{
	int n, k;
	string arr;
	
	cin>>n>>k;
	cin>>arr;
	
	possible_pal(arr, n, k);
	//cout<<arr;
	return 0;
}
