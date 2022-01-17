#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MN = 1000111;

char s[MN], t[MN];
int nxt[MN];

int main()
{
    scanf("%s\n", &t[1]);
    scanf("%s\n", &s[1]);

    int j;
    j = nxt[1] = 0;
    for (int i = 2; s[i]; ++i)
    {
        while (j > 0 && s[j + 1] != s[i])
            j = nxt[j];
        if (s[j + 1] == s[i])
            ++j;
        nxt[i] = j;
    }

    j = 0;
    for (int i = 1; t[i]; ++i)
    {
        while (j > 0 && s[j + 1] != t[i])
            j = nxt[j];
        if (s[j + 1] == t[i])
            ++j;

        if (s[j + 1] == 0)
        { // Het xau s
            printf("%d ", i - j + 1);
            j = nxt[j];
        }
    }
    puts("");
    return 0;
}