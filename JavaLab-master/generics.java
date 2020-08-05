class Test<T, U>{
    
    T obj;
    U obju;
    
    Test(T _obj, U _obju){
        obj = _obj;
        obju = _obju;
    }
    
    T print1(){
        return obj;
        
    }
    U print2(){
        return obju;
    }
    
}

class Main{
    
    public static void main (String[] args) {
        Test<Integer, String> obj = new Test<Integer, String>(100, "HELLO");
        int x = obj.print1();
        String y = obj.print2();
        System.out.println(x +"  "+y);
        
        
        Test<Character, Double> obj2 = new Test<Character, Double>('C', 123.4);
        char xx = obj2.print1();
        double yy = obj2.print2();
        System.out.println(xx +"  "+yy);
    }
}

