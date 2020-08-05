class myThread implements Runnable{
    Thread t;
    myThread(){
        t = new Thread(this);
        t.start();
    }

    public void run(){
        try{
            for(;;){
                System.out.println("BMS College Of Engineering");
                t.sleep(10000);
            }
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
    }
}

class Main{
    public static void main(String[] args){
        myThread obj = new myThread();
        try{
            for(;;){
            System.out.println("CSE");
            Thread.sleep(2000);
            }
        }
        catch(InterruptedException ie){
            System.out.println(ie);
        }
    }
}
