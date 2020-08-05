import java.util.*;
class Shape{
	int a, b;
	Shape(int x, int y){
		a = x;
		b = y;
	}
	void printArea(){}
}

class Rectangle extends Shape{
	Rectangle(int l, int _b){
		super(l, _b);
	}
	void printArea(){
		System.out.println("AREA IS = "+ a*b);
		}
}


class Triangle extends Shape{
	Triangle(int _b, int h){
		super(_b, h);
	}
	void printArea(){
		System.out.println("AREA IS  = "+(double)(0.5*a*b));
	}
}


class Circle extends Shape{
	Circle(int r){
		super(r, r);
	}
	void printArea(){
		System.out.println("AREA IS = "+(double)(3.14*a*a));
	}
}

class ShapeMain{
	public static void main(String args[]){
		Scanner vs = new Scanner(System.in);
		System.out.println("1. Rectangle\n2. Triangle\n3. Circle");
		int n = vs.nextInt();
		
		switch(n){
			case 1:
				
				System.out.println("Enter l and b");
				int l = vs.nextInt();
				int b = vs.nextInt();
				Rectangle obj1 = new Rectangle(l, b);
				obj1.printArea();
				break;
			case 2:
				
				System.out.println("Enter B and H");
				b = vs.nextInt();
				int h = vs.nextInt();
				Triangle obj2 = new Triangle(b, h);
				obj2.printArea();
				break;
			case 3:
				
				System.out.println("Enter r");
				int r = vs.nextInt();
				Circle obj3 = new Circle(r);
				obj3.printArea();
		}
	}
}
