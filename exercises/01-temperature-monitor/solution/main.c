#include <stdio.h>

int main(void)
{
    const int warning_threshold_c = 40;
    const int alarm_threshold_c = 60;
    int alarm_count = 0;

    /* Synthetic readings: no physical sensor is connected. */
    for (int temperature_c = 25; temperature_c <= 65; temperature_c += 10) {
        printf("Temperature: %d C | Status: ", temperature_c);

        if (temperature_c >= alarm_threshold_c) {
            printf("ALARM\n");
            alarm_count++;
        } else if (temperature_c >= warning_threshold_c) {
            printf("WARNING\n");
        } else {
            printf("NORMAL\n");
        }
    }

    printf("Alarm count: %d\n", alarm_count);
    return 0;
}
