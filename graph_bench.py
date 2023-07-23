#!/usr/bin/env python3

import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import csv

sns.set()

def geomean(x):
    return np.exp(np.log(x).mean())

def read_benchmark_data(filename):
    num_values = []
    cycles = []
    insns = []
    with open(filename) as f:
        reader = csv.reader(f)
        for row in reader:
            num_values.append(float(row[0]))
            batch_size = float(row[1])
            cycles.append(float(row[2]) / batch_size)
            insns.append(float(row[3]) / batch_size)
    return num_values, cycles, insns


comp_num_values, comp_cycles, comp_insns = read_benchmark_data('benchmark_compress.csv')
comp_num_values_bp, comp_cycles_bp, comp_insns_bp = read_benchmark_data('benchmark_compress_bitpack.csv')
dec_num_values, dec_cycles, dec_insns = read_benchmark_data('benchmark_decompress.csv')
dec_num_values_bp, dec_cycles_bp, dec_insns_bp = read_benchmark_data('benchmark_decompress_bitpack.csv')

print(f'UP Compression Geomean: {geomean(comp_cycles)} cycles, {geomean(comp_insns)} insns')
print(f'BP Compression Geomean: {geomean(comp_cycles_bp)} cycles, {geomean(comp_insns_bp)} insns')

print(f'UP Decompression Geomean: {geomean(dec_cycles)} cycles, {geomean(dec_insns)} insns')
print(f'BP Decompression Geomean: {geomean(dec_cycles_bp)} cycles, {geomean(dec_insns_bp)} insns')

fig_cyc = plt.subplot(2, 1, 1)
fig_insn = plt.subplot(2, 1, 2)

fig_cyc.plot(comp_num_values, comp_cycles, label='Ultrapack Compression')
fig_cyc.plot(dec_num_values, dec_cycles, label='Ultrapack Decompression')
fig_cyc.plot(comp_num_values_bp, comp_cycles_bp, label='Bitpack Compression')
fig_cyc.plot(dec_num_values_bp, dec_cycles_bp, label='Bitpack Decompression')

fig_cyc.set_xlabel('Distinct Values')
fig_cyc.set_ylabel('Cycles/value')
fig_cyc.set_ylim(bottom=0)
fig_cyc.legend()

fig_insn.plot(comp_num_values, comp_insns, label='Ultrapack Compression')
fig_insn.plot(dec_num_values, dec_insns, label='Ultrapack Decompression')
fig_insn.plot(comp_num_values_bp, comp_insns_bp, label='Bitpack Compression')
fig_insn.plot(dec_num_values_bp, dec_insns_bp, label='Bitpack Decompression')

fig_insn.set_xlabel('Distinct Values')
fig_insn.set_ylabel('Insns/value')
fig_insn.set_ylim(bottom=0)
fig_insn.legend()

plt.show()

