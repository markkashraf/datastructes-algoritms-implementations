#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653
#define fori(a) for (long long i = 0; i < a; i++)
#define forj(a) for (long long j = 0; j < a; j++)
#define fork(a) for (long long k = 0; k < a; k++)
#define arrLength(a) sizeof(a) / sizeof(a[0])
#define sout(a) cout << a << '\n';
#define ssout(a, b) cout << a << b << '\n';
#define swap(a, b)   \
    {                \
        int lol = a; \
        a = b;       \
        b = lol;     \
    }
#define sum(a) a *((a) + 1) / 2
void gg()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int binarySearch(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == element)
            return mid;
        else if (element < arr[mid])
        {
            end = mid - 1;
        }
        else if (element > arr[mid])
        {
            start = mid + 1;
        }
    }
    return -1;
}
int recursiveBinarySearch(int arr[], int start, int end, int element)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;

    if (arr[mid] == element)
    {
        return mid;
    }
    else if (element < arr[mid])
    {
        return recursiveBinarySearch(arr, start, mid - 1, element);
    }
    else
    {
        return recursiveBinarySearch(arr, mid + 1, end, element);
    }
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start, j = end;

    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    return i;
}
void quickSort(int arr[], int start, int end)

{
    if (start >= end)
    {
        return;
    }
    else
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, pIndex + 1, end);
        quickSort(arr, start, pIndex - 1);
    }
}
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        return n * factorial(n - 1);
    }
}
bool isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int gcd(int a, int b)

{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll sumOfDigits(ll x)
{
    ll sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}
void printArry(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << '\n';
}
int sumArry(int arr[], int n)
{
    int sum = 0;
    fori(n) sum += arr[i];
    return sum;
}
class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class MyLinkedList
{
public:
    node *head;
  
    int size;
    MyLinkedList()
    {
        head = NULL;
        size = 0;
    }
    int get(int index)
    {
        if (index >= size || index < 0)
            return -1;
        node *itr = head;
        for (int i = 0; i < index; i++)
        {
            itr = itr->next;
        }

        return itr->data;
    }
    void addAtHead(int val)
    {
        if (head == NULL)
        {
            head = new node(val);
        }
        else
        {
            node *newNode = new node(val);
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void addAtTail(int val)
    {

        if (head != NULL)
        {
            node *itr = head;
            for (int i = 0; i < size - 1; i++)
            {
                itr = itr->next;
            }
            node *newNode = new node(val);
            itr->next = newNode;
            size++;
        }
        else 
        {
            addAtHead(val);
        }
       
    }
    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
        {
            return;
        }
        else if (index == size)
        {
            addAtTail(val);
            return;
        }
        else if (index == 0)
        {
            addAtHead(val);
            return;
        }

        else
        {
            node *itr = head;
            node *beforeItr = NULL;
            for (int i = 0; i < index; i++)
            {
                beforeItr = itr;
                itr = itr->next;
            }
            node *newNode = new node(val);
            newNode->next = itr;
            beforeItr->next = newNode;
            size++;
        }
    }
    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)// You had a mistake here >=
        {
            return;
        } 

        node *itr = head;
        node *beforeItr = NULL;

        if (index == 0 && head!=NULL)
        {
            itr = head;
            head = head->next;
            delete itr;
            size--;
        }
        else
        {
            itr = head;
            beforeItr = NULL;
            for (int i = 0; i < index; i++)
            {
                beforeItr = itr;
                itr = itr->next;
            }
            beforeItr->next = itr->next;
            delete itr;
            size--;
        }
    }
    void print()
    {
        node *itr = head;
        while (itr != NULL)
        {
            cout << itr->data << "->";
            itr = itr->next;
        }
        cout << '\n';
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    int length()
    {
        return size;
    }

    ~MyLinkedList()
    {
        node *itr = head, *old;
        while (itr != NULL)
        {
            old = itr;
            itr = itr->next;
            delete old;
        }
    }
};

int main()
{
    gg();
    sout("hhh");
    sout("TESTING CONFLICTS");
    //hhlololol
    //asfasf
}
