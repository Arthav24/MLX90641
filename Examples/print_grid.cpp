#include <MLX90641_API.h>
#include <MLX90641_I2C_Driver.h>
#include <bcm2835.h>
#include <iostream>
#include <stdint.h>
#define slave_addr 0x33
#define TA_SHIFT 5
using namespace std;
float emissivity = 0.95;
float tr;
static uint16_t eeprom[832];
static uint16_t frame[242];
paramsMLX90641 params;
static float temperatures[192];
void get_pixels();
void print_pixels();
int main() {
  
while(1) {
  delay(2000);
  get_pixels();
  print_pixels();  
}
}
void get_pixels()
{
  MLX90641_DumpEE(slave_addr,eeprom);
  MLX90641_ExtractParameters(eeprom, &params);
  MLX90641_GetFrameData(slave_addr, frame);
  tr = MLX90641_GetTa(frame,&params) - TA_SHIFT;
  MLX90641_CalculateTo(frame,&params,emissivity,tr,temperatures);
}

void print_pixels()
{
  for(int i = 0 ; i < 12 ; i++){ //rows
    for(int j = 0 ; j < 16 ; j++) // cols 
    {
      cout << temperatures[j+16*i] << " : ";
      //cout <<(16 * (11-i) + j)<< " : ";
     
      
      
    }
    cout << "\n\n";  
  }
  cout <<"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"; 
}

