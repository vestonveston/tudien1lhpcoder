#include <bits/stdc++.h>

using namespace std;
string cong(string a, string b)
{
    while(a.size() < b.size())a = '0' + a;
    while(a.size() > b.size())b = '0' + b;
    int nho = 0;
    string kq = "";
    for(int i = a.size() - 1; i >= 0; i--)
    {
        int so = a[i] + b[i] -96 + nho;
        kq = char(so%10 + 48) + kq;
        nho = so/10;
    }
    if(nho == 1)kq= '1' + kq;
    return kq;
}
string tru(string a, string b)
{
    while(a.size() > b.size())b = '0' + b;
    int nho = 0;
    string kq = "";
    for(int i = a.size() - 1; i >= 0; i--)
    {
        int so = a[i] - b[i] - nho;
        if(so < 0)
        {
            so += 10;
            nho = 1;
        }
        else nho = 0;
        kq = char(so%10 +48) + kq;
    }
    while(kq[0] == '0' && kq.size() > 1)kq.erase(0, 1);
    return kq;
}
bool ss(string a, string b)
{
    while(a.size() < b.size())a = '0' + a;
    while(a.size() > b.size())b = '0' + b;
    return a > b;
}
int t, n, k;
string m;
string pascal[355][355];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pascal[0][0] = "1";
    for(int i = 1 ; i <= 350; i++)
    {
        pascal[i][0] = "1";
        pascal[i][i] = "1";
        for(int j = 1; j < i; j++)
        {
            pascal[i][j] = cong(pascal[i-1][j], pascal[i-1][j-1]);
            //cout << pascal[i][j] << ' ';
        }
        //cout << '\n';
    }
    cin >> t;
    for(int o = 1; o <= t; o++)
    {
        cin >> n >> k >> m;
        if(ss(m, pascal[n][k])){
            cout << -1 <<'\n';
            continue;
        }
        string kq = "";
        int so0 = n - k, so1 = k;
        while(n > 0)
        {
            //cout << m << '\n';
            if(ss(m, pascal[n - 1][so1]))
            {
                m = tru(m, pascal[n - 1][so1]);
                kq += '1';
                so1--;
            }
            else kq += '0';
            n--;
        }

        cout << kq;
        cout << '\n';
    }
    return 0;
}