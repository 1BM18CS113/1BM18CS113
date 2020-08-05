class myThread implements Runnable{
    int i; Thread t;
    myThread(int i){
        this.i = i;
        t = new Thread(this);
        t.start();        
    }

    public void run(){
        try{
            if(i<=5){
            myThread obj = new myThread(i+1);
            t.sleep(5000/i);
            System.out.println("Hello "+i);
            }
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
    }
}

class Main{
    public static void main(String[] args){
        myThread obj = new myThread(1);
    }
}
