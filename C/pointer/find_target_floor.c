#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    u_int32_t building_floors[5] = {101, 102, 103, 104, 105};
    u_int32_t target_floor = 103;
    u_int8_t  found = 0;

    printf("Starting find\n");
    for (uint32_t i = 0; i < 5; i++) {
        printf("%d, address = %lu\n", target_floor, (void *)&building_floors[i]);
        if (building_floors[i] == target_floor) {
            printf("find %d, address = %lu\n", target_floor, &building_floors[i]);
            printf("Set %d = 1000\n", target_floor);
            u_int32_t *p = &building_floors[i];
            *p = 1000;
            printf("building_floors[%d] = %d\n", i, (*p));
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not found\n");
    }

    return 0;
}
