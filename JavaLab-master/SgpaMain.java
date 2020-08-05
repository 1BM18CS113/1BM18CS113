import java.util.*;    

class SgpaMain{

	public static void main(String args[]){
	
		System.out.println("Enter the number of subjects");
		Scanner vs = new Scanner(System.in);		
		int n = vs.nextInt();		
		SgpaCalc s1 = new SgpaCalc(n);
		
		System.out.println("Enter the marks and subjects");		
		s1.input();
		
		s1.grades_calc();
		s1.actual_sgpa();
		
		System.out.println("YOUR SGPA IS " + s1.display());
	
		
	}

}


class SgpaCalc{
	
	int marks[];
	int credits[];
	int grades[];
	int n;
	int total_credits = 0;
	double sgpa_value = 0;
	
	SgpaCalc(int n){
		
		this.marks = new int[n];
		this.credits = new int[n];
		this.grades = new int[n];	
		this.n = n;	
	}
	
	
	void input(){
		Scanner vs = new Scanner(System.in);
		
		for(int i = 0; i<n; i++){		
			System.out.println("Marks of Subject " + (i+1));
			marks[i] = vs.nextInt();
			
			System.out.println("Credits of Subject " + (i+1));
			credits[i] = vs.nextInt();
			total_credits += credits[i];
		}
	}
	
	void grades_calc(){
	
		for(int i = 0; i<n; i++){
			int m = marks[i];
			
				if(m>=90)
					grades[i] = 10;
				else if(m>=75)
					grades[i] = 9;
				else if(m>=65)
					grades[i] = 8;
				else if(m>=55)
					grades[i] = 5;
				else if(m>=40)
					grades[i] = 4;
				else
					grades[i] = 0;
				
		}
	
	}
	
	void actual_sgpa(){
		int sgpa_temp = 0;
		for(int i=0; i<n; i++){
			sgpa_temp += grades[i]*credits[i];		
		}
		
		sgpa_value = (double)(sgpa_temp)/(total_credits);
	
	}
	
	double display(){
		return sgpa_value;
	}	
}
