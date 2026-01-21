#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string baseword;
    cin >> baseword;
    N--;
    int base[26] = {0, };

    for (int i = 0; i < baseword.size(); i++) {
        base[baseword[i] - 'A']++;
    }

    int answer = 0; 

    while (N--) {
        string compare_word;
        cin >> compare_word;

        int cnt[26] = {0, };
        for (int i = 0; i < compare_word.size(); i++) {
            cnt[compare_word[i] - 'A']++;
        }

        int len_diff = abs((int)baseword.size() - (int)compare_word.size());
        int diff = 0; 
        for (int i = 0; i < 26; i++) {
            diff += abs(base[i] - cnt[i]);
        }

        if ((len_diff == 0 && diff == 0) || (len_diff == 1 && diff == 1) || (len_diff == 0 && diff == 2)) { 
            answer++;
        }
    }

    cout << answer << '\n';
    
    return 0; 
}
