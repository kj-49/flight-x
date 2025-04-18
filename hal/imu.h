#ifndef IMU_H
#define IMU_H

typedef struct {
    float x, y, z;
} gyro_data_t;

void imu_init(void);
gyro_data_t imu_read_gyro(void);

#endif