package fourPillarOOP;


abstract class User {
    String username;
    User(String username){
        this.username = username;
    }
    abstract void login();
    
}
class Admin extends User {
    Admin(String username){
        super(username);
    }

    @Override
    void login(){
        System.out.println("login menggunakan admin system");
    }
}

class Customer extends User{
    Customer(String username){
        super(username);
    }
    @Override
    void login(){
        System.out.println("login menggunakan system customer");
    }
}

public class Abstraksi {
    public static void main(String[] args){
        User ayah = new Admin("Firdaus");
        User kakak = new Customer("yunandhi");

        ayah.login();
        kakak.login();

    }
}
