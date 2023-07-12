#!/usr/bin/env python3

import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import csv

sns.set()

def geomean(x):
    return np.exp(np.log(x).mean())

comp_num_values = []
comp_cycles = []
comp_insns = []
with open('benchmark_compress.csv') as f:
    reader = csv.reader(f)
    for row in reader:
        comp_num_values.append(float(row[0]))
        batch_size = float(row[1])
        comp_cycles.append(float(row[2]) / batch_size)
        comp_insns.append(float(row[3]) / batch_size)

dec_num_values = []
dec_cycles = []
dec_insns = []
with open('benchmark_decompress.csv') as f:
    reader = csv.reader(f)
    for row in reader:
        dec_num_values.append(float(row[0]))
        batch_size = float(row[1])
        dec_cycles.append(float(row[2]) / batch_size)
        dec_insns.append(float(row[3]) / batch_size)

print(f'Compression Geomean: {geomean(comp_cycles)} cycles, {geomean(comp_insns)} insns')
print(f'Decompression Geomean: {geomean(dec_cycles)} cycles, {geomean(dec_insns)} insns')

fig_cyc = plt.subplot(2, 1, 1)
fig_insn = plt.subplot(2, 1, 2)

fig_cyc.plot(comp_num_values, comp_cycles, label='Compression')
fig_cyc.plot(dec_num_values, dec_cycles, label='Decompression')
fig_cyc.set_xlabel('Distinct Values')
fig_cyc.set_ylabel('Cycles/value')
fig_cyc.set_ylim(bottom=0)
fig_cyc.legend()

fig_insn.plot(comp_num_values, comp_insns, label='Compression')
fig_insn.plot(dec_num_values, dec_insns, label='Decompression')
fig_insn.set_xlabel('Distinct Values')
fig_insn.set_ylabel('Insns/value')
fig_insn.set_ylim(bottom=0)
fig_insn.legend()

plt.show()

