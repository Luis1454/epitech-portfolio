#!/usr/bin/python3

import random
import math
import sys

def create_icao(i):
    icao = chr(ord('A') + i % 26)
    i = math.floor(i / 26)
    icao += chr(ord('A') + i % 26)
    i = math.floor(i / 26)
    icao += chr(ord('A') + i % 26)
    i = math.floor(i / 26)
    icao += chr(ord('A') + i % 26)
    icao = icao[::-1]
    return icao

def create_tower(name, icao, x, y, alt, range, capacity, taxiing_time):
    return "T %s %s %d %d %f %f %d %d" % (name, icao, x, y, alt, range, capacity, taxiing_time)

def create_aircraft(name, callsign, departure_icao, arrival_icao, departure_timestamp, climb_rate, climb_speed, cruise_speed, cruise_alt, approch_rate, approach_speed, fuel_capacity, fuel_consumption, stall_speed):
    return "A %s %s %s %s %d %d %d %d %d %d %d %f %f %f" % (name, callsign, departure_icao, arrival_icao, departure_timestamp, climb_rate, climb_speed, cruise_speed, cruise_alt, approch_rate, approach_speed, fuel_capacity, fuel_consumption, stall_speed)

def create_random_tower(i):
    name = "tower-%d" % i
    icao = create_icao(i)
    x = random.randint(0, 1000)
    y = random.randint(0, 1000)
    alt = random.randint(0, 100)
    range = random.randint(50, 200)
    capacity = random.randint(0, 1000)
    taxiing_time = random.randint(0, 1000)
    return create_tower(name, icao, x, y, alt, range, capacity, taxiing_time)

def create_random_aircraft(i, n):
    name = "aircraft-%d" % random.randint(0, 1000)
    callsign = "F-" + str(create_icao(i))
    departure_icao = str(create_icao(random.randint(0, n - 1)))
    tmp = departure_icao
    while (tmp == departure_icao):
        tmp = str(create_icao(random.randint(0, n - 1)))
    arrival_icao = tmp
    departure_timestamp = random.randint(0, 10000)
    climb_rate = random.randint(0, 1000)
    climb_speed = random.randint(100, 500)
    cruise_speed = random.randint(500, 1000)
    cruise_alt = random.randint(100, 50000)
    approch_rate = random.randint(0, 1000)
    approach_speed = random.randint(100, 400)
    fuel_capacity = random.randint(0, 1000)
    fuel_consumption = random.randint(0, 1000)
    stall_speed = random.randint(0, 1000)
    return create_aircraft(name, callsign, departure_icao, arrival_icao, departure_timestamp, climb_rate, climb_speed, cruise_speed, cruise_alt, approch_rate, approach_speed, fuel_capacity, fuel_consumption, stall_speed)

def create_random_towers(n):
    towers = []
    for i in range(n):
        towers.append(create_random_tower(i))
    return towers

def create_random_aircrafts(n, t):
    aircrafts = []
    for i in range(n):
        aircrafts.append(create_random_aircraft(i, t))
    return aircrafts

def create_random_scenario(n_towers, n_aircrafts):
    towers = create_random_towers(n_towers)
    aircrafts = create_random_aircrafts(n_aircrafts, n_towers)
    return towers + aircrafts

def write_scenario(scenario, filename):
    with open(filename, "w") as f:
        for line in scenario:
            f.write(line + "\n")
        f.write("TIME 0 250\n\n")
        f.write("RANGE_METRIC 1 1 0\n")
        f.write("AIRCRAFT_METRIC 1 1 0\n")

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 generator.py <n_towers> <n_aircrafts>")
        return
    if int(sys.argv[1]) <= 1:
        print("n_towers must be greater than 1")
        return
    if int(sys.argv[2]) < 1:
        print("n_aircrafts must be greater than 0")
        return
    n_towers = int(sys.argv[1])
    n_aircrafts = int(sys.argv[2])
    scenario = create_random_scenario(n_towers, n_aircrafts)
    write_scenario(scenario, "scenario.rdr")

if __name__ == "__main__":
    main()
