/*
    author    : MishkatIT
    created   : Thursday 2022-11-17-12.03.06
    problem   : Finding the Kth Prime
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 900000000
using namespace std;
bool prime[MAX + 1];
vector<long long > v;
void sieve()
{
    for (long long  i = 2; i * i <= MAX; i++)
    {
        if(prime[i] == false)
        {
            for (long long  j = i * i; j <= MAX; j += i)
                prime[j] = true;
        }
    }
    for (long long  i = 2; i <= MAX; i++)
    {
        if(prime[i] == false)
            v.push_back(i);
    }


}

int main()
{
    fio;
    sieve();
    long long  t = 1;
//    cin >> t;
    while(t--)
    {
        long long  num;
        cin >> num;
          cout << v[num - 1] << '\n';

    }

    return 0;
}



