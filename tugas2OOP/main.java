import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

abstract class Identitas {
    private String Nrp;
    private String Nama;
    private String platNomor;
    private String nfcId;

    public Identitas(String nrp, String nama, String id, String platNomor) {
        this.Nrp = nrp;
        this.platNomor = platNomor;
        nfcId = id;
        this.Nama = nama;
    }

    public String getNama() {
        return Nama;
    }

    public String getId() {
        return nfcId;
    }

    public String platNomor() {
        return platNomor;
    }

    public abstract String getInfo();
}

class Motor {
    private String platNomor;
    private String jenis;

    public Motor(String plat, String Jenis) {
        platNomor = plat;
        jenis = Jenis;
    }

    public String getPlatNomor() {
        return platNomor;
    }

    public String getJenis() {
        return jenis;
    }
}

class Mahasiswa extends Identitas {

    private String Prodi;
    private Motor Kendaraan;
    private String nama;
    private String nrp;
    private String nfcId;

    private List<String> riwayatAbsen = new ArrayList<>();

    public Mahasiswa(String nrp, String nama, String id, String prodi, Motor motor) {
        super(nrp, nama, id, motor.getPlatNomor());
        this.Prodi = prodi;
        this.nama = nama;
        this.nrp = nrp;
        this.nfcId = id;
        Kendaraan = motor;
    }

    @Override
    public String getInfo() {
        return String.format(

                "Nama         : %s\n" +
                        "NRP          : %s\n" +
                        "Prodi        : %s\n" +
                        "NFCid        : %s\n" +
                        "Plat Motor   : %s\n" +
                        "Merk Motor   : %s\n" +
                        "Absensi      : %s\n",
                nama, nrp, Prodi, nfcId, Kendaraan.getPlatNomor(), Kendaraan.getJenis(),
                riwayatAbsen.isEmpty() ? "Belum ada" : String.join(", ", riwayatAbsen));
    }

    public void tambahAbsen(String matkul) {
        riwayatAbsen.add(matkul);
    }
}

public class main {
    static List<Mahasiswa> dataMahasiswa = new ArrayList<>();

    static Mahasiswa cariMahasiswa(String id) {
        for (Mahasiswa m : dataMahasiswa) {
            if (m.getId().equalsIgnoreCase(id))
                return m;
        }
        return null;
    }

    static Scanner sc = new Scanner(System.in);

    static void daftarMahasiswa() {
        System.out.println("-------------------------------------------");
        System.out.println("PENDAFTARAN MAHASISWA");
        System.out.println("-------------------------------------------");

        System.out.print("Masukan nrp :");
        String nrp = sc.nextLine().trim();

        System.out.print("Masukan nama :");
        String nama = sc.nextLine().trim();

        System.out.print("Masukan prodi: ");
        String prodi = sc.nextLine().trim();

        System.out.print("Masukan NFC ID: ");
        String nfcId = sc.nextLine().trim();

        System.out.print("Masukan Plat Motor: ");
        String platNomor = sc.nextLine().trim();

        System.out.print("Masukan Merk Motor: ");
        String merkMotor = sc.nextLine().trim();

        Motor motor = new Motor(platNomor, merkMotor);
        dataMahasiswa.add(new Mahasiswa(nrp, nama, nfcId, prodi, motor));
        System.out.println("Data berhasil ditambahkan");
    }

    static void tampilkanData() {
        if (dataMahasiswa.isEmpty()) {
            System.out.println("Data masih kosong");
            return;
        }
        for (Mahasiswa m : dataMahasiswa) {
            System.out.println(m.getInfo());
        }
    }

    static void absensi() {
        System.out.print("Masukan NFC ID: ");
        String nfcId = sc.nextLine().trim();
        System.out.print("Masukan Matkul: ");
        String matkul = sc.nextLine().trim();

        Mahasiswa mahasiswa = cariMahasiswa(nfcId);
        if (mahasiswa == null) {
            System.out.println("Data tidak ditemukana");
            return;

        }
        mahasiswa.tambahAbsen(matkul);

        System.out.println("berhasil absen di matkul " + matkul);
    }

    static void keluarGate() {
        System.out.print("Masukan NFC ID: ");
        String nfcId = sc.nextLine().trim();
        System.out.print("Masukan Plat Nomor: ");
        String platNomor = sc.nextLine().trim();

        Mahasiswa mahasiswa = cariMahasiswa(nfcId);
        if (mahasiswa == null) {
            System.out.println("Credential Palsu kamu pencuri ya...");
        }
        if (mahasiswa.platNomor().equalsIgnoreCase(platNomor)) {
            System.out.println("Berhasil Keluar Palang ke buka");
        } else {
            System.out.println("Credential Palsu kamu pencuri ya...");
        }
    }

    public static void main(String[] args) {
        System.out.println();
        System.out.println("  ====================================================");
        System.out.println("    SISTEM INFORMASI MAHASISWA — PARKIR & ABSENSI");
        System.out.println("  ====================================================");

        while (true) {
            System.out.println();
            System.out.println("  MENU UTAMA");
            System.out.println("  ====================================================");
            System.out.println("  1. Daftar Mahasiswa & Motor");
            System.out.println("  2. Tampilkan Semua Data");
            System.out.println("  3. Absensi");
            System.out.println("  4. Keluar Gate Parkir  (NFC + Plat Nomor)");
            System.out.println("  0. Exit");
            System.out.println("  ====================================================");
            System.out.print("Masukan pilihan: ");
            String pilihan = sc.nextLine().trim();
            switch (pilihan) {
                case "1":
                    daftarMahasiswa();
                    break;
                case "2":
                    tampilkanData();
                    break;
                case "3":
                    absensi();
                    break;
                case "4":
                    keluarGate();
                    break;
                case "0":
                    System.out.println("  Sampai jumpa!");
                    sc.close();
                    return;
                default:
                    System.out.println("  [!] Pilihan tidak valid.");
            }
        }

    }
}

// 2.1 no 2