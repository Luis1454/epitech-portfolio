import random
import math

class Neuron:
    def __init__(self):
        self.weights = []
        self.bias = random.uniform(-1, 1)

    def initialize_weights(self, num_inputs: int):
        limit = math.sqrt(6 / num_inputs)
        self.weights = [random.uniform(-limit, limit) for _ in range(num_inputs)]
