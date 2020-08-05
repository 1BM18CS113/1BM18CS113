/*class book - 4 memebers: name, authour, price, no of pages. 
include a constructor to set the values for the members
include methods to set and get the details of the objects. 
Iclude toString method that displays complete details of the book. wap to create n bok objetcs*/


import java.util.*;

class Book{
	String name, author;
	int num_pages;
	double price;
	
	
	Book(){
		name = "";
		author = "";
		num_pages = 0;
		price = 0.0;
		
	}
	
	
	
	void get_data(){
		Scanner vs = new Scanner(System.in);
		System.out.println("Enter name, author, no of pages, price");
		
		System.out.print("NAME : ");
		name = vs.nextLine();
		System.out.print("AUTHOR : ");
		author = vs.nextLine();
		System.out.println("Number Of Pages : ");
		num_pages = vs.nextInt();
		price = vs.nextDouble();
	}
	
	
	public String toString(){
		return (name + " " + author + " " + Integer.toString(num_pages) + " " + Double.toString(price));		
	}
}


class BookMain{
	public static void main(String args[]){
		
		Scanner vs = new Scanner(System.in);
		System.out.println("Enter the number of Books");
		int n = vs.nextInt();
		
		Book obj[] = new Book[n];
		
		for(int i=0; i<n;i++){
			obj[i] = new Book();
			obj[i].get_data();
			System.out.println(obj[i].toString());	
			
		}
	}
}



