
// You are given an array/list 'ARR' of integers of length ‘N’. You are supposed to find all the elements that occur strictly more than floor(N/3) times in the given array/list.


// Sample Input 1 :
// 7 (size of array)
// 3 2 2 1 5 2 3
// 5
// 7 4 4 9 7
// Sample Output 1:
// 2
// 4 7
// Explanation Of Sample Input 1:
// In the first test case, floor(N/3) = floor(7/3) is equal to 2, and 2 occurs 3 times which is strictly more than N/3. No other element occurs more than 2 times.

// In the second test case, floor(N/3) = floor(5/3) is equal to 1, and 4 and 7 both occur 2 times. No other element occurs more than once.
#include<math.h>
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
	int count1=0;
    int count2=0;
    
    int element1=-1;
    int element2=-1;
    
    for(int i=0;i<arr.size();i++){
        if(element1==arr[i]){
            count1++;
        }
        else if(element2==arr[i]){
            count2++;
        }
        else if(count1==0){
            element1=arr[i];
            count1=1;
        }
        else if(count2==0){
            element2=arr[i];
            count2=1;
        }
		else{
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]==element1){
            count1++;
        }
        else if(element2==arr[i]){
            count2++;
        }
    }
    vector<int> result;
    int n = arr.size();
    if(element1!=-1 && count1>floor((double)(n/3))){
        result.push_back(element1);
    }
    if(element2!=-1 && count2>floor((double)(n/3))){
        result.push_back(element2);
    }
    return result;
}
