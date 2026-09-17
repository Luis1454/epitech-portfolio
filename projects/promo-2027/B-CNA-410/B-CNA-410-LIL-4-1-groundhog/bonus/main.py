#!/usr/bin/env python3

import math
import sys
import matplotlib.pyplot as plt

class Groundhog:
    def __init__(self, n):
        self.period = n
        self.history = {}
        self.deviations = []
        self.changes = []
        self.switchs = []
        self.filled_areas = []
        self.epoch = 0
        self.lastChange = self.relative_change()
        self.delay = 0.01

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
        self.changes.append(change)
        print("g={:.2f}\tr={:.0f}%\ts={:.2f}".format(self.temp_average(), change * 100, deviation), end="")
        self.visualize()
        if self.detect_switch():
            self.switchs.append(self.epoch)
            print("\ta switch occurs")
        else:
            print("")
        self.lastChange = change

    def visualize(self):
        if self.epoch < self.period:
            return
        if not hasattr(self, 'fig'):
            plt.ion()
            self.fig, self.axes = plt.subplots(3, 1, sharex=True)
            self.line_temp, = self.axes[0].plot(list(self.history.keys()), list(self.history.values()), label="temperature")
            self.line_change, = self.axes[1].plot(list(self.history.keys()), [0]*len(self.history), label="change")
            self.line_deviation, = self.axes[2].plot(list(self.history.keys()), [0]*len(self.history), label="deviation")
            self.red_signal, = self.axes[1].plot([], [], 'ro', label="negative change")
            self.green_signal, = self.axes[1].plot([], [], 'go', label="positive change")
            for ax in self.axes:
                ax.legend(loc='upper left')
                ax.grid()
            plt.show(block=False)
        else:
            self.line_temp.set_ydata(list(self.history.values()))
            self.line_temp.set_xdata(list(self.history.keys()))
            self.line_change.set_ydata(self.changes)
            self.line_change.set_xdata(list(self.history.keys()))
            self.line_deviation.set_ydata(self.deviations)
            self.line_deviation.set_xdata(list(self.history.keys()))

            switches = []
            colors = []

            if self.filled_areas:
                last_filled_switch = self.filled_areas[-1][1]
            else:
                last_filled_switch = None

            start_index = self.switchs.index(last_filled_switch) + 1 if last_filled_switch else 0

            if start_index < len(self.switchs):
                ax = self.axes[1]
                if self.changes[self.switchs[-1]] < 0:
                    ax.scatter(self.switchs[-1] + 1, self.changes[self.switchs[-1]], color='red')
                else:
                    ax.scatter(self.switchs[-1] + 1, self.changes[self.switchs[-1]], color='green')
                for switch in self.switchs[start_index:]:
                    if self.changes[switch] < 0:
                        switches.append(switch)
                        colors.append('green')
                    else:
                        switches.append(switch)
                        colors.append('red')

            for ax in self.axes:
                ax.relim()
                ax.autoscale_view()
            plt.draw()
            plt.pause(0.01)

def groundhog(n, delay=0.01):
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
        groundhog.delay = delay

def help():
    print("SYNOPSIS")
    print("\t./groundhog period delay (in seconds)")
    print("DESCRIPTION")
    print("\tperiod\tthe number of days defining a period")

def main():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        return help()
    if len(sys.argv) != 3:
        help()
        return 84
    try:
        n = int(sys.argv[1])
        delay = float(sys.argv[2])
    except ValueError:
        return 84
    if n <= 0:
        return 84
    return groundhog(n, delay)

if __name__ == "__main__":
    sys.exit(main())
