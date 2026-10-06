# Neural Network — Multi-Layer Perceptron & Gradient Descent from Scratch

A lightweight artificial neural network framework implemented from mathematical first principles without relying on high-level machine learning libraries.

## Overview

This project implements a multi-layer feedforward perceptron designed for classification and regression tasks. It implements matrix mathematical operations, activation functions, and reverse-mode automatic differentiation (backpropagation) to optimize network weights via stochastic gradient descent.

## Architecture & Technical Highlights

- **Forward Propagation:** Matrix multiplication kernels applying layer weights, bias vectors, and activation functions.
- **Activation Functions & Derivatives:** Implements Sigmoid, ReLU, LeakyReLU, and Softmax functions with analytic derivative calculations.
- **Backpropagation Engine:** Gradient calculation utilizing the chain rule to propagate error vectors from output layers back through hidden representations.
- **Optimization Routines:** Mini-batch gradient descent with adaptive learning rates and weight decay regularization.

## Tech Stack

- **Language:** Python / C++
- **Math Primitives:** Linear Algebra & Matrix Calculus
- **Architecture:** Feedforward Multi-Layer Perceptron (MLP)

## Build & Execution

```bash
# Train network on dataset
python3 train.py --config config/network.json --data dataset.csv

# Run inference
python3 predict.py --model models/weights.bin --input test_sample.csv
```
