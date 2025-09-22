import numpy as np
import matplotlib.pyplot as plt

# Fungsi untuk menghasilkan bentuk hati
def heart_shape(t):
    x = 16 * np.sin(t) ** 3
    y = 13 * np.cos(t) - 5 * np.cos(2*t) - 2 * np.cos(3*t) - np.cos(4*t)
    return x, y

# Generate points untuk bentuk hati
t = np.linspace(0, 2*np.pi, 1000)
x, y = heart_shape(t)

# Membuat plot
fig, ax = plt.subplots(figsize=(10, 9))
ax.plot(x, y, 'r-', linewidth=3)
ax.fill(x, y, 'pink', alpha=0.3)

# Menambahkan teks
ax.text(0, 0, "I Love You", fontsize=40, fontweight='bold',
        ha='center', va='center', color='darkred')

# Mengatur batas plot
ax.set_xlim(-20, 20)
ax.set_ylim(-15, 15)

# Menghilangkan axis
ax.axis('off')

plt.tight_layout()
plt.savefig('i_love_you_heart.png', dpi=300)
plt.show()