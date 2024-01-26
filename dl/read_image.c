#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(){
    int width, height, channels;

    unsigned char *img = stbi_load("pet.png", &width, &height, &channels, 0);

    if (img == NULL){
        printf("Error loading the image.");
        exit(1);
    }

    printf("Loaded image with width: %dpx height: %dpx and channles: %dpx \n", width, height, channels);

}