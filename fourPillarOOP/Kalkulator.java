package fourPillarOOP;


class InnerKalkulator {

    int hasil;
    public void InnerKalkulator(){
        System.out.println("sedang membuat class");
    }
    public  void tambah(int a, int b ){
        this.hasil = a + b ;
        System.out.println(this.hasil);
    }
}



public class Kalkulator {

    public static void main(String args[]){
        InnerKalkulator math  = new InnerKalkulator();
        math.tambah(1,3);
    }
}