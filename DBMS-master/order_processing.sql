 create table customer(custno int,cname varchar(10),city varchar(10),primary key(custno));
 
 create table order1(orderno int,odate date,custno int,ord_amt int,primary key(orderno),foreign key(custno) references customer(custno));
 
  create table item(itemno int,untiprice int,primary key(itemno));
  
  
  create table order_item(orderno int,itemno int,quantity int,primary key(orderno,itemno),foreign key(orderno) references order1(orderno),foreign key(itemno) references item(itemno) on delete cascade);
  
  
  create table warehouse(warehouseno int,city varchar(10),primary key(warehouseno));
  
  
  
 create table shipment(orderno int,warehouseno int,ship_date date,primary key(orderno,warehouseno),foreign key(orderno) references order1(orderno),foreign key(warehouseno) references warehouse(warehouseno));



-- 2:

 insert into customer values(&custno,'&cname','&city');

insert into order1 values(&orderno,'&odate',&custno,&ord_amt);

 insert into item values(&itemno,&unitprice);

insert into order_item values(&orderno,&itemno,&quantity);

insert into warehouse values(&warehouseno,'&city');

insert into shipment values(&orderno,&warehouseno,'&ship_date');


-- 3:

select c.custno,count(*) as No_of_orders,avg(o.ord_amt) as Avg_order_amount from customer c,order1 o where o.custno=c.custno group by c.custno;


-- 4:
select distinct s.orderno from shipment s where not exists((select warehouseno from warehouse where city='Bangalore') minus (select w.warehouseno from shipment w where w.orderno=s.orderno))and exists ( select warehouseno from warehouse where city='Bangalore');



-- 5:

delete from item where itemno=3;