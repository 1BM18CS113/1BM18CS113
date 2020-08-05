import java.util.Scanner;

class WrongAgeException extends Exception{
	String name;
	WrongAgeException(String _name){
		name = _name;
	}
	
	public String toString(){
		return name;
	}

}


class Father{
	int f_a;
	Father(int age){
		f_a = age;
		try{
			if(age<0){
				throw new WrongAgeException("Father's age less than zero");
			}
					
		}
		catch(WrongAgeException wa1){
			System.out.println(wa1);
		}
		
	}
}


class Son extends Father{
	int s_a;
	Son(int fage, int sage)throws WrongAgeException{
		super(fage);		
		s_a = sage;
		if(f_a<=s_a){
			throw new WrongAgeException("Father's age less than or equal to sons");
		}
		if(s_a<0){
			System.out.println("Sons's age less than 0");
		}	
	
	}
	
}


class except{
	public static void main(String args[]){
		int f=0, flag = 0, s=0;
		Scanner vs = new Scanner(System.in);
		
		
		do{
			flag = 0;
			
			try{
				System.out.println("Enter fathers age");
				f = vs.nextInt();
				if(f<0){
					throw new WrongAgeException("FATHERS AGE LESS THAN 0");
				}		
			}
			catch(WrongAgeException fa2){
				System.out.println(fa2);
				flag = 1;
				continue;
			}
		}while(flag == 1);
		
		do{
			
			flag = 0;
			// THIS IS US
			try{
				System.out.println("Enter Sons age");
				s = vs.nextInt();
				if(s<0){
					throw new WrongAgeException("Sons AGE LESS THAN 0");
				}		
			}
			catch(WrongAgeException sa2){
				System.out.println(sa2);
				flag = 1;
				continue;
			}
		}while(flag == 1);
			
			
			//This is us
			
			try{
				Son obj = new Son(f, s);
			}
			catch(WrongAgeException wa){
				System.out.println(wa);
			}		
		
	}
}
