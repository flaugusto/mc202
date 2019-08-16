#include <stdio.h>

int main() {
    int n, i, h, lim;
    scanf("%d", &n);

    int speeds[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &speeds[i]);
    }
    
    scanf("%d", &h);

    if (h == 1) {
        lim = 100;
    } else if (h == 2) {
        lim = 20;
    } else {
        lim = 10;
    }
    
    int max = 0;
    for (i = 0; i < n; i++) {
        int v = speeds[i];
        if (v > max && v <= lim)
            max = v;
    }
    
    printf("%d\n", max);
    
    return 0;
}
