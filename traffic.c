#include <err.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>

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
   
    *lights = (*lights << 1) | ((*lights & 0x08) >> 3);
}

void reverse(unsigned char *lights) {

    *lights ^= 0x0F;
}

void swap(unsigned char *lights_1, unsigned char *lights_2) {

    *lights_1 ^= *lights_2;
    *lights_2 ^= *lights_1;
    *lights_1 ^= *lights_2;
}
