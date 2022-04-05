#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;
#define d 256
class define {
private:
    int b;
public:
    static int a;
    define() {
        a++;
        b = a;
        cout << b << endl;
    }
    void mana(define b) {
        cout << "toi la con vit bau" << endl;
    }
    ~define() {
        cout << "delete" << b << endl;
    }

};
int define::a = 0;
void search(string pat, string txt, int q)
{
    int M = pat.length();
    int N = txt.length();
    int p = 0;
    int t = 0;
    int h = 1;
    int j, i;
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
                if (flag)
                {
                    cout << i << " ";
                }

            }
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}
int mainte15()
{
    define a, b, c;
    a.mana(b);
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101;
    search(pat, txt, q);
    return 0;
}