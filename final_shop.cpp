#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

void ClearScreen()
    {
        int n;
        for (n = 0; n < 10; n++)
           cout<<"\n\n\n\n\n\n\n\n\n\n";
    }


class manager;
class employee{
    public:
	    float adhno;
	    string name;
	    char sex;
	    float salary;
	    employee(){
	    	adhno = 0.0;
	    	name = "";
	    	sex = 'M';
	    	salary = 0.0;
	    }
	    employee addemployee(){
	    	employee t;
	    	cout<<"Input Aadhar no:";
	    	cin>>t.adhno;
	    	cout <<"\nInput Name:";
	    	cin>>t.name;
	    	cout <<"\nsex:";
	    	cin >>t.sex;
	    	cout<<"\nSalary:";
	    	cin>>t.salary;
	    	cout<<endl;
	    	return t;
	    }

	    void dispemployee()
	    {
	    	cout<<setiosflags(ios::left)<<setw(9)<<adhno<<"\t"<<setw(12)<<name<<"\t"<<setw(3)<<sex<<"\t"<<setw(6)<<salary<<endl;
	    }

	    bool searchemployee(string temp)
	    {
	    	if(name == temp)
	    	    return true;
	        else
	        	return false;
	    }
	friend class manager;
};
class manager:public employee{
	public:
	    void modsalary(employee& emp)
		{
			float new_sal;
			cout<<"\nEnter the modified salary:";
			cin>>new_sal;
			emp.salary = new_sal;
		}

		manager addemployeem(){
	    	manager t;
	    	cout<<"Input Aadhar no:";
	    	cin>>t.adhno;
	    	cout <<"\nInput Name:";
	    	cin>>t.name;
	    	cout <<"\nsex:";
	    	cin >>t.sex;
	    	cout<<"\nSalary:";
	    	cin>>t.salary;
	    	cout<<endl;
	    	return t;
	    }
		
};

class sales{
    public:
	    int serial_no;
	    float total;
	    string saletype,customer_name;
	    vector<int> quantity;
		vector<float> tax,discount,mrp,amt;
	    vector<string> item_name;
	    sales(){											//Constructor for sales.
	    	serial_no = 0;
	    	total = 0.0;
	    	saletype = "normal";
			customer_name="";
			total=0.0;
			}
	
	sales addsales(int n)									//member function to add a new sale to the list.
	{
		sales t;
		cout<<"Input serial no: ";
		cin>>t.serial_no;
		cout<<"\nCustomer Name:  ";
		cin>>t.customer_name;
		int i=0;
		while(i<n)
		{
			string temp;
			int temp1;
			float temp2;
			
			cout<<"Input details of item "<<i+1<<":\n\n";
			cout<<"Input item name:";
			cin>>temp;
			t.item_name.push_back(temp);
			cout<<"Input mrp:";
			cin>>temp2;
			t.mrp.push_back(temp2);
			cout<<"Input quantity";
			cin>>temp1;
			t.quantity.push_back(temp1);
			cout<<"\nInput tax: ";
			cin>>temp2;
			t.tax.push_back(temp2);
			cout<<"\nInput discount :";
			cin>>temp2;
			t.discount.push_back(temp2);
			i++;
		}

		n=t.item_name.size();
		i=0;
		while(i<n)																//Computing the total price.
		{
			float t1,t2;
			t1=t.mrp[i]+((t.tax[i]*t.mrp[i])/100);
			t2=t.quantity[i]*t1-((t.discount[i]*t.quantity[i]*t1)/100);
			t.amt.push_back(t2);
			i++;
		}	
		for(i=0;i<n;i++)
			t.total=t.total+t.amt[i];
		
		
		return t;
		
		
		}
		
	void dispsales()													//Function to display
	{
		
		cout<<setiosflags(ios::left)<<setw(9)<<serial_no<<"\t"<<setw(13)<<customer_name<<"\t";
		int count = quantity.size(),i = 0;
		while(i<count)
		{
			cout<<setw(9)<<item_name[i]<<setiosflags(ios::left)<<"\t"<<setw(3)<<mrp[i]<<"\t"<<setw(8)<<quantity[i]<<"\t"<<setw(3)<<tax[i]<<"\t"<<setw(8)<<discount[i]<<"\t"<<setw(6)<<amt[i];
			cout<<"\n\t\t\t\t";
			i++;
			
			
		}
		cout<<"\t\t\t\t\t\t\t\t\t"<<total<<"\n";
		
	

	}
	bool searchsales(int a)
	{
		if(serial_no == a)
			return true;
		else	
			return false;
		
		
	}
	
	
	
	
};

class flash_sales:public sales			//flash sales is inherited from sales class.
{					
	public:

	    flash_sales()
	    {
		    saletype="flash sale";			//Here we set saletype to flash sale and disounts 50%.
		    vector<float>discount(10,50);	
	    }		
	    flash_sales addsalesf(int n)									//member function to add a new sale to the list.
	    {
			flash_sales t;
			cout<<"Input serial no: ";
			cin>>t.serial_no;
			cout<<"\nCustomer Name:  ";
			cin>>t.customer_name;
			int i=0;
			while(i<n)
			{
				string temp;
				int temp1;
				float temp2;
				
				cout<<"Input details of item "<<i+1<<":\n\n";
				cout<<"Input item name:";
				cin>>temp;
				t.item_name.push_back(temp);
				cout<<"\nInput Mrp: ";
				cin>>temp2;
				t.mrp.push_back(temp2);
				cout<<"\nInput item quantity: ";
				cin>>temp1;
				t.quantity.push_back(temp1);
				cout<<"\nInput tax: ";
				cin>>temp2;
				t.tax.push_back(temp2);
				temp2 = 50;
				t.discount.push_back(temp2);
				i++;
			}

			n=t.item_name.size();
			i=0;
			while(i<n)																//Computing the total price.
			{
				float t1,t2;
				t1=t.mrp[i]+((t.tax[i]*t.mrp[i])/100);
				t2=t.quantity[i]*t1-((t.discount[i]*t.quantity[i]*t1)/100);
				t.amt.push_back(t2);
				i++;
			}	
			for(i=0;i<n;i++)
				t.total=t.total+t.amt[i];
			
			
			return t;
			
			
			}

	
};

class item{													
    public:
	    float mrp;
	    string name;
	    int present_stock;

	    item(){
	    	mrp = 0.0;
	    	name = "";
	    	present_stock = 0;
	    }
	    item additem()
	    {										    //add the details of an item to an object			
	    	item i;
	    	cout<<"\nEnter the name : ";
	    	cin>>i.name;
	    	cout<<"\nEnter the mrp: ";
	    	cin>>i.mrp;
	    	cout<<"\nEnter the present stock: ";
	    	cin>>i.present_stock;
	    	return i;
	    }
	    void dispitem()								//display the details of an item
	    {
	    	cout<<"\n"<<setiosflags(ios::left)<<setw(10)<<name<<"\t"<<setw(4)<<mrp<<"\t"<<"\t"<<setw(5)<<present_stock<<"\n";
	    }
	    bool searchitem(string n){
	    	if (name == n)
	    	{
	    		return true;
	    	}
	    	else
	    	{
	    		return false;
	    	}
	    }
	    //friend item retitem(string nam);
};

class shop{
	vector<sales> S;
	vector<flash_sales>FS;
	vector<item> I;
	vector<employee> E;
	manager M;
    public:
    	void add_employee()													//function to add employee
    	{
			employee temp;
			manager temp1;
			cout<<"1.MANAGER\n2.EMPLOYEE\n";
			int choice;
			cout<<"Enter the choice: ";
			cin>>choice;
			if(choice == 2)
			    E.push_back(temp.addemployee());
			else
				M = temp1.addemployeem();
		}

		void disp_employee()												//function to display all employee details
		{

            int choice;
            cout<<"1.MANAGER\n2.EMPLOYEE\n";
            cout<<"\nEnter the choice:";
            cin>>choice;
		   	cout<<"Aadhar no\tEmployee Name\tSex\tsalary\n";
		   	if(choice == 2)
		   	    for(int i = 0;i < E.size();i++)
		            E[i].dispemployee();
		    else
		    	M.dispemployee();
	    }

		
	    void search(string emp_name)										//overloaded function to search and display details of an employee 
	    {
	    	int flag = 0,i;
            for(i = 0;i < E.size();i++)
            {
            	if(E[i].searchemployee(emp_name))
            	{   
            		flag = 1;
            		break;
            	}
            }
			if(flag)
			{
				cout<<"Aadhar no:\tInput Name:\tSex:\tsalary\n";
				E[i].dispemployee();
			}
			else
				cout<<"Employee doesn't exist";
		}
		
	    void del_employee()													//function to display the delete an employee
	    {
	    	int flag = 0,i;
	    	string emp_name;
            cout<<"Enter the employee name: ";
            cin>>emp_name;
            for(i = 0;i < E.size();i++)
            {
            	if(E[i].searchemployee(emp_name))
            	{   
            		flag = 1;
            		break;
            	}
            }
            if(flag)
                E.erase(E.begin()+i);
            else
                cout<<"Employee doesn't exist";
        }

		
		void mod_salary(){						//function to give access to the manager to change employee salary 
			int i;
			string emp_name;
			cout<<"Enter the employee name:";
			cin>>emp_name;
			for(i = 0;i < E.size();i++)
			{
				if(E[i].searchemployee(emp_name))
				{
					M.modsalary(E[i]);		
					break;
				}
			}
			if(i == E.size())
				cout<<"Employee doesn't exist";
		}
       void add_item()							//add a new item to the vector I
        {
        	item t;
        	I.push_back(t.additem());
        }
        void disp_item()						//display all the items in the vector I
        {
        	int i;

        	cout<<"\n"<<setiosflags(ios::left)<<setw(10)<<"ITEM"<<"\t"<<setw(4)<<"MRP"<<"\t"<<"\t"<<setw(5)<<"PRESENT STOCK"<<"\n";
        	for ( i = 0; i <I.size(); ++i)
        	{
        		I[i].dispitem();
        	}
        	cout<<"\n";
        }

        void modify_item(string name)			// modify the item whose name is given
        {
        	int i,flag=0;
        	item t;
        	string n;
        	for ( i = 0; i < I.size(); ++i)
        	{
       			if (I[i].searchitem(name))			
       			{
       				flag = 1;
       				break;
       			}
       		}

       			if (flag)
       			{
       				cout<<"\nEnter the new name:";
       				cin>>t.name;
       				cout<<"\nEnter the new mrp :";
       				cin>>t.mrp;
       				cout<<"\nEnter the new present stock :";
       				cin>>t.present_stock;
                    I[i] = t;
       			}
       		    else
       		    	cout<<"\nList is empty\n";
        }

        void search(string name,int a)				//overloaded search for an item whose name is given
        {
        	int i,flag=0;
        	for (i = 0; i < I.size(); ++i)
        		{
        			if(I[i].searchitem(name))
        			{
						flag = 1;					//if an item of the given name is found
						break;
					}
						
        		}
        		if (flag)
        		{
        			cout<<"\n"<<setiosflags(ios::left)<<setw(10)<<"ITEM"<<"\t"<<setw(4)<<"MRP"<<"\t"<<"\t"<<setw(5)<<"PRESENT STOCK"<<"\n";
					I[i].dispitem();
        		}

        }

		 void del_item(string name)				    // delete an item whose name is given
        {
        	int i,flag=0;
        	for (i = 0; i < I.size(); ++i)
        	{
        		if (I[i].searchitem(name))
        		{
        			flag = 1;
        			break;
        		}

        	}
        	if (flag)
        	{
        		I.erase(I.begin()+i);
        	}
        }
        
		
		void add_sales()							//function to add a new sale
		{
			int count,choice;
			cout<<"Enter the number of items in sale: ";
			cin>>count;
			cout<<endl;
			sales temp;
			flash_sales temp1;
			cout<<"1.NORMAL SALE\n2.FLASH SALE\n\n";
			cout<<"Enter choice:";
			cin>>choice;
			if(choice == 1)
			    S.push_back(temp.addsales(count));
			else
				FS.push_back(temp1.addsalesf(count));
			
		}
		
		void disp_sales()							//function to call salesdisplay()
		{
			int choice;
			cout<<"\n1.NORMAL SALE\n2.FLASH SALE\n\n";
			cout<<"Enter choice:";
			cin>>choice;
			cout<<"SERIAL NO\tCUSTOMER NAME\tITEM NAME\tMRP\tQUANTITY\tTAX\tDISCOUNT\tAMOUNT\tTOTAL\n\n";
			if(choice == 1)
			    for(int i = 0;i < S.size();i++)
		            S[i].dispsales();
		    else
		    	for(int i = 0;i < FS.size();i++)
		    		FS[i].dispsales();	
		}

		void search(int a)							//overloaded function to find a particular sale using serial no.
		{
			int flag=0,count,i=0;
			count=S.size();
			for(i=0;i<count;i++)
				if(S[i].searchsales(a))
				{flag=1;break;}
			
			if(flag==1)
			{
				cout<<"Serial No:\tCustomer name:\t Item_name:\t mrp\t quantity\t tax\t discount\tAmt\tTotal\n";
			    S[i].dispsales();
			}
		
		}

	};


 main()
 {
	int ch,ch1;
	string name,name1;
	shop S1;


	do
	{
		cout<<"******** SHOP MANAGEMENT***********\n";
	    cout<<"-----------------------------------\n\n";
		cout<<"1.EMPLOYEE\n2.ITEM\n3.SALES\n4.EXIT\n";
		cout<<"Enter the choice:";
		cin>>ch;
		ClearScreen();
		switch(ch)
		{
			case 1: do
					{
						cout<<"\n\n======EMPLOYEE======\n";
						cout<<"\n1.ADD EMPLOYEE\n";
						cout<<"2.DELETE EMPLOYEE\n";
						cout<<"3.DISPLAY ALL EMPLOYEES\n";
						cout<<"4.SEARCH EMPLOYEE\n";
						cout<<"5.MODIFY SALARY\n";
						cout<<"6.EXIT\n";
						cout<<"\nEnter the choice:";
						cin>>ch1;
						cout<<endl;
						switch(ch1)
						{	
							case 1:S1.add_employee();
									ClearScreen();
									break;
							case 2:S1.del_employee();
									ClearScreen();
									break;
							case 3:S1.disp_employee();
									break;
							case 4:		
								        cout<<"Enter Employee name\n";
									    cin>>name;
									    S1.search(name);
									    break;
							case 5:
										string pass;
									    cout<<"\nEnter password:";
									    cin>>pass;
									    if(pass == "password")
									    {
									        S1.mod_salary();
									        ClearScreen();
									    }
									    else
										    cout<<"Wrong password";
									    break;		
						}
					}
					while(ch1!=6);
					break;
			case 2: 
					do
					{		
					    cout<<"\n\n======ITEMS======";
						cout<<"\n1.ADD ITEM\n";
						cout<<"2.DISPLAY ITEMS\n";
						cout<<"3.MODIFY ITEM\n";
						cout<<"4.DELETE ITEM\n";
						cout<<"5.SEARCH ITEM\n";
						cout<<"6.EXIT\n";
						cout<<"\nEnter the choice:";
						cin>>ch1;
						switch(ch1)
						{
							case 1:S1.add_item();
									ClearScreen();
									break;
							case 2:S1.disp_item();
									break;
							case 3: cout<<"Input item name\n";
									cin>>name;
									S1.modify_item(name);
									ClearScreen();
									break;
							case 4: cout<<"Input item name\n";
									cin>>name;
									S1.del_item(name);
									ClearScreen();
									break;
							case 5:	cout<<"\nEnter item name:";
									cin>>name;
									cout<<endl;
									S1.search(name,1);
									break;					
						}
					}
					while(ch1!=6);
					break;		
			case 3:
				  do{
				  	    cout<<"\n======SALES======";
						cout<<"\n1.ADD SALES\n";
						cout<<"2.SEARCH SALE\n";
						cout<<"3.DISPLAY SALE INFO\n";
						cout<<"4.EXIT\n";
						cout<"Enter your choice:";
						cin>>ch1;
						switch(ch1)
						{
							case 1:S1.add_sales();
									ClearScreen();
									break;
									
							case 2:cout<<"Input serial no\n";
									int no;
									cin>>no;
									S1.search(no);
									break;
							case 3:
									S1.disp_sales();
									break;
						}  
				    }
				    while(ch1!=4);
					    break;
		}
	}
	while(ch!=4);
 }
