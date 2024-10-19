#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

int main(){

   

    void navigation_modes_list();

    navigation_modes_list();

    return 0;
}

void navigation_modes_list(){

    cout<<""<<endl;

    cout<<"******************    Welcome To Amber Bakers..!!      *************************"<<endl;

    cout<<""<<endl;
    
    cout<<"Navigation Menu..!!"<<endl;

    cout<<""<<endl;

    string modes[] = {"1. Customer", "2. Employee"};

    int count_modes;

    count_modes = 0;

    while(count_modes <= 1){

        cout<<modes[count_modes]<<endl;

        cout<<""<<endl;

        count_modes = count_modes + 1;
    }


    void select_navigations_mode();

    select_navigations_mode();
}



void select_navigations_mode(){

    int mode_num;

    cout<<"\n Please Select Navigation Mode : ";

    cin>>mode_num;

    cout<<""<<endl;

    

    switch(mode_num){

        case 1: 
           void customer_mode();
           customer_mode();
           break;


        case 2:
           void employee_mode();
           employee_mode();
           break;

        
        default: 
           cout<<"No More Modes in the System..!!";
    }
}




//customer mode
void customer_mode(){

    
    //welcome part
    time_t c_time;
    time(&c_time);

    tm* time_info = localtime(&c_time);

    int hours, minutes, seconds;


    hours = time_info->tm_hour;

    minutes = time_info->tm_min;

    seconds = time_info->tm_sec;


    if(hours >= 0 and hours <= 12){
        cout<<"                     Good Morning..!!            "<<endl;
    }else{
        cout<<"                    Good Afternoon..!!           "<<endl;
    }

    

    

    cout<<"             We look forward to serving you.                      "<<"\n\n";



    
    cout<<"Customer Navigation Menu..!!"<<"\n\n";

    //customer navigations

    void customer_navigations();

    customer_navigations();

    
    int mod_number;



    cout<<"\n What Are You Looking For : ";

    cin>>mod_number;


    cout<<""<<endl;
    
    
    
    if(mod_number == 1){

        void visit_products_store();

        visit_products_store();
    }
    
    else if(mod_number == 2){

        //view company details
        void about_company();
        about_company();



    }else if(mod_number == 3){

        void exit();
        exit();
    }

}

//show customer navigations menu
void customer_navigations(){



    string customer_modes[] = {"1. Visit Store and Order.", "2. About Company.", "3. Exit."};

    int mod_counter;

    mod_counter = 0;


    while(mod_counter <= 2){

        cout<<customer_modes[mod_counter]<<"\n\n";

        mod_counter = mod_counter + 1;
    }


}







//visit store
void visit_products_store(){

    cout<<"                            ************* Find Your Best Deals..!! *************                    "<<"\n\n";

    cout<<"Order Your Products..!!"<<endl;

    void show_products();

    show_products();

}

void show_products(){

    ifstream bakery_file_read;

    bakery_file_read.open("Bakery_Items.txt", ios::in);


    string item_codes, item_names, item_prices;

    bakery_file_read>>item_codes>>item_names>>item_prices;

    while(bakery_file_read){

        

        cout<<"Item Codes : "<<item_codes<<"   Item Names : "<<item_names<<"   Item Prices :  "<<item_prices<<endl;

        bakery_file_read>>item_codes;

        bakery_file_read>>item_names;

        bakery_file_read>>item_prices;

        

        
    }

    bakery_file_read.close();


    string order_choice;

    cout<<"\n Want to Search Available Products (press y/n) : ";

    cin>>order_choice;


    if(order_choice == "Y" || order_choice == "y"){


        cout<<"Search Products and Order..!!"<<endl;

        void search_products();

        search_products();

    }else if(order_choice == "N" || order_choice == "n"){

        cout<<"Okay..!! Place Your Order without Search..!!"<<endl;

        void order_products();

        order_products();

    }
}

//for search products
void search_products(){

    cout<<"Search Products..!!"<<endl;

    string s_item_name, item_codes, item_names, item_prices;

    cout<<"\nEnter Item Name : ";

    cin>>s_item_name;

    ifstream bakery_file_data;

    bakery_file_data.open("Bakery_Items.txt", ios::in);

    

    bool search_founded = false;

    while(bakery_file_data>>item_codes>>item_names>>item_prices){

        if(item_names == s_item_name){

            search_founded = true;

            break;
        }

    }

    if(search_founded){

        cout<<"Item Founded..!!\n\n"<<endl;

        cout<<"      Item Codes : "<<item_codes<<"   Item Names : "<<item_names<<"   Item Prices :  "<<item_prices<<endl;

        void confirm_order();

        confirm_order();


    }else{

        cout<<"Item Not Found..!!"<<endl;

        cout<<"Reloading..!!"<<endl;


        void visit_products_store();

        visit_products_store();


    }

}

//normal orders placing(without searching)
void order_products(){


    void confirm_order();

    confirm_order();
}



void Billing(int quantity, string item){

    int calculate, cake_price, bread_price, cupcake_price, bun_price, lava_cake_price, cookies_price;

    if(item == "Cake" || item == "CAKE"){

            cake_price = 50;

            calculate = cake_price * quantity;

            cout<<"The Total is : $ "<<calculate<<endl;

    }else if(item == "Bread" || item == "BREAD"){

           bread_price = 20;

           calculate = bread_price * quantity;

           cout<<"The Total is : $ "<<calculate<<endl;

    }else if(item == "CupCake" || item == "CUPCAKE"){

           cupcake_price = 60;

           calculate = cupcake_price * quantity;

           cout<<"The Total is : $ "<<calculate<<endl;


    }else if(item == "Bun" || item == "BUN"){

          bun_price = 20;

          calculate = bun_price * quantity;

          cout<<"The Total is : $ "<<calculate<<endl;

    }else if(item == "LavaCake" || item == "LAVACAKE"){

          lava_cake_price = 100;

          calculate = lava_cake_price * quantity;

          cout<<"The Total is : $ "<<calculate<<endl;

    }else if(item == "Cookies" || item == "COOKIES"){

          cookies_price = 60;

          calculate = cookies_price * quantity;

          cout<<"The Total is : $ "<<calculate<<endl;

    }
}



//save order details and order confirmation
void confirm_order(){

    string cus_name, address, order_item, mobile_no, order_confirm;

    int item_quntity;

    cout<<"\n Please enter Your Details and Order Details..!!"<<endl;

    ofstream customer_details_file;

    customer_details_file.open("customer_order_details.txt", ios::app);



    cout<<"\n Enter Your Name : ";

    cin>>cus_name;

    cin.ignore();

    cout<<"\n Enter Your Address : ";

    getline(cin, address);

    

    cout<<"\n Enter Order Item : ";

    getline(cin, order_item);

    cout<<"\n Enter Item Quntity : ";

    cin>>item_quntity;

    cin.ignore();

    cout<<"\n Enter Contact No : ";

    getline(cin, mobile_no);

    cout<<"\n Please Confirm the Order (press y/n) : ";

    cin>>order_confirm;

    time_t c_time;

    time(&c_time);

    tm* time_info = localtime(&c_time);

    int year, month, date;

    

    year = time_info->tm_year + 1900;

    month = time_info->tm_mon + 1;

    date = time_info->tm_mday;


    if(order_confirm == "y" || order_confirm == "Y"){

        cout<<"Order Placed Successfully..!!\n\n";

        

        customer_details_file<<cus_name<<" "<<address<<" "<<order_item<<" "<<item_quntity<<" "<<mobile_no<<" "<<year<<"-"<<month<<"-"<<date<<endl;

        cout<<"Calculating Bill..!!\n\n"<<endl;

        Billing(item_quntity, order_item);

        void customer_mode();

        customer_mode();

        


    }else{
        cout<<"Okay..!! find more Products..!!"<<endl;

        void visit_products_store();

        visit_products_store();
    }

}


//displaying about of the company
void about_company(){

    cout<<"                               *********** About Amber Bakers **************"                                <<"\n\n";


    string company_details_1;
    string company_details_2;


    company_details_1 = "             Since 1875, Amber Bakery has been a haven of delightful confections, blending culinary artistry with a rich heritage. Our legacy of excellence continues with a touch of modernity,";
    company_details_2 = "as we combine our time-honored recipes with innovative approaches to create an unforgettable experience for every palate.";


    cout<<company_details_1;

    cout<<company_details_2<<"\n\n";

    cout<<"\n Back to the Main menu(y) : ";

    string select_main_menu;

    cin>>select_main_menu;

    

    if(select_main_menu == "YES" || select_main_menu == "yes" ){
        customer_mode();
    }else{
        cout<<"Command does not Recognised..!!"<<endl;
    }
}

//customer exit

void exit(){

    cout<<"Good Bye Have a Nice Day..!!"<<endl;

    navigation_modes_list();
}




//employee mode
void employee_mode(){

    cout<<"Employee Mode..!!\n\n";

    //login
    void emp_login();

    emp_login();

    int choose_mode;

    

    cout<<"\n Please Select Mode : ";

    cin>>choose_mode;

    switch(choose_mode){

        case 1:
           void add_products();

           add_products();

           break;

        case 2:
           void update_products();

           update_products();

           break;

        case 3:
           void delete_products();

           delete_products();

           break;

        case 4:
          
           void manage_sales_details();

           manage_sales_details();
           
           break;

        case 5:

           void logout();

           logout();

           break;

        default:
          
           cout<<"No more modes for employee..!!"<<endl;
           break;
           
    }
}

//employee navigations menu
void employee_navigations_menu(){

    cout<<"Employee Navigations Menu..!!"<<endl;

    string employee_modes[] = {"1. Add Products.", "2. Update Products.", "3. Delete Products.", "4. Manage Customer Sales.", "5. Logout"};

    int emp_mod_counter;

    emp_mod_counter = 0;


    while(emp_mod_counter <= 4){

        cout<<employee_modes[emp_mod_counter]<<"\n\n";

        emp_mod_counter = emp_mod_counter + 1;
    }
}




//employee login
void emp_login(){

    cout<<"Employee Login"<<endl;

    string employee_username, employee_password;

    ifstream credential_file;

    credential_file.open("Employee_login_credentials.txt");

    string username, password;

    cout<<"\nEnter Username : ";

    cin>>username;

    cout<<"\nEnter Password : ";

    cin>>password;

    bool isLogin = false;

    while(credential_file>>employee_username>>employee_password){

        
        
           if(employee_username == username && employee_password == password){

               isLogin = true;

               break;

           }

    }

    if(isLogin){

        cout<<"Access Granted..!!\n\n";

        employee_navigations_menu();


    }else{

        

        cout<<"Access Failed..!!\n\n";

        void employee_mode();

        employee_mode();

        
    }

    

}

//add products to the store
void add_products(){

    cout<<"Add Products to the Store..!!"<<endl;

    string item_name;

    int item_code, item_price;

    string ask_employee;
    
    while(ask_employee != "Yes" || ask_employee != "yes" || ask_employee != "YES"){

        ofstream Bakery_items;
    
        Bakery_items.open("Bakery_Items.txt", ios::app);

        cout<<"\nItem Code : ";

        cin>>item_code;

        cout<<"\nItem Name : ";

        cin>>item_name;

        cout<<"\nItem Price : $ ";

        cin>>item_price;

        Bakery_items<<"\n"<<item_code<<" "<<item_name<<" $"<<item_price;


        cout<<"Item Added Successfully..!!"<<endl;

        Bakery_items.close();


        cout<<"\n You want Add More : ";

        cin>>ask_employee;
        

        if(ask_employee == "No" || ask_employee == "no" || ask_employee == "NO"){

            cout<<"Okay..!! Exiting in Add Products Mode..!!"<<endl;

            navigation_modes_list();

            break;

        }
    }





}

//showing the listed products for the employee
void show_listed_products(){

    ifstream bakery_file_read;

    bakery_file_read.open("Bakery_Items.txt", ios::in);


    string item_codes, item_names, item_prices;

    bakery_file_read>>item_codes>>item_names>>item_prices;

    while(bakery_file_read){

        

        cout<<"Item Codes : "<<item_codes<<"   Item Names : "<<item_names<<"   Item Prices :  "<<item_prices<<endl;

        bakery_file_read>>item_codes;

        bakery_file_read>>item_names;

        bakery_file_read>>item_prices;

        

        
    }

    bakery_file_read.close();

}

//update products
void update_products(){

    cout<<"Update Products..!!"<<endl;

    cout<<"Already Listed Products..!!"<<endl;

    show_listed_products();

    string item_name;


    int line_num, item_no, item_price;

    cout<<"\n Enter Products line Num to Update : ";

    cin>>line_num;

    cout<<"\n Update Item No : ";

    cin>>item_no;

    cout<<"\n Update Products Name : ";

    cin>>item_name;

    cout<<"\n Update Products Price : $";

    cin>>item_price;

    ifstream bakery_file_update;

    bakery_file_update.open("Bakery_Items.txt", ios::in);


    string data_line;

    vector <string> data_lines_vector;

    while(getline(bakery_file_update, data_line)){

        data_lines_vector.push_back(data_line);
        
    }


    if(line_num <= 0 || line_num > data_lines_vector.size()){
        cout<<"The Product Line Number Was Not Found...!!"<<endl;
    }

    string update_data;
    
    update_data = to_string(item_no) + " " + item_name + " $ " + to_string(item_price);

    data_lines_vector[line_num - 1] = update_data;


    ofstream bakery_data_file;

    bakery_data_file.open("Bakery_Items.txt", ios::out);

    for(string& update_line : data_lines_vector){

        bakery_data_file<<update_line<<endl;
    }


    cout<<"Line is  "<<line_num<<" Updated Successfully "<<endl;

}

//delete products
void delete_products(){

    show_listed_products();

    int delete_line_number;

    cout<<"\n Enter Product line Number to Delete : ";

    cin>>delete_line_number;

    ifstream bakery_file_delete;

    bakery_file_delete.open("Bakery_Items.txt", ios::in);

    vector <string> delete_lines_vector;

    string data_lines;

    while(getline(bakery_file_delete, data_lines)){

        delete_lines_vector.push_back(data_lines);


    }

    if(delete_line_number <= 0 || delete_line_number > delete_lines_vector.size()){

        cout<<"The Product Line Not Founded..!!"<<endl;
    }

    delete_lines_vector.erase(delete_lines_vector.begin() + delete_line_number - 1);



    ofstream bakery_data_file;

    bakery_data_file.open("Bakery_Items.txt", ios::out);

    for(string& delete_line : delete_lines_vector){

        bakery_data_file<<delete_line<<endl;
    }


    cout<<"Line is  "<<delete_line_number<<" Deleted Successfully..!! "<<endl;


}



//Manage sales details
void manage_sales_details(){

    cout<<"Sales Details..!!"<<endl;

    ifstream customer_order_details_file;

    customer_order_details_file.open("customer_order_details.txt", ios::in);

    string data_lines; 


    while(getline(customer_order_details_file, data_lines)){

        cout<<data_lines<<endl;
        
    }
}


//employee logout
void logout(){

    string ask_employee_choice;

    cout<<"\n Are you Want to Logout : ";

    cin>>ask_employee_choice;

    if(ask_employee_choice == "Yes" || ask_employee_choice == "YES" || ask_employee_choice == "yes"){

        cout<<"Okay..!! Logging Out..!!"<<endl;

    }else{

        employee_navigations_menu();

    }




}