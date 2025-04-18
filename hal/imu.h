#ifndef IMU_H
#define IMU_H

typedef struct {
    float x;  // Angular velocity around X-axis (roll rate)
    float y;  // Angular velocity around Y-axis (pitch rate)
    float z;  // Angular velocity around Z-axis (yaw rate)
} imu_data_t;

void imu_init(void);
imu_data_t imu_read(void);

#endif