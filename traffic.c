#include <err.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>

#define LIGHT_MASK 0x0F
#define SHIFT_MASK 0x01

void init(unsigned char *lights) {

    *lights = 0;
}

void turn_on(unsigned char *lights, unsigned char light_num) {
    
    *lights |= (1 << light_num);
}

void turn_off(unsigned char *lights, unsigned char light_num) {
    
    *lights &= ~(1 << light_num);
}

void next_step(unsigned char *lights) {
  
    *lights = (*lights << 1) ^ ((*lights & (1 << 3)) ? SHIFT_MASK : 0);
}

void reverse(unsigned char *lights) {
    
    *lights ^= LIGHT_MASK;
}

void swap(unsigned char *lights_1, unsigned char *lights_2) {
   
    *lights_1 ^= *lights_2;
    *lights_2 ^= *lights_1;
    *lights_1 ^= *lights_2;
}
