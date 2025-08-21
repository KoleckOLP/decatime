#include <stdio.h>
#include <string.h>

void print_usage(const char *prog_name) {
    // Find the last occurrence of '/' or '\\' to get the executable name
    const char *base = strrchr(prog_name, '\\');
    if (!base) base = strrchr(prog_name, '/');
    base = base ? base + 1 : prog_name;

    printf("Decimal Time Converter by koleq (C)2025\n\n");
    printf("Usage: %s <mode> <time>\n", base);
    printf("  mode: 'st' for standard time\n"
           "        'dt' for decimal time\n"
           "  time: in format HH:MM:SS\n");
}

int convert_st_to_dt(const char *time_input) {
    int hours = 0, minutes = 0, seconds = 0;
    int matched = sscanf(time_input, "%d:%d:%d", &hours, &minutes, &seconds);
    if (matched < 2) {
        printf("Invalid time format. Use HH:MM or HH:MM:SS.\n");
        return 1;
    }
    // seconds will be 0 if not provided
    double total_seconds = hours * 3600 + minutes * 60 + seconds;
    double decimal_total = total_seconds * (100000.0 / 86400.0);

    int dec_hour = (int)(decimal_total / 10000);
    int remainder = (int)decimal_total % 10000;
    int dec_min = remainder / 100;
    int dec_sec = remainder % 100;

    printf("Standard time %02d:%02d:%02d is Decimal time %02d:%02d:%02d\n",
           hours, minutes, seconds, dec_hour, dec_min, dec_sec);
    return 0;
}

int convert_dt_to_st(const char *time_input) {
    int dec_hour = 0, dec_min = 0, dec_sec = 0;
    int matched = sscanf(time_input, "%d:%d:%d", &dec_hour, &dec_min, &dec_sec);
    if (matched < 2) {
        printf("Invalid time format. Use HH:MM or HH:MM:SS.\n");
        return 1;
    }
    // dec_sec will be 0 if not provided
    double decimal_total = dec_hour * 10000 + dec_min * 100 + dec_sec;
    double total_seconds = decimal_total * (86400.0 / 100000.0);

    int hours = (int)(total_seconds / 3600);
    total_seconds -= hours * 3600;
    int minutes = (int)(total_seconds / 60);
    int seconds = (int)(total_seconds - minutes * 60);

    printf("Decimal time %02d:%02d:%02d is Standard time %02d:%02d:%02d\n",
           dec_hour, dec_min, dec_sec, hours, minutes, seconds);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) { // if there aren't 3 arguments print usage
        print_usage(argv[0]);
        return 1;
    }

    const char *mode = argv[1];
    const char *time_input = argv[2];

    printf("The address of argv[1] is: %p\n", argv[1]);
    printf("The address of the 'mode' pointer is: %p\n", mode);

    if (strcmp(mode, "st") == 0) {
        return convert_st_to_dt(time_input);
    } else if (strcmp(mode, "dt") == 0) {
        return convert_dt_to_st(time_input);
    } else {
        printf("Invalid mode. Use 'st' for standard time or 'dt' for decimal time.\n");
        return 1;
    }

    return 0;
}