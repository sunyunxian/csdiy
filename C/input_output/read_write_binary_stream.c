#include <stdio.h>
#include <stdlib.h>

#define FILENAME "gs.bin"

typedef struct {
    float volume;
    int   resolution_x;
    int   resolution_y;
    int   difficulty;
} GetSettings;

void set_game_settings(const GetSettings* write_settings, const char* filename);
void get_game_settings(const GetSettings* read_settings, const char* filename);

int main(int argc, char const* argv[]) {
    GetSettings write_setting = {
        10.0,
        1024,
        1080,
        1,
    };
    set_game_settings(&write_setting, FILENAME);

    GetSettings read_setting;
    get_game_settings(&read_setting, FILENAME);

    return 0;
}
void set_game_settings(const GetSettings* write_settings, const char* filename) {
    FILE* fp;
    if ((fp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "open file %s error\n", filename);
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fwrite(write_settings, sizeof(GetSettings), 1, fp);

    fclose(fp);
}

void get_game_settings(const GetSettings* read_settings, const char* filename) {
    FILE* fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "open file %s error\n", filename);
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    size_t rst = fread(read_settings, sizeof(GetSettings), 1, fp);
    printf("read_setting.volume = %f read_setting.resolution_x= %d\n", read_settings->volume,
           read_settings->resolution_x);
    fclose(fp);
}
