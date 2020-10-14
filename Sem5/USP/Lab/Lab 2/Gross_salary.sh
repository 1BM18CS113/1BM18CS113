echo "Enter basic salary: "
read bsal

gross_salary=$((bsal+((bsal/100)*30)+(bsal/100)*20))
echo "Gross salary is $gross_salary"
