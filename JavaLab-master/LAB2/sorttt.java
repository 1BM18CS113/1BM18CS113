class Main{
    public static void main(String[] args) {
        int array[] = {3, 2, 7, 5, 2, 5};
        int array1[] = {3, 2, 7, 5, 2, 5};


        myThread obj = new myThread(array1, array.length);
        for(int i = 0; i< array.length; i++){
            for(int j =0; j<i;j++){
                if(array[j+1]<array[j]){
                    int temp = array[j];
                    array[j] = array[j+1] ;
                    array[j+1] = temp;
                }
            }
        }
        System.out.println("The ascending list is ");
        for(int i = 0; i<array.length;i++){
            System.out.println(array[i]);
        }
        
        
    }
}


class myThread implements Runnable{
    int a[];
    int l;
    myThread(int array1[], int length){
        l= length;
        //a = new int[l];
        a = array1;
        Thread t =new Thread(this);
        t.start();
    }

    public void run(){
        
        System.out.println("-------------------------------"+a[0]);
        for(int i = 0; i< l; i++){
            for(int j =0; j<i;j++){
                if(a[j+1]>a[j]){
                    int temp = a[j];
                    a[j] = a[j+1] ;
                    a[j+1] = temp;
                }
            }
        }
        System.out.println("The Descending list is ");
        for(int i = 0; i<l;i++){
            System.out.println(a[i]);
        }
    }
}
