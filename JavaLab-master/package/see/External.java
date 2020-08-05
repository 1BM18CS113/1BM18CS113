
package see;

import java.util.Scanner;
import cie.Student;

public class External extends Student{
	public  double see_marks[] = new double[5];
	Scanner vs  = new Scanner(System.in);
	
	
	public void getdata(){
		System.out.println("Enter Name");
		name = vs.nextLine();
		System.out.println("Enter usn");
		usn = vs.nextInt();
		System.out.println("Enter sem");
		sem = vs.nextInt();
		
		System.out.println("SEE MARKS");
		for(int i =0; i<5;i++){
			System.out.println("Enter marks of subject"+ (i+1));
			see_marks[i] = vs.nextDouble();
			see_marks[i] = (see_marks[i])/2;
		}
	}
	
	
} 
