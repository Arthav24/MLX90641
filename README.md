# mlx90641-library adapted for Raspberry Pi

This library takes the official Melexis library found here:

https://github.com/melexis/mlx90641-library

and adapts it specifically for the Raspberry Pi. 

From datasheet:
The MLX90641 is a fully calibrated 16x12 pixels
thermal IR array in an industry standard 4-lead
TO39 package with digital interface.
The MLX90641 contains 192 FIR pixels. An
ambient sensor is integrated to measure the
ambient temperature of the chip and supply
sensor to measure the VDD. The outputs of all
sensors IR, Ta and VDD are stored in internal RAM
and are accessible through I2C.

This branch of the MLX90641 library is mostly filling the in the 
MLX90641_I2C_Driver.cpp file using the BCM2835.

The Melexis library extracts all the required calibration data, in fact 
the whole EEPROM, and dumps it into an array, which totals 1664 bytes. 
This library was written to work around the limitations imposed by this.

Default I2C slave address of device is 0x33 but this may not be the case 
for your device.

To get the best out of your sensor you should modify `/boot/config.txt` and change your I2C baudrate.

The fastest rate recommended for compatibility with other sensors is 400kHz. This is compatible with SMBus devices:

```text
dtparam=i2c1_baudrate=400000
```

This will give you a framerate of - at most - 8FPS.

### BCM2835 Library 
To use the bcm2835 library, install like so:

```text
make bcm2835
```

Or, manually:
```text
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.59.tar.gz
tar xvfz bcm2835-1.59.tar.gz
cd bcm2835-1.59
./configure
make
sudo make install
```
### Example/print_grid.cpp
This is a simple program to test the sensor is working or not.
It prints a matrix of 16x12, each cell denoting a temperature in Celsius.
To compile and try print_grid.cpp
```text
make 
sudo ./printgrid
```
