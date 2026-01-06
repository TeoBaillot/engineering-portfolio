#include "lenet_cnn_fixed.h"
#include "fixed_point.h"

void Conv1_28x28x1_5x5x20_1_0(int32_t input[IMG_DEPTH][IMG_HEIGHT][IMG_WIDTH],                // IN
    int32_t kernel[CONV1_NBOUTPUT][IMG_DEPTH][CONV1_DIM][CONV1_DIM],                          // IN
    int32_t bias[CONV1_NBOUTPUT],                                                              // IN
    int32_t output[CONV1_NBOUTPUT][CONV1_HEIGHT][CONV1_WIDTH])                                 // OUT
{
//#pragma HLS RESOURCE variable=kernel core=RAM_2P_BRAM
//#pragma HLS RESOURCE variable=bias core=RAM_1P_BRAM

    int32_t res = 0;
    for (short filter_index = 0; filter_index < CONV1_NBOUTPUT; filter_index++) {

        for (short y = 0;y < IMG_WIDTH - CONV1_DIM + 1;y += CONV1_STRIDE) {

            for (short x = 0; x < IMG_HEIGHT - CONV1_DIM + 1; x += CONV1_STRIDE) {
#pragma HLS PIPELINE
                res = 0;

                for (short ky = 0; ky < CONV1_DIM; ky += CONV1_STRIDE) {

                    for (short kx = 0; kx < CONV1_DIM; kx += CONV1_STRIDE) {
                        res += fixed_mul(input[0][y + ky][x + kx] , kernel[filter_index][0][ky][kx]);
                    }
                }
                res += bias[filter_index];
                output[filter_index][y][x] = res >0 ? res :0;
            }
        }
    }
}

void Pool1_24x24x20_2x2x20_2_0(int32_t input[CONV1_NBOUTPUT][CONV1_HEIGHT][CONV1_WIDTH],      // IN
    int32_t output[POOL1_NBOUTPUT][POOL1_HEIGHT][POOL1_WIDTH])                                 // OUT
{
    for (short z = 0; z < CONV1_NBOUTPUT; z++) {

        for (short x = 0; x < CONV1_WIDTH - POOL1_DIM + 1; x += POOL1_STRIDE) {
            for (short y = 0; y < CONV1_HEIGHT - POOL1_DIM + 1; y += POOL1_STRIDE) {
                int32_t tab[4] = { input[z][y][x], input[z][y][x + 1], input[z][y + 1][x], input[z][y + 1][x + 1] };
                int32_t max = tab[0];
                for (short i = 1; i < 4; i++) {
                    max = max < tab[i] ? tab[i] : max;
                }
                output[z][y / POOL1_STRIDE][x / POOL1_STRIDE] = max;
            }
        }
    }
}

void Conv2_12x12x20_5x5x40_1_0(
    int32_t input[POOL1_NBOUTPUT][POOL1_HEIGHT][POOL1_WIDTH],
    int32_t bias[CONV2_NBOUTPUT],
    int32_t output[CONV2_NBOUTPUT][CONV2_HEIGHT][CONV2_WIDTH]
)
{
    int32_t res = 0;

    for (short filter_index = 0; filter_index < CONV2_NBOUTPUT; filter_index++) {
        for (short y = 0; y < POOL1_WIDTH - CONV2_DIM + 1; y += CONV2_STRIDE) {
            for (short x = 0; x < POOL1_HEIGHT - CONV2_DIM + 1; x += CONV2_STRIDE) {

                res = 0;

                for (short z = 0; z < POOL1_NBOUTPUT; z++) {
#pragma HLS PIPELINE
                    for (short ky = 0; ky < CONV2_DIM; ky += CONV2_STRIDE) {
                        for (short kx = 0; kx < CONV2_DIM; kx += CONV2_STRIDE) {
                            res += fixed_mul(input[z][y + ky][x + kx], CONV2_KERNEL_FIXED[filter_index][z][ky][kx]);
                        }
                    }
                }

                res += bias[filter_index];
                output[filter_index][y][x] = res > 0 ? res : 0;
            }
        }
    }
}
void Pool2_8x8x40_2x2x40_2_0(int32_t input[CONV2_NBOUTPUT][CONV2_HEIGHT][CONV2_WIDTH],
    int32_t output[POOL2_NBOUTPUT][POOL2_HEIGHT][POOL2_WIDTH])
{
    for (short z = 0; z < CONV2_NBOUTPUT; z++) {
        for (short x = 0; x < CONV2_WIDTH - POOL2_DIM + 1; x += POOL2_STRIDE) {
            for (short y = 0; y < CONV2_HEIGHT - POOL2_DIM + 1; y += POOL2_STRIDE) {
                int32_t tab[4] = { input[z][y][x], input[z][y][x + 1], input[z][y + 1][x], input[z][y + 1][x + 1] };
                int32_t max = tab[0];
                for (short i = 1; i < 4; i++) {
                    max = max < tab[i] ? tab[i] : max;
                }
                output[z][y / POOL2_STRIDE][x / POOL2_STRIDE] = max;
            }
        }
    }
}


void Fc1_40_400(int32_t input[POOL2_NBOUTPUT][POOL2_HEIGHT][POOL2_WIDTH],
    int32_t bias[FC1_NBOUTPUT],
    int32_t output[FC1_NBOUTPUT])
{
//#pragma HLS RESOURCE variable=FC1_KERNEL_FIXED core=RAM_2P_BRAM
//#pragma HLS RESOURCE variable=bias core=RAM_1P_BRAM

    int32_t sum =0;

    for (short k = 0; k < FC1_NBOUTPUT; k++) {

        sum= bias[k];

        for (short z = 0; z < POOL2_NBOUTPUT; z++)
#pragma HLS PIPELINE
            for (short y = 0; y < POOL2_HEIGHT; y++)
//#pragma HLS PIPELINE
                for (short x = 0; x < POOL2_WIDTH; x++)
                    sum += fixed_mul(input[z][y][x], FC1_KERNEL_FIXED[k][z][y][x]);
        output[k] = (sum > 0) ? sum : 0;
    }
}
void Fc2_400_10(int32_t input[FC1_NBOUTPUT],
    int32_t kernel[FC2_NBOUTPUT][FC1_NBOUTPUT],
    int32_t bias[FC2_NBOUTPUT],
    int32_t output[FC2_NBOUTPUT])
{
//#pragma HLS RESOURCE variable=kernel core=RAM_2P_BRAM
//#pragma HLS RESOURCE variable=bias core=RAM_1P_BRAM

    int32_t sum=0;
    for (short k = 0; k < FC2_NBOUTPUT; k++) {
        sum = bias[k];
        for (short i = 0; i < FC1_NBOUTPUT; i++){
            sum += fixed_mul(input[i], kernel[k][i]);
        }
        output[k] = (sum > 0) ? sum : 0;
    }
}

void Softmax(int32_t vector_in[FC2_NBOUTPUT], float vector_out[FC2_NBOUTPUT]) {

    float frac_sum = 0;
    float exp_values[FC2_NBOUTPUT];
    for (short k = 0; k < FC2_NBOUTPUT; k++) {
        exp_values[k] = exp(fixed_to_float(vector_in[k]));
        frac_sum += exp_values[k];
    }

    for (short j = 0; j < FC2_NBOUTPUT; j++) {
        vector_out[j] = exp_values[j] / frac_sum;
    }
}
