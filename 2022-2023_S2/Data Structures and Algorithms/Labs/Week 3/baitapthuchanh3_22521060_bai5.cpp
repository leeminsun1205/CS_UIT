#include <bits/stdc++.h>
using namespace std;
int chuyenSangHe10(stack<string> st, int A)
{
    int he_10=0,i=0;
    while (!st.empty())
    {
        int number;
        if (st.top()=="0") number=0;
        else if (st.top()=="1") number=1;
        else if (st.top()=="2") number=2;
        else if (st.top()=="3") number=3;
        else if (st.top()=="4") number=4;
        else if (st.top()=="5") number=5;
        else if (st.top()=="6") number=6;
        else if (st.top()=="7") number=7;
        else if (st.top()=="8") number=8;
        else if (st.top()=="9") number=9;
        else if (st.top()=="A") number=10;
        else if (st.top()=="B") number=11;
        else if (st.top()=="C") number=12;
        else if (st.top()=="D") number=13;
        else if (st.top()=="E") number=14;
        else if (st.top()=="F") number=15;
        he_10+=number*pow(A,i);
        i++;
        st.pop();
    }
    return he_10;
}
string chuyenSangHeB(int he_10, int B)
{
    stack<int> st;
    while (he_10!=0)
    {
        st.push(he_10%B);
        he_10/=B;
    }
    string he_B="";
    int i=0;
    while (!st.empty())
    {
        string number;
        if (st.top()==0) number="0";
        else if (st.top()==1) number="1";
        else if (st.top()==2) number="2";
        else if (st.top()==3) number="3";
        else if (st.top()==4) number="4";
        else if (st.top()==5) number="5";
        else if (st.top()==6) number="6";
        else if (st.top()==7) number="7";
        else if (st.top()==8) number="8";
        else if (st.top()==9) number="9";
        else if (st.top()==10) number="A";
        else if (st.top()==11) number="B";
        else if (st.top()==12) number="C";
        else if (st.top()==13) number="D";
        else if (st.top()==14) number="E";
        else if (st.top()==15) number="F";
        he_B+=number;
        st.pop();
        i++;
    }
    return he_B;
}
int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        stack<string> st;
        string N, number;
        cin >> N;
        int A, B;
        cin >> A >> B;
        for (int i=0; i<N.length(); i++)
        {
            number=N[i];
            st.push(number);
        }
        int he_10=chuyenSangHe10(st, A);
        if (B==10)
            cout << he_10;
        else 
            cout << chuyenSangHeB(he_10,B);
    }
    return 0;
}