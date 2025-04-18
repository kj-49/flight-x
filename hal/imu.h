#ifndef IMU_H
#define IMU_H

typedef struct {
    float x, y, z;
} imu_data_t;

void imu_init(void);
imu_data_t imu_read(void);

#endif