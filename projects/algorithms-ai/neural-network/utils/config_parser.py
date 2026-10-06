import json
from typing import Dict, Any

def validate_layer_config(layer: Dict[str, Any]) -> bool:
    required_fields = ['type', 'size']
    return all(field in layer for field in required_fields)

def validate_config(config: Dict[str, Any]) -> bool:
    if 'layers' not in config:
        raise ValueError("Config must contain 'layers' field")

    layers = config['layers']
    if not layers or len(layers) < 2:
        raise ValueError("Config must contain at least input and output layers")

    return all(validate_layer_config(layer) for layer in layers)

def parse_config(config_path: str) -> Dict[str, Any]:
    try:
        with open(config_path, 'r') as f:
            config = json.load(f)

        if validate_config(config):
            return config
    except json.JSONDecodeError:
        raise ValueError(f"Invalid JSON format in {config_path}")
    except FileNotFoundError:
        raise FileNotFoundError(f"Config file not found: {config_path}")
