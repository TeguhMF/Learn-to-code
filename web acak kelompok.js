let namaPeserta = [];

function acakKelompok() {
    const namaInput = document.getElementById('namaInput').value;
    const jumlahKelompokInput = document.getElementById('jumlahKelompok');
    const jumlahKelompok = parseInt(jumlahKelompokInput.value);
    
    if (!namaInput || !jumlahKelompok) {
        alert('Masukkan nama dan jumlah kelompok terlebih dahulu!');
        return;
    }

    namaPeserta = namaInput.split(',').map(nama => nama.trim()).filter(nama => nama.length > 0);

    if (namaPeserta.length < jumlahKelompok) {
        alert('Jumlah nama harus lebih besar atau sama dengan jumlah kelompok!');
        return;
    }

    const acakNama = [...namaPeserta].sort(() => Math.random() - 0.5);
    const hasilKelompok = [];

    for (let i = 0; i < jumlahKelompok; i++) {
        hasilKelompok.push([]);
    }

    for (let i = 0; i < acakNama.length; i++) {
        const kelompokIndex = i % jumlahKelompok;
        hasilKelompok[kelompokIndex].push(acakNama[i]);
    }

    let hasilHTML = '';
    hasilKelompok.forEach((kelompok, index) => {
        hasilHTML += `<h3>Kelompok ${index + 1}</h3>`;
        hasilHTML += `<ul>`;
        kelompok.forEach(nama => {
            hasilHTML += `<li>${nama}</li>`;
        });
        hasilHTML += `</ul>`;
    });

    const hasilKelompokElement = document.getElementById('hasilKelompok');
    hasilKelompokElement.innerHTML = hasilHTML;
    hasilKelompokElement.style.display = 'block';
}

document.getElementById('hasilKelompok').addEventListener('click', () => {
    document.getElementById('hasilKelompok').style.display = 'none';
});