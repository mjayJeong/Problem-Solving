#include <iostream>
#include <stack>

using namespace std;

stack<int> s[8];


int main(){
    int n, p;
    cin >> n >> p;
    
    int a,b;
    int ans = 0;

    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if(s[a].empty()) { 
            s[a].push(b); 
            ans++; 
        } else if(s[a].top() < b) { 
            s[a].push(b); 
            ans++; 
        } else if(s[a].top() > b) { 

            while(s[a].top()>b) {
                s[a].pop(); 
                ans++; 
                if(s[a].empty()) { 
                    s[a].push(b); 
                    ans++; 
                }
            }
            if(s[a].top() < b) { 
                s[a].push(b);
                ans++; 
            } 
        }
    }
    cout << ans;

    return 0;
}
