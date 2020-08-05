class Person{
	String name, address;
	int age;
	
	Person(String _name, String _address, int _age){
		name = _name;
		address = _address;
		age = _age;
	}
}


class Student extends Person{
	double roll_num;
	int sem;
	
	Person(String name, String address, int age, double _roll_num, int _sem){
		super(name, address, age);
		roll_num = _roll_num;
		sem = _sem
		
	}
	
	
}


class Exam extends Student{
	int marks1, marks2;
	Student(String name, String address, int age, double _roll_num, int _sem, int _marks1, int marks2){
		super(String name, String address, int age, double roll_num, int sem);
		marks1 = _marks1;
		marks2 = _marks2
	}
	double avg = (marks1+marks2)/2;
	System.out.println("Average is " + avg);
}



class StudentMain{
	public static void main(String args[]){
		Scanner vs = new Scanner(System.in);
		System.out.println("Enter the Name, Address, Age, Roll Number, Sem, marks1, marks2");
		String name = vs.nextLine();
		String address = vs.nextLine();
		int age = vs.nextInt();
		
	}
}
