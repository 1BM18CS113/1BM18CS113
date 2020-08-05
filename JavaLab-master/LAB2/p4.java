import java.util.Scanner;

interface safe_driving{
    int safe_speed = 80;
    void speed_of_vehicle(int s);
}

class Drive implements safe_driving{
    public void speed_of_vehicle(int s){
        if(s>safe_speed){
            System.out.println("Drive Slow");
        }
        else{
            System.out.println("Safe Driving");
        }
    }
}

class Main{
    public static void main(String[] args){
        Scanner vs = new Scanner(System.in);
        System.out.println("Enter Vehicle Speed");
        int s = vs.nextInt();
        Drive obj = new Drive();
        obj.speed_of_vehicle(s);
    }
}
