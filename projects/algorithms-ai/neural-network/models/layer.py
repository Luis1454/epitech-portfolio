from .neuron import Neuron

activation_functions = {"sigmoid", "tanh", "relu"}

class Layer:
    def __init__(self, num_neurons: int, num_inputs: int, activation_function: str):
        self.neurons = [Neuron() for _ in range(num_neurons)]
        self.activation_function = activation_function
        for neuron in self.neurons:
            neuron.initialize_weights(num_inputs)
