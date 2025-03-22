import random

nama_peserta = [
    "regy", "ahdan", "aji", "alfawahid", "ghina", "dika", "aqilah", "aska", "sherly", "della", "denis", "dina", "diva",
    "erlangga", "fadjar", "fatur", "harya", "ibnu", "richad", "abidzar", "haiklar", "faiz", "naufal", "dayat", "sasi", 
    "maulana", "rivaldy", "sahrul", "sandi", "teguh", "yose"
]

jumlah_kelompok = 4
random.shuffle(nama_peserta)

kelompok = {f"Kelompok {i+1}": [] for i in range(jumlah_kelompok)}

for i, nama in enumerate(nama_peserta):
    kelompok[f"Kelompok {(i % jumlah_kelompok) + 1}"].append(nama)

for k, v in kelompok.items():
    print(f"{k}: {', '.join(v)}")
    