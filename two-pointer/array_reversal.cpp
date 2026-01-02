/*
Approach : 2-pointer
variables: left , right , temp
data structure: array/vector

steps:
1.take user inputted array size and elements
2.reverse the array:
    -- take a temp variable
    -- swap left anf right using temp
      ---left = 0 , right = size-1
      ---while(left < right)
        ----swap(array[left],array[right]) 
        ---- left++
        ---- right--
    -- return/print reversed array

testcases:
[1,2,3,4] -->> [4,3,2,1]
[17,43,87,2]-->>[2,87,43,17]
*/
// code:
#include <iostream>
using namespace std;
void arr_Reversal(int arr[], int n)
{
    int left = 0, right = n - 1;
    int temp;
    while (left < right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int array[n];
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    arr_Reversal(array, n);
    cout<<"Reversed array\n: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] <<" ";
    }

    return 0;
}