import java.util.Scanner;

class insuf_bal_exception extends Exception{
    String name;
    insuf_bal_exception(String name){
        this.name = name;
    }

    public String toString(){
        return name;
    }
}


class Bank{
        int acno, bal = 2000;
        String name;

        Bank(int acno, String name){
            this.acno = acno;
            this.name = name;
        }

        void deposit(int amt){
            bal += amt;
            System.out.println("Deposit Successful");
        }

        void withdraw(int amt)throws insuf_bal_exception{
            if(bal<2000){
                throw new insuf_bal_exception("INSUFFICIENT BALANCE");
            }
            else if(bal-amt<2000){
                System.out.println("Max Amount you can withdraw is "+(bal-2000));
                throw new insuf_bal_exception("INSUFFICIENT BALANCE");
                
            }
            else{
                bal -= amt;
                System.out.println("Withdrawal Successful");
            }
        }

        int balance(){
            return bal;
        }
}

class BankMain{
    public static void main(String[] args){
        Scanner vs = new Scanner(System.in);
        int choice = 0;

        String name = vs.nextLine();
        int acno = vs.nextInt();
        
        Bank obj = new Bank(acno, name);
        do{
            System.out.println("1. Deposit    2. Withdraw    3. Display Current Balance    4. EXIT");
            choice = vs.nextInt();
            switch(choice){
                case 1:
                    System.out.println("ENTER AMOUNT");
                    int amt = vs.nextInt();
                    obj.deposit(amt);
                break;

                case 2:
                    System.out.println("ENTER AMOUNT");
                    amt = vs.nextInt();
                    try{
                        obj.withdraw(amt);
                    }
                    catch(insuf_bal_exception ibe){
                        System.out.println(ibe);
                    }
                    
                break;

                case 3:
                    System.out.println("Current BALANCE = " + obj.balance());
                break;
            }

        }while(choice != 4);
        
    }
}