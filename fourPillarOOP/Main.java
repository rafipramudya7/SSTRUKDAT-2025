package fourPillarOOP;

// menggunakan public
class Account {
    public double balance;
}

//menggunakan  private
class SecAccount {
    private double balance;
    public void setBalance(double balance){
        this.balance = balance;
    }
    public double output(){
        return balance;
    }
    
}
public class Main {
    public static void main(String[] args){
        Account acc = new Account();
        acc.balance = 10000; //Bisa diubah di luar class account karena public
        SecAccount akun = new SecAccount();
        akun.setBalance(50000);
        System.out.println(acc.balance);
        System.out.println(akun.output());
    }
    
}