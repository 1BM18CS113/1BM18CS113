import java.util.*;

class customer{
	private String customer_no, customer_name;
	private int Qty;
	private double Discount, Netprice, Price, TotalPrice;
	
	customer(){
		customer_no ="";
		customer_name = "";
		Qty = 0;
		Discount =0;
		Netprice = 0;
		TotalPrice = 0;
		Price = 0;
	}
	
	void input(){
		
		Scanner scan = new Scanner(System.in);
		
		customer_no = scan.nextLine();
		customer_name = scan.nextLine();
		Qty = scan.nextInt();
		Price = scan.nextDouble();
		
		TotalPrice = Price * Qty;
		
	}
	
	void caldiscount(){
		if(TotalPrice>=50000){
			Discount = 0.25*TotalPrice;
			Netprice = TotalPrice - Discount;
		}
		else if(TotalPrice>=25000){
			Discount = 0.1*TotalPrice;
			Netprice = TotalPrice - Discount;
		}
		else{
			System.out.println("No Discount Applicable");
		}
	}
	
	void show(){
		
		System.out.println("The details are : ");
		System.out.println("NAME :" +customer_name);
		System.out.println("Number :" +customer_no);
		System.out.println("Price before Discount  = "+ TotalPrice);
		System.out.println("Discount : "+Discount);
		System.out.println("Net Price : "+Netprice);
	}
	
}

class customermain{
	
	public static void main(String args[]){
		System.out.println("Enter n");
		Scanner vs = new Scanner(System.in);
		int n = vs.nextInt();
		customer arr[] = new customer[n];
		
		for(int i=0; i<n; i++){
			arr[i] = new customer();
			arr[i].input();
			arr[i].caldiscount();
			arr[i].show();
		}
	}
}