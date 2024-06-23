#include <stdio.h>

void go_south_east(int *lat, int *lon) {
    // 纬度 -1
    *lat = *lat - 1;
    // 经度 +1
    *lon = *lon + 1;
}

int main() {
    int latitude = 32;
    int longitude = -64;
    go_south_east(&latitude, &longitude);
    printf("停！当前位置是：[%i, %i]\n", latitude, longitude);
    return 0;
}
