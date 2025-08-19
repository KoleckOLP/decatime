#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    clock_t next_tick = clock();
    while(1) {
        struct timeval tv; // give you tv.tv_sec (seconds since 1970) and tv.tv_usec (microseconds since the last second)

        if (gettimeofday(&tv, NULL) != 0) { // checking if time of day doesn't fail
            perror("Failed to get current time");
            return 1;
        }

        time_t seconds = (time_t)tv.tv_sec; // cast to time_t, fixes a compile time error
        struct tm *local = localtime(&seconds); // gives you a pointer to tm_sec, tm_min, tm_hour, tm_ mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst
        if (!local) {
            perror("Failed to convert time");
            return 1;
        }

        // deca time code here
        double total_seconds = local->tm_hour*3600 + local->tm_min*60 + local->tm_sec + tv.tv_usec / 1000000.0;
        double decimal_total = total_seconds * (100000.0 / 86400.0);

        // separate integer and fractional parts
        int dec_hour = (int)(decimal_total / 10000);
        int remainder = (int)decimal_total % 10000;

        int dec_min = remainder / 100;
        int dec_sec = remainder % 100;

        printf("  %02d-%02d-%d %02d:%02d:%02d %02d:%02d:%02d\r", 
            local->tm_mday, local->tm_mon + 1, local->tm_year + 1900, 
            local->tm_hour, local->tm_min, local->tm_sec,
            dec_hour, dec_min, dec_sec);
        
        fflush(stdout);

        next_tick += CLOCKS_PER_SEC / 10; // 1000ms
        while(clock() < next_tick); // wait
    }

    return 0;
}
