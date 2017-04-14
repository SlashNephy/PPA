import matplotlib
import matplotlib.pyplot as plt
import numpy as np

with open("result.txt", "r") as f:
    data = [[y[1], y[2], y[3]] for x in f.readlines() for y in [[eval(z) for z in x.strip("\n").split()]]]

X = np.arange(20, 1246, 1)
Y1, Y2, Y3 = [x[0] for x in data], [x[1] for x in data], [x[2] for x in data]

plt.figure(figsize=(30, 20))

plt.plot(X, Y1, color="black", linewidth=0.5, antialiased=True)
plt.plot(X, Y2, color="red", linewidth=0.5, antialiased=True)
plt.plot(X, Y3, color="blue", linewidth=0.5, antialiased=True)

plt.xlabel("Date", fontsize=10)
plt.ylabel("Price [JPY/EUR]", fontsize=10)
plt.legend(["$x_t$", "$SMA_t^{(5)}$", "$SMA_t^{(20)}$"], prop={"size": 20}, loc=2)

plt.show()
