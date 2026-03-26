package fourPillarOOP;


interface terbang {
    int power=100;


    default void aksi(){
        System.out.print("melaklukan gerakan terbang");
    }
    void kurangBahanBakar();

    
}

class burung implements terbang{
    String nama;
    int kekuatan = power;
    void hewan(){
        System.out.println("menginisiasi hewan");
    }
    void isiNama(String namaAnimal){
        this.nama = namaAnimal ;
    }
    @Override
    public void kurangBahanBakar(){
        this.kekuatan -= 1;
        System.out.println("kekuatan tinggal" + this.kekuatan);
    }
}
public class intraface {
    public static void main(String args[]){


    }
}
