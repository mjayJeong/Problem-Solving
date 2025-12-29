#include <iostream>

using namespace std;

int main()
{
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int answer = 0; 
    int width, height;
    if (W % (1+M) == 0) width = W / (1+M);
    else width = (W / (1+M) + 1);

    if (H % (1+N) == 0) height = H / (1+N);
    else height = (H / (1+N) + 1);

    answer = width * height;

    cout << answer << '\n';

    return 0;
}
