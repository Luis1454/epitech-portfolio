#!/usr/bin/env python3

import math
import sys

class Groundhog:
    def __init__(self, n):
        self.period = n
        self.history = {}
        self.deviations = []
        self.switchs = []
        self.epoch = 0
        self.lastChange = self.relative_change()

    def end(self):
        if len(self.history) < self.period:
            return 84
        try:
            if not self.history[self.epoch]:
                print("No values entered.")
                return False
            values = self.weirdest_values()
            print("Global tendency switched %d times" % len(self.switchs))
            print("5 weirdest values are %s" % values)
            return 0
        except KeyError:
            return 84

    def insert(self, value):
        self.epoch += 1
        self.history[self.epoch] = value

    def temp_average(self):
        if self.epoch <= self.period:
            return float('nan')
        differences = [self.history[i] - self.history[i - 1] for i in range(self.epoch - self.period + 1, self.epoch + 1)]
        differences = [d if d >= 0 and not math.isnan(d) else 0 for d in differences]
        return sum(differences) / len(differences) if differences else float('nan')

    def relative_change(self):
        if self.epoch <= self.period:
            return float('nan')
        if self.history[self.epoch - self.period] == 0:
            return 0
        change = (self.history[self.epoch] - self.history[self.epoch - self.period]) / self.history[self.epoch - self.period]
        return change

    def std_deviation(self):
        if self.epoch < self.period:
            return float('nan')
        values = [self.history[i] for i in range(self.epoch - self.period + 1, self.epoch + 1)]
        average = sum(values) / self.period
        return math.sqrt(sum((x - average) ** 2 for x in values) / self.period)

    def detect_switch(self):
        if self.epoch <= self.period:
            return False
        return self.relative_change() * self.lastChange < 0

    def rate(self, changes):
        return [abs(c) if not math.isnan(c) else 0 for c in changes]

    def weirdest_values(self, n=5):
        if self.epoch < self.period:
            return []
        indexed_changes = list(enumerate(self.deviations))
        rates = self.rate(self.deviations)
        sorted_changes = sorted(indexed_changes, key=lambda x: rates[x[0]], reverse=True)
        sorted_indices = [i for i, _ in sorted_changes if not math.isnan(self.deviations[i])]
        if len(sorted_indices) < n:
            return [self.history[i + 1] for i in sorted_indices]
        return [self.history[i + 1] for i in sorted_indices[:n]]

    def display(self):
        change = self.relative_change()
        deviation = self.std_deviation()
        self.deviations.append(deviation)
        print("g={:.2f}\tr={:.0f}%\ts={:.2f}".format(self.temp_average(), change * 100, deviation), end="")
        if self.detect_switch():
            self.switchs.append(self.epoch)
            print("\ta switch occurs")
        else:
            print("")
        self.lastChange = change

def groundhog(n):
    groundhog = Groundhog(n)
    while True:
        try:
            entry = input()
            if entry == "STOP":
                return groundhog.end()
            value = float(entry)
        except:
            return 84
        groundhog.insert(value)
        groundhog.display()

def help():
    print("SYNOPSIS")
    print("\t./groundhog period")
    print("DESCRIPTION")
    print("\tperiod\tthe number of days defining a period")

def main():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        return help()
    if len(sys.argv) != 2:
        help()
        return 84
    try:
        n = int(sys.argv[1])
    except ValueError:
        return 84
    if n <= 0:
        return 84
    return groundhog(n)

if __name__ == "__main__":
    sys.exit(main())
