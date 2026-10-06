import json
from models.network import NeuralNetwork
from utils.config_parser import parse_config

class NetworkGenerator:
    def generate_from_config(self, config_path: str) -> NeuralNetwork:
        config = parse_config(config_path)
        network = NeuralNetwork()
        prev_size = config['layers'][0]['size']

        for layer in config['layers'][1:]:
            network.add_layer(layer['size'], prev_size, 'sigmoid')
            prev_size = layer['size']

        return network

    def save_network(self, network: NeuralNetwork, filename: str):
        data = {
            'layers': [{
                'activation_function': layer.activation_function,
                'weights': [neuron.weights for neuron in layer.neurons],
                'biases': [neuron.bias for neuron in layer.neurons]
            } for layer in network.layers]
        }

        with open(filename, 'w') as f:
            json.dump(data, f, indent=4)
