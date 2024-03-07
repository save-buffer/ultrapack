#!/usr/bin/env python3

import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import csv

sns.set()

def geomean(x):
    return np.exp(np.log(x).mean())

num_values = []
bpv = []
normal_bpv = []
savings = []
with open('bpv.csv') as f:
    reader = csv.reader(f)
    for row in reader:
        num_values.append(float(row[0]))
        bpv.append(float(row[1]))
        normal_bpv.append(float(row[2]))
        savings.append(float(row[3]))

print(f'Percent savings geomean: {geomean([x for x in savings if x != 0.0])}')

ax1 = plt.subplot(2, 1, 1)
ax2 = plt.subplot(2, 1, 2)
ax1.plot(num_values, bpv, label='bits per value')
ax1.plot(num_values, normal_bpv, label='normal bits per value')
ax1.set_xlabel('Distinct Values')
ax1.legend()

ax2.plot(num_values, savings, label='percent savings')
ax2.set_xlabel('Distinct Values')
ax2.legend()

plt.show()
