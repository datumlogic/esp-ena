/*
 Note: The MPU6886 is an I2C sensor and uses the Arduino Wire library.
 Because the sensor is not 5V tolerant, we are using a 3.3 V 8 MHz Pro Mini or
 a 3.3 V Teensy 3.1. We have disabled the internal pull-ups used by the Wire
 library in the Wire.h/twi.c utility file. We are also using the 400 kHz fast
 I2C mode by setting the TWI_FREQ  to 400000L /twi.h utility file.
 */
#ifndef _IMU_MPU6886_H_
#define _IMU_MPU6886_H_

#include "stdio.h"

#define MPU6886_ADDRESS 0x68
#define MPU6886_WHOAMI 0x75
#define MPU6886_ACCEL_INTEL_CTRL 0x69
#define MPU6886_SMPLRT_DIV 0x19
#define MPU6886_INT_PIN_CFG 0x37
#define MPU6886_INT_ENABLE 0x38
#define MPU6886_ACCEL_XOUT_H 0x3B
#define MPU6886_ACCEL_XOUT_L 0x3C
#define MPU6886_ACCEL_YOUT_H 0x3D
#define MPU6886_ACCEL_YOUT_L 0x3E
#define MPU6886_ACCEL_ZOUT_H 0x3F
#define MPU6886_ACCEL_ZOUT_L 0x40

#define MPU6886_TEMP_OUT_H 0x41
#define MPU6886_TEMP_OUT_L 0x42

#define MPU6886_GYRO_XOUT_H 0x43
#define MPU6886_GYRO_XOUT_L 0x44
#define MPU6886_GYRO_YOUT_H 0x45
#define MPU6886_GYRO_YOUT_L 0x46
#define MPU6886_GYRO_ZOUT_H 0x47
#define MPU6886_GYRO_ZOUT_L 0x48

#define MPU6886_USER_CTRL 0x6A
#define MPU6886_PWR_MGMT_1 0x6B
#define MPU6886_PWR_MGMT_2 0x6C
#define MPU6886_CONFIG 0x1A
#define MPU6886_GYRO_CONFIG 0x1B
#define MPU6886_ACCEL_CONFIG 0x1C
#define MPU6886_ACCEL_CONFIG2 0x1D
#define MPU6886_FIFO_EN 0x23

//#define G (9.8)
#define RtA 57.324841
#define AtR 0.0174533
#define Gyro_Gr 0.0010653

enum Ascale
{
    AFS_2G = 0,
    AFS_4G,
    AFS_8G,
    AFS_16G
} ;

enum Gscale
{
    GFS_250DPS = 0,
    GFS_500DPS,
    GFS_1000DPS,
    GFS_2000DPS
};

int mpu6886_start(void);
void mpu6886_get_accel_adc(int16_t *ax, int16_t *ay, int16_t *az);
void mpu6886_get_gyro_adc(int16_t *gx, int16_t *gy, int16_t *gz);
void mpu6886_get_temp_adc(int16_t *t);

void mpu6886_get_accel_data(float *ax, float *ay, float *az);
void mpu6886_get_gyro_data(float *gx, float *gy, float *gz);
void mpu6886_get_temp_data(float *t);

void mpu6886_set_gyro_fsr(int scale);
void mpu6886_set_accel_fsr(int scale);

#endif