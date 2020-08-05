import java.util.*;

abstract class Shape{
	int a;
	
	Shape(int x){
		a=x;
	}
	Shape(){}
	
	abstract void printArea();
}



class Rectangle extends Shape{
		int b;
		Rectangle(int x, int y){
		super(x);
		b = y;
	}
	void printArea(){
		System.out.println(a*b);
	}
}




class Triangle extends Shape{
		int b ;
		Triangle(int x, int y){
		super(x);
		b=y;
	}
	void printArea(){
		System.out.println(((double)0.5*a*b));
	}
}

class Circle extends Shape{
		Circle(int x){
		super(x);
	}
	void printArea(){
		System.out.println((double)3.14*a*a);
	}
}


class Shape_Main{
	public static void main(String args[]){
		int l, b, choice;
		Scanner vs = new Scanner(System.in);
		do{
			System.out.println("1. Rectangle\n2. Triangle\n3. Circle\n5. Exit");
			
			choice = vs.nextInt();
			
			switch(choice){
				case 1:		
				System.out.println("Enter l and b");	
				l = vs.nextInt();
				b = vs.nextInt();
				Rectangle obj1 = new Rectangle(l, b);
				obj1.printArea();
				break;
				
				case 2:		
				System.out.println("Enter b and h");	
				l = vs.nextInt();
				b = vs.nextInt();
				Triangle obj2 = new Triangle(l, b);
				obj2.printArea();
				break;
				
				case 3:		
				System.out.println("Enter r");	
				l = vs.nextInt();
				Circle obj3 = new Circle(l);
				obj3.printArea();
				break;
				
			}
		}while(choice !=5);
	}
}




