#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string toLowerCase(string s) {
    for (char& c : s) {
        c = tolower(c);
    }
    return s;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if (cacheSize == 0) return cities.size() * 5;

    for (string city : cities) {
        city = toLowerCase(city);

        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end()) {
            // cache hit
            answer += 1;
            cache.erase(it);
            cache.push_back(city);
        } else {
            // cache miss
            answer += 5;
            if (cache.size() == cacheSize) {
                cache.erase(cache.begin());
            }
            cache.push_back(city);
        }
    }

    return answer;
}
