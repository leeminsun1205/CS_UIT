#include <bits/stdc++.h>
using namespace std;
struct Fraction
{
    int numerator, pattern;
};
void inputFractional(Fraction &frac)
{
    cin >>  frac.numerator;
    while(1){
        cin >> frac.pattern;
        if (frac.pattern != 0) break;
    }
}
double findMin(Fraction a[], int n)
{
    double min=(double) a[0].numerator/a[0].pattern;
    for (int i=1; i<n; i++)
        if ((double) a[i].numerator/a[i].pattern < min) min=(double) a[i].numerator/a[i].pattern;
    return min;
}
double findMax(Fraction a[], int n)
{
    double max=(double) a[0].numerator/a[0].pattern;
    for (int i=1; i<n; i++)
        if ((double) a[i].numerator/a[i].pattern > max) max=(double) a[i].numerator/a[i].pattern;
    return max;
}
void outputFractional(Fraction frac)
{
    cout << frac.numerator << "/" << frac.pattern << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n; 
    cin >> n;
    Fraction a[100];
    for (int i=0; i<n; i++)
        inputFractional(a[i]);
    for (int i=0; i<n; i++)
        if ((double) a[i].numerator/a[i].pattern == findMin(a,n))
            {
                outputFractional(a[i]);
                break;
            }
    for (int i=0; i<n; i++)
        if ((double) a[i].numerator/a[i].pattern == findMax(a,n))
           { outputFractional(a[i]);
                break;
            }
    return 0;
}