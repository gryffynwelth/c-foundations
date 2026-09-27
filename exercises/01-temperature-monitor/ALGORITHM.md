# Algorithm

## Stage A: Classify one reading

1. Set the warning threshold to 40 C and the alarm threshold to 60 C.
2. Set the simulated temperature to 25 C.
3. If the temperature is at least 60 C, print ALARM.
4. Otherwise, if the temperature is at least 40 C, print WARNING.
5. Otherwise, print NORMAL.
6. Stop.

## Stage B: Process multiple readings

1. Set the warning threshold to 40 C and the alarm threshold to 60 C.
2. Set the alarm count to zero.
3. Start the simulated temperature at 25 C.
4. While the temperature is at most 65 C, print the temperature and classify it.
5. If the status is ALARM, increase the alarm count by one.
6. Increase the temperature by 10 C and repeat from step 4.
7. Print the alarm count and stop.

## Pseudocode

```text
SET warning_threshold_c TO 40
SET alarm_threshold_c TO 60
SET alarm_count TO 0
SET temperature_c TO 25

WHILE temperature_c <= 65
    PRINT temperature_c
    IF temperature_c >= alarm_threshold_c
        PRINT "ALARM"
        INCREMENT alarm_count
    ELSE IF temperature_c >= warning_threshold_c
        PRINT "WARNING"
    ELSE
        PRINT "NORMAL"
    END IF
    SET temperature_c TO temperature_c + 10
END WHILE

PRINT alarm_count
```
