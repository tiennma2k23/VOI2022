#include <bits/stdc++.h>
using namespace std;
const int MINN = 1000, MAXN = 1000, MINM = 1000, MAXM = 1000, MINV = int('a'), MAXV = int('b');
int n, m;

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= 100; iTest++)
    {
        ofstream inp("QPACAT.inp");
        n = MINN + rand() % (MAXN - MINN + 1);
        m = MINM + rand() % (MAXM - MINM + 1);
        inp << n << ' ' << m << endl;
        for (int i = 1; i <= n; i++)
        {
            int len = 1 + rand() % (1 - 1 + 1);
            for (int j = 1; j <= len; j++)
            {
                char ch = char(MINV);
                inp << ch;
            }
            inp << endl;
        }
        // inp << "\n";
        for (int i = 1; i <= m; i++)
        {
            int len = MINN + rand() % (MAXN - MINN + 1);
            for (int j = 1; j <= len; j++)
            {
                char ch = char(MINV + rand() % (MAXV - MINV + 1));
                inp << ch;
            }
            inp << endl;
        }
        // inp << MINV + rand() % (MAXV - MINV + 1) << " " << MINV + rand() % (MAXV - MINV + 1);
        inp.close();
        system("QPACAT.exe");
        system("QPACAT_trau.exe");
        if (system("fc QPACAT.out QPACAT.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
