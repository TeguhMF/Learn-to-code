import java.util.Scanner;

public class newJavaFile {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Masukkan jumlah elemen: ");
            int n = scanner.nextInt();
            
            int[] angka = new int[n];
            
            System.out.println("Masukkan " + n + " angka:");
            for (int i = 0; i < n; i++) {
                System.out.print("Elemen ke-" + (i + 1) + ": ");
                angka[i] = scanner.nextInt();
            }
            
            System.out.println("Angka yang dimasukkan:");
            for (int num : angka) {
                System.out.print(num + " ");
            }
            System.out.println();
            
            int jumlah = 0;
            for (int num : angka) {
                jumlah += num;
            }
            
            double rataRata = (double) jumlah / n;
            
            System.out.println("Jumlah: " + jumlah);
            System.out.println("Rata-rata: " + rataRata);
            
            System.out.print("Masukkan angka yang ingin dicari: ");
            int cari = scanner.nextInt();
            boolean ditemukan = false;
            
            for (int i = 0; i < n; i++) {
                if (angka[i] == cari) {
                    System.out.println("Angka " + cari + " ditemukan pada indeks " + i);
                    ditemukan = true;
                    break;
                }
            }
            
            if (!ditemukan) {
                System.out.println("Angka " + cari + " tidak ditemukan dalam array.");
            }
        }
    }
}
