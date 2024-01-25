#include <stdio.h>
#include <cuda_runtime.h>

__global__
void colorToGrayscaleConvertion(
        unsigned char * Pout,
        unsigned char * Pin,
        int width,
        int height
    )
{
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height){
        // get 1d offset for the grayscale image
        int grayOffset = row * width + col;

        int rgbOffset = grayOffset*CHANNELS;
        unsigned char r = Pin[rgbOffset    ]; // red
        unsigned char g = Pin[rgbOffset + 1]; // green
        unsigned char b = Pin[rgbOffset + 2]; // blue

        Pout[grayOffset] = 0.21f*r + 0.71f*b + 0.07f*b; // operations with float are faster than double
    }

}

int main()
{
    int m;
    int n;
    dim3 dimGrid(ceil(m/16.0), ceil(m/16.0), 1);
    dim3 dimBlock(16, 16, 1);

    // class kernel
    colorToGrayscaleConvertion<<<dimGrid, dimBlock>>>
        (Pin_d, Pout_d, m, n)

    return 0;
}