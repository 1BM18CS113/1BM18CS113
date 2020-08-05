

import java.util.*;
import cie.Student;
import cie.Internal;
import see.External;

public class FileMain{
	public static void main(String args[]){
		Scanner vs = new Scanner(System.in);
		System.out.println("Enter number of students:");
		int n = vs.nextInt();
		
		Internal objarri[] = new Internal[n];
		External objarre[] = new External[n];
		
		for(int j = 0; j<n; j++){
			System.out.println("STUDENT "+ (j+1));
			objarre[j] = new External();
			objarre[j].getdata();
			objarri[j] = new Internal();
			objarri[j].getdata();
			
			
			for(int i = 0; i<5; i++){
			System.out.println("Total Marks in subject "+(i+1) +" = "+(objarre[j].see_marks[i]+objarri[j].cie_marks[i]));
		
			}	
		}
		
				
		
		
	}
}
