class noargs extends Exception{
    String name;
    noargs(String name){
        this.name = name;
    }

    public String toString(){
        return name;
    }
}



class Student{
    public static void main(String[] args){
        int x = args.length;
        try{
            if(x == 0){
                throw new noargs("NO ARGUMENTS");
            }
            if(Integer.parseInt(args[2]) <0){
                throw new ArithmeticException("NEGATIVE MARKS");
            }
        }
        catch(noargs na){
            System.out.println(na);
        }
        catch(ArithmeticException ae){
            System.out.println(ae);
        }

            
    }
}