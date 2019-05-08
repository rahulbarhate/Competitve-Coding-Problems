int main()
{
    int a[] = {10, 15, 3, 7} 
    int k = 17;
    int size = sizeof(a) / sizeof(a[0]);

    if (getResult(a[], k, n))
        cout<<"Success";
    else
        cout<<"Try using some other array values!";
}

bool getResult(int a[], int k, int n)
{

    int l,r;
    
    sort(a, a+n);
    l=0; r=n-1;
    while(l<r)
    {
        if(a[l]+a[r] == k)
            return 1;
        else if(a[l]+a[r]<k)
            l++;
        else
            r--;
    }
    return 0;

}