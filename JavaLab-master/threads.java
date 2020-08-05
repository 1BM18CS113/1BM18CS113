class myThread implements Runnable{
    Thread t;
    myThread(String name){
        t = new Thread(this, name);
    }

    public void run(){
        for(int i = 0; i< 10; i++){
            try{
                System.out.println("BMS College Of Engineering");
                t.sleep(10000);
            }
            catch(InterruptedException ie){
                System.out.println("Thread Woken From sleep");
            }
        }
        
        System.out.println("Exiting "+t);
    }
    
}



class threads{
    public static void main(String args[]){
        //int a=0;
        myThread obj = new myThread("BMS THREAD");

        System.out.println("PReSS ctrl+z to End");

        obj.t.start();
        for(int i = 0; i<10;i++){
            try {
                System.out.println("CSE");
                Thread.sleep(2000);
            } catch (InterruptedException ie2) {
                System.out.println("Thread Woken From sleep");
            }
            

        }


        try {
            obj.t.join();
        } catch (InterruptedException e) {
            System.out.println("Thread Woken From sleep");
        }

        
    }
}