#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    const struct timespec sleep_time = {0, 100 * 1000000L}; // 100ms = 100,000,000 ns

    while(1) {
        struct timeval tv;

        if (gettimeofday(&tv, NULL) != 0) {
            perror("Failed to get current time");
            return 1;
        }

        time_t seconds = (time_t)tv.tv_sec;
        struct tm *local = localtime(&seconds);
        if (!local) {
            perror("Failed to convert time");
            return 1;
        }

        // deca time calculation
        double total_seconds = local->tm_hour*3600 + local->tm_min*60 + local->tm_sec + tv.tv_usec / 1000000.0;
        double decimal_total = total_seconds * (100000.0 / 86400.0);

        int dec_hour = (int)(decimal_total / 10000);
        int remainder = (int)decimal_total % 10000;
        int dec_min = remainder / 100;
        int dec_sec = remainder % 100;

        printf("   %02d-%02d-%d st: %02d:%02d:%02d dt: %02d:%02d:%02d\r", 
            local->tm_mday, local->tm_mon + 1, local->tm_year + 1900, 
            local->tm_hour, local->tm_min, local->tm_sec,
            dec_hour, dec_min, dec_sec);
        fflush(stdout);

        // sleep efficiently for 100ms
        nanosleep(&sleep_time, NULL);
    }

    return 0;
}
