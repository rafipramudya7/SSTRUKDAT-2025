package fourPillarOOP;

class User{
    String nama;
    User(String username){
        this.nama = username;
    }
    
    void output(){
        System.out.println(nama);
    }
}
class Admin extends User{
    Admin(String username){
        super(username);
    }
}

public class Pewarisan{
    public static void main(String[] args){
        Admin developer = new Admin("jokowai");
        developer.output();
    }
}
