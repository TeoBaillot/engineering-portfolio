# LeNet CNN on FPGA using High Level Synthesis

Implementation of the LeNet convolutional neural network on a Xilinx Zynq-7000 FPGA platform using Vivado HLS for hardware acceleration.

## Overview

This project demonstrates CNN inference acceleration on FPGAs by implementing LeNet for MNIST digit classification. The network achieves 97.82% accuracy in floating-point and 97.79% in fixed-point (14-bit representation).

## Architecture

- **Input**: 28×28 grayscale MNIST images
- **Layers**: 2 convolutional layers (5×5 kernels), 2 pooling layers, 2 fully connected layers
- **Output**: 10-class digit classification with softmax

## Implementation

### Software Version
- Sequential execution on embedded processor
- Fixed-point arithmetic (14-bit shift offset)
- Baseline implementation for functional verification

### Hardware-Accelerated Version
- Vivado HLS synthesis with `#pragma HLS PIPELINE` directives
- Targets Conv1, Conv2, and Fc1 layers (most compute-intensive)
- Operating frequency: ~114 MHz (8.742 ns clock period)
- Conv1 fully accelerated; Conv2 and Fc1 remain in software due to time constraints

## Performance Results

| Platform | Execution Time | Speedup |
|----------|---------------|---------|
| PC (SW) | 20s | - |
| Xilinx SW-only | 900s | - |
| Xilinx HW-accelerated | 450s | 2× |

**Note**: Only Conv1 is hardware-accelerated in the final implementation. Full hardware synthesis of the entire inference pipeline could theoretically achieve ~350s execution time.

## Resource Utilization

| Resource | SW | HW-Accelerated |
|----------|-----|----------------|
| Latency (cycles) | 8.3M | 990,659 |
| BRAM | 50 | Higher |
| LUTs | 2,666 | Higher |
| DSPs | Low | High |

## Key Design Decisions

- **Fixed-point arithmetic**: Reduces hardware complexity and improves DSP utilization
- **Global weight variables**: Avoids array duplication for large Conv2 and Fc1 kernels (80 KB and 1 MB respectively)
- **Resource balancing**: Latency optimized while preventing LUT RAM saturation (>100% would prevent deployment)

## Tools

- Xilinx Vivado HLS
- Xilinx Zynq-7000 Platform
- TensorFlow/Keras (for training)

## Authors

- ABDERRAHMANE Mohamed Redha
- BAILLOT D'ESTIVAUX Téo