#include <stdio.h>

int main() {
    int N, M, B, max = 0;
    scanf("%d %d %d", &N, &M, &B);

    int arr[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    int result = 128000000, height, land;

    for (land = max; land >= 0; land--) {
        int set = 0, remove = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] < land)
                    set += land - arr[i][j];
                else if (arr[i][j] > land)
                    remove += arr[i][j] - land;
            }
        }

        int time = set + remove * 2;
        int inventory = B + remove - set;

        if (time < result && inventory >= 0) {
            height = land;
            result = time;
        }
    }

    printf("%d %d\n", result, height);
    
    return 0;
}
