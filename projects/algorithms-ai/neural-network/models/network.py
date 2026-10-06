from typing import List
from .layer import Layer

class NeuralNetwork:
    def __init__(self):
        self.layers: List[Layer] = []

    def add_layer(self, num_neurons: int, num_inputs: int, activation_function: str):
        self.layers.append(Layer(num_neurons, num_inputs, activation_function))
