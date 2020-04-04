/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <string>
#include <array>
#include <cstdio>
#define BINSIZE 100000
using namespace std;

void count_sort(unsigned long place, unsigned long n, array<long, 5>& A);
void radix_sort(array<long, 5>& B, unsigned long n, unsigned long maxx);

void count_sort(unsigned long place, unsigned long n, array<long, 5>& A)
{
    array<long, 5> output;
    array<long, BINSIZE> count;
    count.fill(0);
    
    unsigned long i;
    for(i=0; i<n; i++)
    {
        count[(A[i]/place)%BINSIZE]++;
    }
    
    for(i=1; i<count.size(); i++)
    {
        count[i]+= count[i-1];
    }
    
    for(i=1; i <= n; i++)
    {
        output[count[(A[n-i]/place)%BINSIZE] - 1] = A[n-i];
        count[(A[n-i]/place)%BINSIZE]--;
    }
    
    for(i=0; i<n; i++)
    {
        A[i] = output[i];
    }
}

void radix_sort(array<long, 5>& B, unsigned long n, unsigned long maxx)
{
    for(unsigned long i=1; maxx/i>0; i*=BINSIZE)
    {
        count_sort(i, n, B);
        for(int j=0; j<n; j++) printf("%ld ", B[j]);
        printf("\n");
    }
}

int main()
{
    array<long, 5> arr;
    unsigned long n;
    unsigned long maxx;
    scanf("%ld", &n);
    
    scanf("%ld", &arr[0]);
    maxx=static_cast<unsigned long>(arr[0]);
    
    for(unsigned long i=1; i<n; i++) 
    {
        scanf("%ld", &arr[i]);
        maxx = max(maxx, static_cast<unsigned long>(arr[i]));
    }
    
    // printf("%ld ", maxx);
    
    radix_sort(arr, n, maxx);
    
    return 0;
}