#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
void createLPS(string pat, int M,vector<int>& lps);
void KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    vector<int>lps(M);
    createLPS(pat, M, lps);
    int i = 0;
    int j = 0; 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
void createLPS(string pat, int M, vector<int>& lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int mainte14()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABDCABDCD";
    KMPSearch(pat, txt);
    return 0;
}