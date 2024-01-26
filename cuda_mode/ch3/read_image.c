#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(){

    int width, height, channels;
    uint8_t *img = stbi_load("pet.png", &width, &height, &channels, 3);

    if (img == NULL){
        printf("Error loading the image.");
        exit(1);
    }

    stbi_image_free(img);

    printf("Loaded image with width: %dpx height: %dpx and channles: %dpx \n", width, height, channels);


    return 0;
}