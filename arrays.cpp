/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int getLargest(int a[], int n)
{
    int max = 0;
    for(int i=1;i<n;i++)
    {
        if(a[max] < a[i])
        {
            max = i;
        }
    }
    
    return max;
}

int getSecondLargest(int a[], int n)
{
    int fistMax = getLargest(a,n);
    int max = 0;
    
    for(int i=1;i<n;i++)
    {
        if(i != fistMax && a[max] < a[i] )
        {
            max = i;
        }
    }
    return max;
}

int getLargestSingleIter(int a[], int n)
{
    int largest = 0;
    int secondLargest = -1;
    
    for(int i=1;i<n;i++)
    {
        if(a[largest] < a[i])
        {
            secondLargest = largest;
            largest = i;
        }
        else if(a[largest] > a[i])
        {
            if(secondLargest == -1 || a[secondLargest] < a[i] )
            {
                secondLargest = i;
            }
        }
    }
    return secondLargest;
}


bool isSorted(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        if(a[i] < a[i-1])
            return false;
    }
    return true;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(int a[], int n)
{
    int i = 0;
    int j = n-1;
    while(i<=j)
    {
        swap(a[i++],a[j--]);
    }
}

void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
    cout<<endl;
}

void removeDuplicates(int a[], int &n)
{
    int i=0;
    int j=1;
    while(j<n)
    {
        if(a[i] != a[j]) 
        {
            i++; 
            j++;
        }
        else
        {
            while(a[i] == a[j])
                j++;
            a[i+1] = a[j];
            i++;
            
        }
    }
    n = i;
}

void efficentDupRemoval(int a[], int &n)
{
    int i=1;
    for(int j=1;j<n;j++)
    {
        if(a[i-1] != a[j])
        {
            a[i] = a[j];
            i++;
        }
    }
    
    n = i;
    
    
}
int main()
{
    //cout<<"Hello World";
    int a[] = {10,90,90,5,120,8,40};
    int n = sizeof(a)/sizeof(int);
    int indx = getLargest(a,n);
    cout<<"Largest is : "<<a[indx]<<endl;
    int idx = getSecondLargest(a,n);
    cout<<"Second Largest : "<<a[idx]<<endl;
    
    int idx1 = getLargestSingleIter(a,n);
    cout<<"Second Largest in one iteration : "<<a[idx1]<<endl;
    
    bool flag = isSorted(a,n);
    cout<<"Array is "<<(flag?"sorted":"not sorted")<<endl;
    int b[] = {2,3,4,5,20,30,30,40};
    n = sizeof(b)/sizeof(int);
    flag = isSorted(b,n);
    cout<<"Array is "<<(flag?"sorted":"not sorted")<<endl;
    
    int d[] = {1,2,3,4,5,6};
    n = sizeof(d)/sizeof(int);
    cout<<"original Array ";
    printArray(d,n);
    reverseArray(d,n);
    cout<<"Array after reversing ";
    printArray(d,n);
    
    
    int dublicateArray[] = {1,2,3,3,3,3,4,4,4,5,6,7,7,8};
    n = sizeof(dublicateArray)/sizeof(int);
    cout<<"dublicateArray : ";
    printArray(dublicateArray,n);
    removeDuplicates(dublicateArray,n);
    cout<<"after removing duplicates : ";
    printArray(dublicateArray,n);
    
    int c[] = {1,2,3,3,3,3,4,4,4,5,6,7,7,8};
    n = sizeof(c)/sizeof(int);
    cout<<"dublicateArray : ";
    printArray(c,n);
    efficentDupRemoval(c,n);
    cout<<"after removing duplicates (efficient way) : ";
    printArray(c,n);
    
    
    return 0;
}
