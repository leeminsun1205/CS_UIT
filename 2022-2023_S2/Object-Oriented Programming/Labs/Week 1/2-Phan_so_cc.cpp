#include <bits/stdc++.h>
using namespace std;
struct Fraction
{
    int numerator;
    int pattern;
};
void inputFractional(Fraction &frac)
{
    cin >>  frac.numerator;
    while(1){
        cin >> frac.pattern;
        if (frac.pattern != 0) break;
    }
}
void outputFractional(Fraction frac)
{
    cout << frac.numerator << "/" << frac.pattern << endl;
}
bool cmp(Fraction a, Fraction b)
{
    return (double)a.numerator/a.pattern < (double)b.numerator/b.pattern;
}
int main()
{
    int n; cin >> n;
    int k; cin >> k;
    Fraction a[100];
    for (int i=0; i<n; i++)
        inputFractional(a[i]);
    sort(a,a+n,cmp);
    for (int i=n-1; i>=0; i--)
        if (n-k==i)
        {
            outputFractional(a[i]);
            break;
        }
    for (int i=0; i<n; i++)
        if (k-1==i) 
        {
            outputFractional(a[i]);
            break;
        }
    return 0;
}