#include <stdio.h>

int main(void)
{
    const int warning_threshold_c = 40;
    const int alarm_threshold_c = 60;
    int temperature_c = 25;

    printf("Temperature: %d C\n", temperature_c);
    printf("Warning threshold: %d C\n", warning_threshold_c);
    printf("Alarm threshold: %d C\n", alarm_threshold_c);

    /* TODO: Print NORMAL, WARNING, or ALARM using if / else if / else. */
    /* TODO: Test the boundary values listed in README.md. */
    /* TODO: Add a loop from 25 C to 65 C in steps of 10 C. */

    return 0;
}
