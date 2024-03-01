//---------------------------
//       HEADER FILES
//---------------------------









#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <ctime>
#include <tuple>
#include <numeric>
#include <chrono>
#include<ctime>

using namespace std;

//---------------------------------
//       GLOBAL VARIABLE
//---------------------------------
string Current_Date;










//---------------------------------
//       UTILITY FUNCTIONS
//---------------------------------










bool Contains_Digits(const string& Input_Date)
{
    return std::all_of(Input_Date.begin(), Input_Date.end(), ::isdigit);
}

tm Date_To_tm(int day, int month, int year) 
{
    tm timeinfo = {};
    timeinfo.tm_mday = day;
    timeinfo.tm_mon = month - 1; 
    timeinfo.tm_year = year - 1900; 
    return timeinfo;
}

int Date_Difference(string date_1, string date_2)
{
    int day_1 = stoi(date_1.substr(0, 2));
    int month_1 = stoi(date_1.substr(2, 2));
    int year_1 = stoi(date_1.substr(4, 4));
    int day_2 = stoi(date_2.substr(0, 2));
    int month_2 = stoi(date_2.substr(2, 2));
    int year_2 = stoi(date_2.substr(4, 4));
    tm date_1_tm = Date_To_tm(day_1, month_1, year_1);
    tm date_2_tm = Date_To_tm(day_2, month_2, year_2);
    time_t date_1_time_t = mktime(&date_1_tm);
    time_t date_2_time_t = mktime(&date_2_tm);
    return static_cast<int>(difftime(date_2_time_t, date_1_time_t) / (60 * 60 * 24));
}








//---------------------------------
//            CAR CLASS
//---------------------------------








class Car_Class;
vector<Car_Class> Cars_Present;
int Total_No_Of_Cars;
int Total_No_Of_Cars_AllTime;
unordered_map<string, int> Cars_Map;
int Is_Member_Cars_Present(string Car_ID);
class Car_Class
{
    public:
        string Car_ID;
        string Car_Plate_No;
        string Company;
        string Model;
        string Engine;
        int Engine_Size;
        string Power_Output;
        float Litres_p100kms;
        string Transmission;
        int Kilometres_Driven;
        int Seating_Capacity;
        int No_Of_Airbags;
        string Air_Conditioning;    //Available or Unavailable
        string Infotainment_System; //Available or Unavailable
        string Colour;
        int No_Of_Dents;
        int No_Of_Scratches;
        string Condition_Of_Headlights; //Intact or Broken
        string Other_Remarks;
        long long Booking_Charge_Day;
        long long Overdue_Charge;
        long long Damage_Cost;
        string Available_For_Rent;  //Yes or No
        string On_Rent; //Yes or No
        string Start_Date;
        string End_Date;
        long long Base_Payment;
        int Current_No_Of_Days;
        long long Current_Payment_Due;
        string Renter_ID;
        string Managing_Employee_ID;
        string Status; //Active or Deactivated

        Car_Class(){;}

        Car_Class(string Car_ID, string Car_Plate_No, string Company, string Model, string Engine, int Engine_Size, string Power_Output, float Litres_p100kms, string Transmission, int Kilometres_Driven, int Seating_Capacity, int No_Of_Airbags, string Air_Conditioning, string Infotainment_System, string Colour, int No_Of_Dents, int No_Of_Scratches, string Condition_Of_Headlights, string Other_Remarks, long long Booking_Charge_Day, long long Overdue_Charge, long long Damage_Cost, string Available_For_Rent, string On_Rent, string Start_Date, string End_Date, long long Base_Payment, int Current_No_Of_Days, long long Current_Payment_Due, string Renter_ID, string Managing_Employee_ID)
        {
            this->Car_ID=Car_ID;
            this->Car_Plate_No=Car_Plate_No;
            this->Company=Company;
            this->Model=Model;
            this->Engine=Engine;
            this->Engine_Size=Engine_Size;
            this->Power_Output=Power_Output;
            this->Litres_p100kms=Litres_p100kms;
            this->Transmission=Transmission;
            this->Kilometres_Driven=Kilometres_Driven;
            this->Seating_Capacity=Seating_Capacity;
            this->No_Of_Airbags=No_Of_Airbags;
            this->Air_Conditioning=Air_Conditioning;
            this->Infotainment_System=Infotainment_System;
            this->Colour=Colour;
            this->No_Of_Dents=No_Of_Dents;
            this->No_Of_Scratches=No_Of_Scratches;
            this->Condition_Of_Headlights=Condition_Of_Headlights;
            this->Other_Remarks=Other_Remarks;
            this->Booking_Charge_Day=Booking_Charge_Day;
            this->Overdue_Charge=Overdue_Charge;
            this->Damage_Cost=Damage_Cost;
            this->Available_For_Rent=Available_For_Rent;
            this->On_Rent=On_Rent;
            this->Start_Date=Start_Date;
            this->End_Date=End_Date;
            this->Base_Payment=Base_Payment;
            this->Current_No_Of_Days=Current_No_Of_Days;
            this->Current_Payment_Due=Current_Payment_Due;
            this->Renter_ID=Renter_ID;
            this->Managing_Employee_ID=Managing_Employee_ID;
            this->Status="Active";
        }
        
        void Add_Car()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            Car_ID="CAR"+to_string(Total_No_Of_Cars_AllTime+1);

            do
            {
                cout<<">> Enter the Car Plate Number"<<endl;
                cin>>Car_Plate_No;
            }while(Car_Plate_No.length()!=10);

            cout<<">> Enter the Company"<<endl;
            cin>>Company;

            cout<<">> Enter the Model"<<endl;
            cin>>Model;

            do
            {
                cout<<">> Enter the Engine: Petrol, Diesel or Electric"<<endl;
                cin>>Engine;
            }while(Engine!="Petrol" && Engine!="Diesel" && Engine!="Electric");

            cout<<">> Enter the Engine Size"<<endl;
            cin>>Engine_Size;

            cout<<">> Enter the Power Output"<<endl;
            cin>>Power_Output;

            cout<<">> Enter the Kilomteres per litre"<<endl;
            cin>>Litres_p100kms;

            do
            {
                cout<<">> Enter the Transmission: Manual or Automatic"<<endl;
                cin>>Transmission;
            } while (Transmission!="Manual" && Transmission!="Automatic");
            
            cout<<">> Enter the Kilometres Driven"<<endl;
            cin>>Kilometres_Driven;

            cout<<">> Enter the Seating Capacity"<<endl;
            cin>>Seating_Capacity;

            cout<<">> Enter the Number of Airbags"<<endl;
            cin>>No_Of_Airbags;

            do
            {
                cout<<">> Enter the Air Conditioning: Available or Unavailable"<<endl;
                cin>>Air_Conditioning;
            }while(Air_Conditioning!="Available" && Air_Conditioning!="Unavailable");

            do
            {
                cout<<">> Enter the Infotainment System: Available or Unavailable"<<endl;
                cin>>Infotainment_System;
            }while(Infotainment_System!="Available" && Infotainment_System!="Unavailable");

            cout<<">> Enter the Colour"<<endl;
            cin>>Colour;

            cout<<">> Enter the Number of Dents"<<endl;
            cin>>No_Of_Dents;

            cout<<">> Enter the Number of Scratches"<<endl;
            cin>>No_Of_Scratches;

            do
            {
                cout<<">> Enter the Condition of the Headlights: Intact or Broken"<<endl;
                cin>>Condition_Of_Headlights;
            } while (Condition_Of_Headlights!="Intact" && Condition_Of_Headlights!="Broken");

            cout<<">> Enter Other Remarks"<<endl;
            cin>>Other_Remarks;

            cout<<">> Enter the Booking Charge per Day for 25 kms"<<endl;
            cin>>Booking_Charge_Day;

            cout<<">> Enter the Overdue Charge"<<endl;
            cin>>Overdue_Charge;

            cout<<">> Enter the Damage Cost"<<endl;
            cin>>Damage_Cost;

            if(Condition_Of_Headlights=="Broken")
            {
                Available_For_Rent="No";
            }
            else
            {
                Available_For_Rent="Yes";
            }

            On_Rent="No";
            Start_Date="0";
            End_Date="0";
            Base_Payment=0;
            Current_No_Of_Days=0;
            Current_Payment_Due=0;
            Renter_ID="0";
            Managing_Employee_ID="0";
            Status="Active";
        }

        void Display_Car()
        {
            if(Status=="Active")
            {
                cout<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<endl;
                cout<<">> Car ID: "<<Car_ID<<endl;
                cout<<">> Car Plate Number: "<<Car_Plate_No<<endl;
                cout<<">> Company: "<<Company<<endl;
                cout<<">> Model: "<<Model<<endl;
                cout<<">> Engine: "<<Engine<<endl;
                cout<<">> Engine Size: "<<Engine_Size<<" cc"<<endl;
                cout<<">> Power Output: "<<Power_Output<<endl;
                cout<<">> Litres per 100 kms: "<<Litres_p100kms<<endl;
                cout<<">> Transmission: "<<Transmission<<endl;
                cout<<">> Kilometres Driven: "<<Kilometres_Driven<<endl;
                cout<<">> Seating Capacity: "<<Seating_Capacity<<endl;
                cout<<">> Number of Airbags: "<<No_Of_Airbags<<endl;
                cout<<">> Air Conditioning: "<<Air_Conditioning<<endl;
                cout<<">> Infotainment System: "<<Infotainment_System<<endl;
                cout<<">> Colour: "<<Colour<<endl;
                cout<<">> Booking charge per day:"<<Booking_Charge_Day<<endl;
                cout<<">> Overdue Charge: "<<Overdue_Charge<<endl;
                cout<<">> Damage Cost: "<<Damage_Cost<<endl;
                if(On_Rent=="Yes")
                {
                    cout<<"This car is currently booked"<<endl;
                    cout<<">> Renter ID: "<<Renter_ID<<endl;
                    cout<<">> Managing Employee ID: "<<Managing_Employee_ID<<endl;
                    cout<<">> Booking Start Date: "<<Start_Date<<endl;
                    cout<<">> Booking End Date: "<<End_Date<<endl;
                    cout<<">> Current No. of Days: "<<Current_No_Of_Days<<endl;
                    cout<<">> Current Payment Due: "<<Current_Payment_Due<<endl;
                }
            }
        }

        void Book_Car(string End_Date,int Discount, string RenterID, string ManagingEmployeeID)
        {
            Available_For_Rent="No";
            On_Rent="Yes";
            this->Start_Date=Current_Date;
            this->End_Date=End_Date;
            Base_Payment=Booking_Charge_Day*Date_Difference(Start_Date, End_Date)*(1-Discount/100);
            this->Renter_ID=RenterID;
            this->Managing_Employee_ID=ManagingEmployeeID;
            Current_No_Of_Days=1;
            Current_Payment_Due=Booking_Charge_Day;
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Start Date of the Booking: "<<Start_Date.substr(0,2)<<"/"<<Start_Date.substr(2,2)<<"/"<<Start_Date.substr(4,4)<<endl;
            cout<<">> End Date of the Booking: "<<End_Date.substr(0,2)<<"/"<<End_Date.substr(2,2)<<"/"<<End_Date.substr(4,4)<<endl;
            cout<<">> Payment to be made at the end of the end date: Rs."<<Base_Payment<<endl;
        }

        void Update_Booking()
        {
            Current_No_Of_Days=Date_Difference(Start_Date, Current_Date);
            if(Current_No_Of_Days>Date_Difference(Start_Date, End_Date))
            {
                Current_Payment_Due=Base_Payment+Overdue_Charge*(Current_No_Of_Days-Date_Difference(Start_Date, End_Date));
            }
            else
            {
                Current_Payment_Due=Booking_Charge_Day*Current_No_Of_Days;
            }
        }

        void Update_Car()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Select an attribute to update:"<<endl;
            cout<<">> 1. Company"<<endl;
            cout<<">> 2. Model"<<endl;
            cout<<">> 3. Engine"<<endl;
            cout<<">> 4. Engine Size"<<endl;
            cout<<">> 5. Power Output"<<endl;
            cout<<">> 6. Litres per 100 kms"<<endl;
            cout<<">> 7. Transmission"<<endl;
            cout<<">> 8. Kilometres Driven"<<endl;
            cout<<">> 9. Seating Capacity"<<endl;
            cout<<">> 10. Number of Airbags"<<endl;
            cout<<">> 11. Air Conditioning"<<endl;
            cout<<">> 12. Infotainment System"<<endl;
            cout<<">> 13. Colour"<<endl;
            cout<<">> 14. Booking Charge per Day"<<endl;
            cout<<">> 15. Overdue Charge"<<endl;
            cout<<">> 16. Damage Cost"<<endl;

            string Car_Class_Update_Car;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>Car_Class_Update_Car;
                wrong++;
            } while (!Contains_Digits(Car_Class_Update_Car));

            int Car_Class_Update_Car_Int=stoi(Car_Class_Update_Car);

            switch(Car_Class_Update_Car_Int)
            {
                case 1:
                {
                    cout<<">> Enter the new Company:"<<endl;
                    cin>>Company;
                    break;
                }
                case 2:
                {
                    cout<<">> Enter the new Model:"<<endl;
                    cin>>Model;
                    break;
                }
                case 3:
                {
                    do
                    {
                        cout<<">> Enter the new Engine: Petrol, Diesel or Electric"<<endl;
                        cin>>Engine;
                    }while(Engine!="Petrol" && Engine!="Diesel" && Engine!="Electric");
                    break;
                }
                case 4:
                {
                    cout<<">> Enter the new Engine Size:"<<endl;
                    cin>>Engine_Size;
                    break;
                }
                case 5:
                {
                    cout<<">> Enter the new Power Output:"<<endl;
                    cin>>Power_Output;
                    break;
                }
                case 6:
                {
                    cout<<">> Enter the new Litres per 100 kms:"<<endl;
                    cin>>Litres_p100kms;
                    break;
                }
                case 7:
                {
                    do
                    {
                        cout<<">> Enter the new Transmission: Manual or Automatic"<<endl;
                        cin>>Transmission;
                    } while (Transmission!="Manual" && Transmission!="Automatic");
                    break;
                }
                case 8:
                {
                    cout<<">> Enter the new Kilometres Driven:"<<endl;
                    cin>>Kilometres_Driven;
                    break;
                }
                case 9:
                {
                    cout<<">> Enter the new Seating Capacity:"<<endl;
                    cin>>Seating_Capacity;
                    break;
                }
                case 10:
                {
                    cout<<">> Enter the new Number of Airbags:"<<endl;
                    cin>>No_Of_Airbags;
                    break;
                }
                case 11:
                {
                    do
                    {
                        cout<<">> Enter the new Air Conditioning: Available or Unavailable"<<endl;
                        cin>>Air_Conditioning;
                    }while(Air_Conditioning!="Available" && Air_Conditioning!="Unavailable");
                    break;
                }
                case 12:
                {
                    do
                    {
                        cout<<">> Enter the new Infotainment System: Available or Unavailable"<<endl;
                        cin>>Infotainment_System;
                    }while(Infotainment_System!="Available" && Infotainment_System!="Unavailable");
                    break;
                }
                case 13:
                {
                    cout<<">> Enter the new Colour:"<<endl;
                    cin>>Colour;
                    break;
                }
                case 14:
                {
                    cout<<">> Enter the new Booking Charge per Day:"<<endl;
                    cin>>Booking_Charge_Day;
                    break;
                }
                case 15:
                {
                    cout<<">> Enter the new Overdue Charge:"<<endl;
                    cin>>Overdue_Charge;
                    break;
                }
                case 16:
                {
                    cout<<">> Enter the new Damage Cost:"<<endl;
                    cin>>Damage_Cost;
                    break;
                }
                default:
                {
                    cout<<">> Invalid Option Selected"<<endl;
                    Update_Car();
                    break;
                }
            }
        }

        long long Clear_Dues_Car()
        {
            cout<<">> Please Enter The No. of Dents Caused"<<endl;
            cin>>No_Of_Dents;
            cout<<">> Please Enter The No. of Scratches Caused"<<endl;
            cin>>No_Of_Scratches;
            do
            {
                cout<<">> Please Enter The Condition of the Headlights: Intact or Broken"<<endl;
                cin>>Condition_Of_Headlights;
            }while(Condition_Of_Headlights!="Intact" && Condition_Of_Headlights!="Broken");

            do
            {
                cout<<">> Please Enter Other Remarks: None or Headlights_Under_Repair"<<endl;
                cin>>Other_Remarks;
            }while(Other_Remarks!="None" && Other_Remarks!="Headlights_Under_Repair");

            if(Condition_Of_Headlights=="Broken")
            {
                Available_For_Rent="No";
            }
            else
            {
                Available_For_Rent="Yes";
            }

            On_Rent="No";
            Start_Date="0";
            End_Date="0";
            Base_Payment=0;
            Current_No_Of_Days=0;
            Current_Payment_Due=0;
            Renter_ID="0";
            Managing_Employee_ID="0";

            if(Condition_Of_Headlights=="Broken")
            {
                return Damage_Cost;
            }
            else
            {
                return 0;
            }
        }
};








//---------------------------------
//            USER CLASS
//---------------------------------









class User_Class
{
    protected:

        string Password;

    public:

        //attributes

        string User_ID;
        string First_Name;
        string Last_Name;
        int Age;
        string Gender;
        string Personal_Email;
        long long Phone_No; //limited to 10 digits
        string DL_No;   //limited to 15 characters
        int Total_Rented; //no of days
        int Total_Overdue;  //no of days
        int Dents_Caused;
        int Scratches_Caused;
        long long Damage_Cost;  //in rupees
        int Cars_Rented;    //no of cars rented
        int Discount;   //stores discount for the user as percentage
        int Eligibility;    //no of cars that can be booked
        string Status;  //Active or Deactivated

        //methods
        User_Class(){;}

        User_Class(string User_ID,string Password, string First_Name, string Last_Name, int Age, string Gender, string Personal_Email, long long Phone_No, string DL_No, int Total_Rented, int Total_Overdue, int Dents_Caused, int Scratches_Caused, long long Damage_Cost,int Cars_Rented, int Discount,int Eligibility)    //parameterized constructor
        {
            this->User_ID=User_ID;
            this->Password=Password;
            this->First_Name=First_Name;
            this->Last_Name=Last_Name;
            this->Age=Age;
            this->Gender=Gender;
            this->Personal_Email=Personal_Email;
            this->Phone_No=Phone_No;
            this->DL_No=DL_No;
            this->Total_Rented=Total_Rented;
            this->Total_Overdue=Total_Overdue;
            this->Dents_Caused=Dents_Caused;
            this->Scratches_Caused=Scratches_Caused;
            this->Damage_Cost=Damage_Cost;
            this->Cars_Rented=Cars_Rented;
            this->Discount=Discount;
            this->Eligibility=Eligibility;
            this->Status="Active";
        }

        int SignUp(string ID_Begin,int Total_No)
        {
            int Flag=1;
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;

            User_ID=ID_Begin+to_string(Total_No+1);

            cout<<">> Please enter the password:"<<endl;
            cin>>Password;
            
            cout<<">> Please enter First Name:"<<endl;
            cin>>First_Name;

            cout<<">> Please enter Last Name:"<<endl;
            cin>>Last_Name;

            cout<<">> Please enter the Age:"<<endl;
            cin>>Age;
            if(Age<18)
            {
                Flag=0;
                return Flag;
            }

            do
            {
                cout<<">> Please enter your Gender: Male, Female, Transgender or Prefer_Not_To_Say"<<endl;
                cin>>Gender;
            }while(Gender!="Male" && Gender!="Female" && Gender!="Transgender" && Gender!="Prefer_Not_To_Say");

            cout<<">> Please enter the Personal Email ID"<<endl;
            cin>>Personal_Email;

            do
            {
                cout<<">> Please enter the Phone No."<<endl;
                cin>>Phone_No;
            }while(to_string(Phone_No).length()!=10);

            do
            {
                cout<<">> Please enter the Driving License No."<<endl;
                cin>>DL_No;
            }while(DL_No.length()!=13);

            Total_Rented=0;
            Total_Overdue=0;
            Dents_Caused=0;
            Scratches_Caused=0;
            Damage_Cost=0;
            Cars_Rented=0;
            Eligibility=5;
            Status="Active";

            return Flag;
        }

        virtual void Navbar()=0;
        
        void Booking()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Select The Index Corresponding To An Option To View Available Cars:"<<endl;
            cout<<">> 1. View Full Car List"<<endl;
            cout<<">> 2. Search"<<endl;
            string User_Input_Booking;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>User_Input_Booking;
                wrong++;
            } while (!Contains_Digits( User_Input_Booking));

            int User_Input_Booking_Int=stoi(User_Input_Booking);
            
            switch(User_Input_Booking_Int)
            {
                case 1: 
                {
                    for(int ite=0;ite<Cars_Present.size();ite++)
                    {
                        if(Cars_Present[ite].Available_For_Rent=="Yes" && Cars_Present[ite].On_Rent=="No" && Cars_Present[ite].Status=="Active")
                        {
                            Cars_Present[ite].Display_Car();
                            cout<<endl;
                        }
                    }
                    break; 
                }
                case 2:
                {
                    string sCompany;
                    string sModel;
                    string sEngine;
                    int sEngine_Size;
                    string sPower_Output;
                    float sLitres_p100kms;
                    string sTransmission;
                    int sSeating_Capacity;
                    int sNo_Of_Airbags;
                    string sAir_Conditioning;
                    string sInfotainment_System;
                    string sColour;
                    long long sBooking_Charge_Day;
                    long long sOverdue_Charge;

                    cout<<">> Enter The Company:"<<endl;
                    cin>>sCompany;

                    cout<<">> Enter The Model:"<<endl;
                    cin>>sModel;

                    cout<<">> Enter The Engine:"<<endl;
                    cin>>sEngine;

                    cout<<">> Enter The Engine Size:"<<endl;   //convert this to range
                    cin>>sEngine_Size;

                    cout<<">> Enter The Power Output:"<<endl;      //convert this to range
                    cin>>sPower_Output;

                    cout<<">> Enter The Performance Requirement in kilometres per 1 litre of fuel:"<<endl;
                    cin>>sLitres_p100kms;

                    cout<<">> Enter The Transmission:"<<endl;
                    cin>>sTransmission;

                    cout<<">> Enter The Seating Capacity "<<endl;  //convert this to range
                    cin>>sSeating_Capacity;

                    cout<<">> Enter The Required Availability of Air Conditioning System:"<<endl;
                    cin>>sAir_Conditioning;

                    cout<<">> Enter The Required Availability of Infotainment System:"<<endl;
                    cin>>sInfotainment_System;  

                    cout<<">> Enter the Required Colour:"<<endl;
                    cin>>sColour;

                    cout<<">> Enter the Base Booking Charge Required:"<<endl;  //convert this to range
                    cin>>sBooking_Charge_Day;

                    cout<<">> Enter the Overdue Booking Charge Required:"<<endl;   //convert this to range
                    cin>>sOverdue_Charge;

                    for(int ite=0;ite<Cars_Present.size();ite++)
                    {
                        if(Cars_Present[ite].Company == sCompany && Cars_Present[ite].Model == sModel && Cars_Present[ite].Engine == sEngine && Cars_Present[ite].Engine_Size == sEngine_Size && Cars_Present[ite].Power_Output == sPower_Output && Cars_Present[ite].Litres_p100kms == sLitres_p100kms && Cars_Present[ite].Transmission == sTransmission && Cars_Present[ite].Seating_Capacity == sSeating_Capacity && Cars_Present[ite].Air_Conditioning == sAir_Conditioning && Cars_Present[ite].Infotainment_System == sInfotainment_System && Cars_Present[ite].Colour == sColour && Cars_Present[ite].Booking_Charge_Day == sBooking_Charge_Day && Cars_Present[ite].Overdue_Charge == sOverdue_Charge && Cars_Present[ite].Available_For_Rent=="Yes" && Cars_Present[ite].On_Rent=="No" && Cars_Present[ite].Status=="Active")
                        {
                            Cars_Present[ite].Display_Car();
                        }
                    }
                    break;
                }
                default:       
                {
                    cout<<">> Invalid Option Selected";
                    Booking();
                    break;
                }
            }
        }

        virtual void View_Profile()
        {
            if(Status=="Active")
            {
                cout<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<endl;
                cout<<">> User ID:"<<User_ID<<endl;
                cout<<">> First Name:"<<First_Name<<endl;
                cout<<">> Last Name:"<<Last_Name<<endl;
                cout<<">> Age:"<<Age<<endl;
                cout<<">> Gender:"<<Gender<<endl;
                cout<<">> Personal Email:"<<Personal_Email<<endl;
                cout<<">> Phone No.:"<<Phone_No<<endl;
                cout<<">> Driving License No.:"<<DL_No<<endl;
                cout<<">> Total No. of Days Rented From This Account:"<<Total_Rented<<endl;
                cout<<">> Total No. of Days Overdue From This Account:"<<Total_Overdue<<endl;
                cout<<">> No. of Dents Caused:"<<Dents_Caused<<endl;
                cout<<">> No. of Scratches Caused:"<<Scratches_Caused<<endl;
                cout<<">> Total Amount to be paid for damages caused:"<<Damage_Cost<<endl;
                cout<<">> This account is eligibilie to book cars:"<<Eligibility<<endl;
                cout<<">> No. of Cars currently rented:"<<Cars_Rented<<endl;
            }
        }

        void Rented_Cars()
        {
            for(int ite=0;ite<Total_No_Of_Cars;ite++)
            {
                if(Cars_Present[ite].Renter_ID==User_ID && Cars_Present[ite].On_Rent=="Yes" && Cars_Present[ite].Status=="Active")
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    cout<<">> Booked Car ID:"<<Cars_Present[ite].Car_ID<<endl;
                    cout<<">> Start Date:"<<Cars_Present[ite].Start_Date<<endl;
                    cout<<">> End Date:"<<Cars_Present[ite].End_Date<<endl;
                    cout<<">> Current No. of Days:"<<Cars_Present[ite].Current_No_Of_Days<<endl;
                    cout<<">> Current Payment Due:"<<Cars_Present[ite].Current_Payment_Due<<endl;
                }
            }
        }

        void Clear_Dues()
        {
            string User_Class_Clear_Dues_ID;
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Enter the ID of the Booking you wish to clear:"<<endl;
            cin>>User_Class_Clear_Dues_ID;
            if(Cars_Present[Cars_Map[User_Class_Clear_Dues_ID]].Renter_ID!=User_ID)
            {
                cout<<">> You have not booked this car!"<<endl;
                Clear_Dues();
                return;
            }
            else
            {
                Total_Rented+=Date_Difference(Cars_Present[Cars_Map[User_Class_Clear_Dues_ID]].End_Date, Cars_Present[Cars_Map[User_Class_Clear_Dues_ID]].Start_Date);
                if(Date_Difference(Current_Date, Cars_Present[Cars_Map[User_Class_Clear_Dues_ID]].End_Date)>0)
                {
                    Total_Overdue+=Date_Difference(Current_Date, Cars_Present[Cars_Map[User_Class_Clear_Dues_ID]].End_Date);
                }
                Damage_Cost+=Cars_Present[Cars_Map[User_Class_Clear_Dues_ID]].Clear_Dues_Car();
                Cars_Rented--;
                cout<<">> Dues Cleared"<<endl;
            }

        }

        void Update_Profile()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Select an attribute to update:"<<endl;
            cout<<">> 1. First Name"<<endl;
            cout<<">> 2. Last Name"<<endl;
            cout<<">> 3. Password"<<endl;
            cout<<">> 4. Age"<<endl;
            cout<<">> 5. Gender"<<endl;
            cout<<">> 6. Personal Email ID"<<endl;
            cout<<">> 7. Phone No."<<endl;
            cout<<">> 8. Driving License No."<<endl;
            string User_Class_Update_Profile;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>User_Class_Update_Profile;
                wrong++;
            } while (!Contains_Digits(User_Class_Update_Profile));

            int User_Class_Update_Profile_Int=stoi(User_Class_Update_Profile);

            switch(User_Class_Update_Profile_Int)
            {
                case 1:
                {
                    cout<<">> Enter the new First Name:"<<endl;
                    cin>>First_Name;
                    break;
                }
                case 2:
                {
                    cout<<">> Enter the new Last Name:"<<endl;
                    cin>>Last_Name;
                    break;
                }
                case 3:
                {
                    cout<<">> Enter the new Password:"<<endl;
                    cin>>Password;
                    break;
                }
                case 4:
                {
                    do
                    {
                        cout<<">> Enter the new Age(>=18):"<<endl;
                        cin>>Age;
                    } while (Age<18);
                    break;
                }
                case 5:
                {
                    do
                    {
                        cout<<">> Enter the new Gender: Male, Female, Transgender or Prefer_Not_To_Say"<<endl;
                        cin>>Gender;
                    }while(Gender!="Female" && Gender!="Male"  && Gender!="Transgender" && Gender!="Prefer_Not_To_Say");
                    break;
                }
                case 6:
                {
                    cout<<">> Enter the new Personal Email ID:"<<endl;
                    cin>>Personal_Email;
                    break;
                }
                case 7:
                {
                    do
                    {
                        cout<<">> Enter the new Phone No.:"<<endl;
                        cin>>Phone_No;
                    }while(to_string(Phone_No).length()!=10);
                    break;
                }
                case 8:
                {
                    do
                    {
                        cout<<">> Enter the new Driving License No.(13 digits):"<<endl;
                        cin>>DL_No;
                    }while(DL_No.length()!=13);
                    break;
                }
                default:
                {
                    cout<<">> Invalid Option Selected"<<endl;
                    Update_Profile();
                    break;
                }
            }
            
        }
        
        void Update_Eligibility()
        {
            int score=(Total_Rented-Total_Overdue)*10000-Damage_Cost;
            if(score>=5000)
            {
                Eligibility=10;
            }
            else if(score>=2500)
            {
                Eligibility=8;
            }
            else if(score>=0)
            {
                Eligibility=5;
            }
            else Eligibility=2;
        }

        string Get_Password() const
        {
            return Password;
        }

        int Calculate_Cars_Rented()
        {
            Cars_Rented=0;
            for(int ite=0;ite<Total_No_Of_Cars;ite++)
            {
                if(Cars_Present[ite].Renter_ID==User_ID && Cars_Present[ite].On_Rent=="Yes" && Cars_Present[ite].Status=="Active")
                {
                    Cars_Rented++;
                }
            }
            return Cars_Rented;
        }

        virtual ~User_Class() = default;
};
int Viable_Date(string Input_Date);

unordered_map<string, int> Employees_Map;
int Total_No_Of_Employees;
int Total_No_Of_Employees_AllTime;
class Employee_Class: public User_Class
{
    public:
        int Employee_Score;
        string Official_Email;

        Employee_Class(){;}

        Employee_Class(string User_ID,string Password, string First_Name, string Last_Name, int Age, string Gender, string Official_Email, string Personal_Email, long long Phone_No, string DL_No, int Total_Rented, int Total_Overdue, int Dents_Caused, int Scratches_Caused, long long Damage_Cost,int Cars_Rented, int Employee_Score, int Discount,int Eligibility) : User_Class( User_ID, Password, First_Name, Last_Name, Age, Gender, Personal_Email, Phone_No,DL_No, Total_Rented, Total_Overdue, Dents_Caused, Scratches_Caused, Damage_Cost,Cars_Rented, Discount, Eligibility)
        {
            this->Employee_Score=Employee_Score;
            this->Official_Email=Official_Email;
        }

        int Employee_SignUp()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            if(SignUp("EMP",Total_No_Of_Employees_AllTime))
            {
                cout<<">> Please enter the Official Email ID:"<<endl;  
                cin>>Official_Email;
                cout<<">> The User ID is "<<User_ID<<endl;
                Employee_Score=0;
                Discount=15;
                return 1;
            }
            else return 0;
        }

        void View_Profile()
        {
            if(Status=="Active")
            {
                cout<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<endl;
                cout<<">> User ID:"<<User_ID<<endl;
                cout<<">> First Name:"<<First_Name<<endl;
                cout<<">> Last Name:"<<Last_Name<<endl;
                cout<<">> Age:"<<Age<<endl;
                cout<<">> Gender:"<<Gender<<endl;
                cout<<">> Personal Email ID:"<<Personal_Email<<endl;
                cout<<">> Official Email ID:"<<Official_Email<<endl;
                cout<<">> Phone No.:"<<Phone_No<<endl;
                cout<<">> Driving License No.:"<<DL_No<<endl;
                cout<<">> Total No. of Days Rented From This Account:"<<Total_Rented<<endl;
                cout<<">> Total No. of Days Overdue From This Account:"<<Total_Overdue<<endl;
                cout<<">> No. of Dents Caused:"<<Dents_Caused<<endl;
                cout<<">> No. of Scratches Caused:"<<Scratches_Caused<<endl;
                cout<<">> Total Amount to be paid for damages caused:"<<Damage_Cost<<endl;
                cout<<">> This account is eligibilie to book cars:"<<Eligibility<<endl;
                cout<<">> No. of Cars currently rented:"<<Cars_Rented<<endl;
                cout<<">> Discount:"<<Discount<<endl;
                cout<<">> Total Sale:"<<Employee_Score<<endl;
            }
        }
        void Navbar()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Please Select An Option:"<<endl;
            cout<<">> 1. Book Car"<<endl;
            cout<<">> 2. View Profile"<<endl;
            cout<<">> 3. View Rented Cars"<<endl;
            cout<<">> 4. Clear Dues"<<endl;
            cout<<">> 5. Update Profile"<<endl;
            cout<<">> 6. Logout"<<endl;

            string User_Input_Navbar;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>User_Input_Navbar;
                wrong++;
            } while (!Contains_Digits(User_Input_Navbar));

            int User_Input_Navbar_Int=stoi(User_Input_Navbar);
            switch(User_Input_Navbar_Int)
            {
                case 1:
                {
                    Calculate_Cars_Rented();
                    if(Cars_Rented<Eligibility)
                    {
                        cout<<endl;
                        cout<<"---------------------------------"<<endl;
                        cout<<endl;
                        Booking();
                        string Employee_Class_Booking_Car_ID;
                        string Employee_Class_Booking_End_Date;
                        cout<<">> Enter the ID of the car you wish to book:"<<endl;
                        cin>>Employee_Class_Booking_Car_ID;
                        do
                        {
                            cout<<">> Enter the End date in the form ddmmyyyy:"<<endl;
                            cin>>Employee_Class_Booking_End_Date;
                        } while (Date_Difference(Current_Date, Employee_Class_Booking_End_Date)<1 || Date_Difference(Current_Date, Employee_Class_Booking_End_Date)>15 || !Viable_Date(Employee_Class_Booking_End_Date));
                        

                        //Update the car class
                        Cars_Present[Cars_Map[Employee_Class_Booking_Car_ID]].Book_Car(Employee_Class_Booking_End_Date, Discount, User_ID, User_ID);

                        //update the managing employee's score and discount
                        Employee_Score+=Cars_Present[Cars_Map[Employee_Class_Booking_Car_ID]].Base_Payment;
                        Update_Discount();
                        Calculate_Cars_Rented();
                        cout<<">> Booking Done"<<endl;
                        Navbar();
                    }
                    else
                    {
                        cout<<endl;
                        cout<<"---------------------------------"<<endl;
                        cout<<endl;
                        cout<<">> You have reached the maximum number of cars that can be booked"<<endl;
                        Navbar();
                    }
                    break;
                }
                case 2:
                {
                    View_Profile();
                    Navbar();
                    break;
                }
                case 3:
                {
                    Rented_Cars();
                    Navbar();
                    break;
                }
                case 4:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    Clear_Dues();
                    Update_Eligibility();
                    cout<<">> This Account Can Book Cars: "<<Eligibility<<endl;
                    Navbar();
                    break;
                }
                case 5:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    char Employee_Class_Update_Profile='Y';
                    do
                    {
                        Update_Profile();
                        do
                        {
                            cout<<">> Do you wish to edit more attributes? (Y/N)"<<endl;
                            cin>>Employee_Class_Update_Profile;
                        }while(Employee_Class_Update_Profile!='Y' && Employee_Class_Update_Profile!='N');
                    }while(Employee_Class_Update_Profile=='Y');
                    Navbar();
                    break;
                }
                case 6:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    cout<<">> Logging Out"<<endl;
                    return;
                }
                default:
                {
                    cout<<">> Invalid Entry"<<endl;
                    Navbar();
                    break;
                }
            }
        }

        void Update_Discount()
        {
            if(Employee_Score>200000)
            {
                Discount=25;
            }
            else if(Employee_Score>100000)
            {
                Discount=20;
            }
            else if(Employee_Score>50000)
            {
                Discount=18;
            }
            else
            {
                Discount=15;
            }
        }

};
vector<Employee_Class> Employees_Present;
int Is_Member_Employees_Present(string Employee_ID);

unordered_map<string, int> Customers_Map;
int Total_No_Of_Customers;  //length of the vector Customers_Present
int Total_No_Of_Customers_AllTime;  //required for creating ID
class Customer_Class: public User_Class
{
    public:

        Customer_Class(){;}

        Customer_Class(string User_ID,string Password, string First_Name, string Last_Name, int Age,string Gender, string Personal_Email, long long Phone_No, string DL_No, int Total_Rented, int Total_Overdue, int Dents_Caused, int Scratches_Caused, long long Damage_Cost,int Cars_Rented, int Discount,int Eligibility) : User_Class( User_ID, Password, First_Name, Last_Name, Age, Gender, Personal_Email, Phone_No,DL_No, Total_Rented, Total_Overdue, Dents_Caused, Scratches_Caused, Damage_Cost,Cars_Rented, Discount, Eligibility)
        {
            ;
        }

        int Customer_SignUp()
        {
            if(SignUp("CUS",Total_No_Of_Customers_AllTime))
            {
                cout<<">> The User ID is "<<User_ID<<endl;
                Discount=0;
                return 1;
            }
            else return 0; 
        }

        void Navbar()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Please Select An Option:"<<endl;
            cout<<">> 1. Book Car"<<endl;
            cout<<">> 2. View Profile"<<endl;
            cout<<">> 3. View Rented Cars"<<endl;
            cout<<">> 4. Clear Dues"<<endl;
            cout<<">> 5. Update Profile"<<endl;
            cout<<">> 6. Logout"<<endl;
            string User_Input_Navbar;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>User_Input_Navbar;
                wrong++;
            } while (!Contains_Digits(User_Input_Navbar));

            int User_Input_Navbar_Int=stoi(User_Input_Navbar);

            switch(User_Input_Navbar_Int)
            {
                case 1:
                {
                    Calculate_Cars_Rented();
                    if(Cars_Rented<Eligibility)
                    {
                        cout<<endl;
                        cout<<"---------------------------------"<<endl;
                        cout<<endl;
                        Booking();
                        string Customer_Class_Booking_Car_ID;
                        string Customer_Class_Booking_End_Date;
                        string Customer_Class_Managing_Employee_ID;
                        cout<<">> Enter the ID of the car you wish to book:"<<endl;
                        cin>>Customer_Class_Booking_Car_ID;
                        
                        do
                        {
                            cout<<">> Enter the End date in the form ddmmyyyy:"<<endl;
                            cin>>Customer_Class_Booking_End_Date;
                        }while(Date_Difference(Current_Date, Customer_Class_Booking_End_Date)<1|| Date_Difference(Current_Date, Customer_Class_Booking_End_Date)>15 || !Viable_Date(Customer_Class_Booking_End_Date));

                        do{
                            cout<<">> Enter the ID of the Employee managing your booking:"<<endl;
                            cin>>Customer_Class_Managing_Employee_ID;
                        }while(!Is_Member_Employees_Present(Customer_Class_Managing_Employee_ID));

                        //Update Car Class
                        Cars_Present[Cars_Map[Customer_Class_Booking_Car_ID]].Book_Car(Customer_Class_Booking_End_Date, Discount, User_ID, Customer_Class_Managing_Employee_ID);
                        Calculate_Cars_Rented();

                        //Update Managing Employee Class
                        Employees_Present[Employees_Map[Customer_Class_Managing_Employee_ID]].Employee_Score+=Cars_Present[Cars_Map[Customer_Class_Booking_Car_ID]].Base_Payment;
                        Employees_Present[Employees_Map[Customer_Class_Managing_Employee_ID]].Update_Discount();
                        cout<<"Booking Done"<<endl;
                        Navbar();
                        break;
                    }
                    else
                    {
                        cout<<endl;
                        cout<<"---------------------------------"<<endl;
                        cout<<endl;
                        cout<<">> You have reached the maximum number of cars that can be booked"<<endl;
                        Navbar();
                        break;
                    }
                }
                case 2:
                {
                    View_Profile();
                    Navbar();
                    break;
                }
                case 3:
                {
                    Rented_Cars();
                    Navbar();
                    break;
                }
                case 4:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    Clear_Dues();
                    Update_Eligibility();
                    cout<<"This Account Can Book Cars: "<<Eligibility<<endl;
                    Navbar();
                }
                case 5:
                {
                    char Customer_Class_Update_Profile='Y';
                    do
                    {
                        Update_Profile();
                        do
                        {
                            cout<<">> Do you wish to edit more attributes? (Y/N)"<<endl;
                            cin>>Customer_Class_Update_Profile;
                        }while(Customer_Class_Update_Profile!='Y' && Customer_Class_Update_Profile!='N');
                    }while(Customer_Class_Update_Profile=='Y');
                    Navbar();
                    break;
                }
                case 6:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    cout<<">> Logging Out"<<endl;
                    return;
                }
                default:
                {
                    cout<<"Invalid Entry"<<endl;
                    Navbar();
                    break;
                }
            }
        }

};
vector<Customer_Class> Customers_Present;
int Is_Member_Customers_Present(string Customer_ID);

unordered_map<string, int> Managers_Map;
int Total_No_Of_Managers;
int Total_No_Of_Managers_AllTime;
class Manager_Class: public User_Class
{
    public:

        Manager_Class(){;}

        Manager_Class(string User_ID,string Password, string First_Name, string Last_Name) 
        {
            this->User_ID=User_ID;
            this->Password=Password;
            this->First_Name=First_Name;
            this->Last_Name=Last_Name;
            this->Status="Active";
        }

        void Manager_SignUp(){;}
        void View_Profile(){;}

        void Navbar()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Please Select An Option:"<<endl;
            cout<<">> 1. Add Customer"<<endl;
            cout<<">> 2. Add Employee"<<endl;
            cout<<">> 3. Add Car"<<endl;
            cout<<">> 4. Remove Customer"<<endl;
            cout<<">> 5. Remove Employee"<<endl;
            cout<<">> 6. Remove Car"<<endl;
            cout<<">> 7. View all Customers"<<endl;
            cout<<">> 8. View all Employees"<<endl;
            cout<<">> 9. View all Cars"<<endl;
            cout<<">> 10. Update Customer"<<endl;
            cout<<">> 11. Update Employee"<<endl;
            cout<<">> 12. Update Car"<<endl;
            cout<<">> 13. Fix Car"<<endl;
            cout<<">> 14. Logout"<<endl;

            string User_Input_Navbar;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>User_Input_Navbar;
                wrong++;
            } while (!Contains_Digits(User_Input_Navbar));

            int User_Input_Navbar_Int=stoi(User_Input_Navbar);

            switch(User_Input_Navbar_Int)
            {
                case 1:
                {
                    Add_Customer();
                    cout<<">> Customer Added"<<endl;
                    Navbar();
                    break;
                }
                case 2:
                {
                    Add_Employee();
                    cout<<">> Employee Added"<<endl;
                    Navbar();
                    break;
                }
                case 3:
                {
                    Add_Car();
                    cout<<">> Car Added"<<endl;
                    Navbar();
                    break;
                }
                case 4:
                {
                    Remove_Customer();
                    Navbar();
                    break;
                }
                case 5:
                {
                    Remove_Employee();
                    Navbar();
                    break;
                }
                case 6:
                {
                    Remove_Car();
                    Navbar();
                    break;
                }
                case 7:
                {
                    for(int ite=0;ite<Customers_Present.size();ite++)
                    {
                        Customers_Present[ite].View_Profile();
                    }
                    Navbar();
                    break;
                }
                case 8:
                {
                    for(int ite=0;ite<Employees_Present.size();ite++)
                    {
                        Employees_Present[ite].View_Profile();
                    }
                    Navbar();
                    break;
                }
                case 9:
                {
                    for(int ite=0;ite<Cars_Present.size();ite++)
                    {
                        Cars_Present[ite].Display_Car();
                    }
                    Navbar();
                    break;
                }
                case 10:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    char Manager_Class_Update_Decision='Y';
                    string Manager_Class_Update_Customer_ID;
                    do
                    {
                        cout<<">> Enter the ID of the Customer you wish to update:"<<endl;
                        cin>>Manager_Class_Update_Customer_ID;
                        Customers_Present[Customers_Map[Manager_Class_Update_Customer_ID]].Update_Profile();
                        cout<<">> Customer Updated"<<endl;
                        do
                        {
                            cout<<">> Do you wish to edit more attributes? (Y/N)"<<endl;
                            cin>>Manager_Class_Update_Decision;
                        }while(Manager_Class_Update_Decision!='Y' && Manager_Class_Update_Decision!='N');
                    }while(Manager_Class_Update_Decision=='Y');
                    Navbar();
                    break;
                }
                case 11:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    char Manager_Class_Update_Decision='Y';
                    string Manager_Class_Update_Employee_ID;
                    do
                    {
                        cout<<">> Enter the ID of the Employee you wish to update:"<<endl;
                        cin>>Manager_Class_Update_Employee_ID;
                        Employees_Present[Employees_Map[Manager_Class_Update_Employee_ID]].Update_Profile();
                        cout<<">> Employee Updated"<<endl;
                        do{
                            cout<<">> Do you wish to edit more attributes? (Y/N)"<<endl;
                            cin>>Manager_Class_Update_Decision;
                        }while(Manager_Class_Update_Decision!='Y' && Manager_Class_Update_Decision!='N');
                    }while(Manager_Class_Update_Decision=='Y');
                    Navbar();
                    break;
                }
                case 12:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    char Manager_Class_Update_Decision='Y';
                    string Manager_Class_Update_Car_ID;
                    do
                    {
                        cout<<">> Enter the ID of the Car you wish to update:"<<endl;
                        cin>>Manager_Class_Update_Car_ID;
                        Cars_Present[Cars_Map[Manager_Class_Update_Car_ID]].Update_Car();
                        cout<<">> Car Updated"<<endl;
                        do
                        {
                            cout<<">> Do you wish to edit more attributes? (Y/N)"<<endl;
                            cin>>Manager_Class_Update_Decision;
                        }while(Manager_Class_Update_Decision!='Y' && Manager_Class_Update_Decision!='N');
                    }while(Manager_Class_Update_Decision=='Y');
                    Navbar();
                    break;
                }
                case 13:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    string Manager_Class_Fix_Car_ID;
                    cout<<">> Enter the ID of the Car you wish to fix:"<<endl;
                    cin>>Manager_Class_Fix_Car_ID;
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].No_Of_Dents=0;
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].No_Of_Scratches=0;
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Condition_Of_Headlights="Intact";
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Other_Remarks="None";
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Available_For_Rent="Yes";
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].On_Rent="No";
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Start_Date="0";
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].End_Date="0";
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Base_Payment=0;
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Current_No_Of_Days=0;
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Current_Payment_Due=0;
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Renter_ID="0";
                    Cars_Present[Cars_Map[Manager_Class_Fix_Car_ID]].Managing_Employee_ID="0";
                    cout<<">> Car Fixed"<<endl;
                    Navbar();
                    break;
                }
                case 14:
                {
                    cout<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                    cout<<">> Logging Out"<<endl;
                    return;
                }
                default:
                {
                    cout<<">> Invalid Entry"<<endl;
                    Navbar();
                    break;
                }
            }
        }
        void Add_Customer()
        {
            Customer_Class New_Customer;
            New_Customer.Customer_SignUp();
            Customers_Present.push_back(New_Customer);
            Customers_Map[New_Customer.User_ID] = Total_No_Of_Customers;
            Total_No_Of_Customers_AllTime++;
            Total_No_Of_Customers++; 
        }
        void Add_Employee()
        {
            Employee_Class New_Employee;
            if(New_Employee.Employee_SignUp())
            {
                Employees_Present.push_back(New_Employee);
                Employees_Map[New_Employee.User_ID] = Total_No_Of_Employees;
                Total_No_Of_Employees_AllTime++;
                Total_No_Of_Employees++; 
            }
            else
            {
                cout<<">> Add Employee Failed, Underage User"<<endl;
            }
        }

        void Remove_Customer()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            string Manager_Class_Remove_Customer_ID;
            cout<<">> Enter the ID of the Customer you wish to remove:"<<endl;
            cin>>Manager_Class_Remove_Customer_ID;
            if(Is_Member_Customers_Present(Manager_Class_Remove_Customer_ID))
            {
                Customers_Present[Customers_Map[Manager_Class_Remove_Customer_ID]].Status="Deactivated";
                cout<<">> Customer Removed"<<endl;
            }
        }

        void Remove_Employee()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            string Manager_Class_Remove_Employee_ID;
            cout<<">> Enter the ID of the Employee you wish to remove:"<<endl;
            cin>>Manager_Class_Remove_Employee_ID;
            if(Is_Member_Employees_Present(Manager_Class_Remove_Employee_ID))
            {
                Employees_Present[Employees_Map[Manager_Class_Remove_Employee_ID]].Status="Deactivated";
                cout<<">> Employee Removed"<<endl;
            }
        }

        void Add_Car()
        {
            Car_Class New_Car;
            New_Car.Add_Car();
            Cars_Present.push_back(New_Car);
            Cars_Map[New_Car.Car_ID] = Total_No_Of_Cars;
            Total_No_Of_Cars_AllTime++;
            Total_No_Of_Cars++;
        }

        void Remove_Car()
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            string Manager_Class_Remove_Car_ID;
            cout<<">> Enter the ID of the Car you wish to remove:"<<endl;
            cin>>Manager_Class_Remove_Car_ID;
            if(Is_Member_Cars_Present(Manager_Class_Remove_Car_ID))
            {
                Cars_Present[Cars_Map[Manager_Class_Remove_Car_ID]].Status="Deactivated";
                cout<<">> Car Removed"<<endl;
            }
        }

};
vector<Manager_Class> Managers_Present;









//---------------------------------
//            UTILITIES
//---------------------------------










void Create_Parameters()
{
    ifstream file("parameters.csv");
    string line;
    char comma;
    getline(file, line);
    if(getline(file, line))
    {
        stringstream ss(line);
        ss>>Total_No_Of_Cars_AllTime>>comma>>Total_No_Of_Customers_AllTime>>comma>>Total_No_Of_Employees_AllTime>>comma>>Total_No_Of_Managers_AllTime>>comma>>Current_Date;
    }
    file.close();
}

void Create_Cars_Present()
{
    Total_No_Of_Cars = 0;
    ifstream file("car_database.csv");
    string line;
    getline(file, line);
    char comma;
    while (getline(file, line))
    {
        string Car_ID;
        string Car_Plate_No;
        string Company;
        string Model;
        string Engine;
        int Engine_Size;
        string Power_Output;
        float Litres_p100kms;
        string Transmission;
        int Kilometres_Driven;
        int Seating_Capacity;
        int No_Of_Airbags;
        string Air_Conditioning;
        string Infotainment_System;
        string Colour;
        int No_Of_Dents;
        int No_Of_Scratches;
        string Condition_Of_Headlights;
        string Other_Remarks;
        long long Booking_Charge_Day;
        long long Overdue_Charge;
        long long Damage_Cost;
        string Available_For_Rent;
        string On_Rent;
        string Start_Date;
        string End_Date;
        long long Base_Payment;
        int Current_No_Of_Days;
        long long Current_Payment_Due;
        string Renter_ID;
        string Managing_Employee_ID;
        istringstream iss(line);
        iss>>Car_ID>>comma>>Car_Plate_No>>comma>>Company>>comma>>Model>>comma>>Engine>>comma>>Engine_Size>>comma>>Power_Output>>comma>>Litres_p100kms>>comma>>Transmission>>comma>>Kilometres_Driven>>comma>>Seating_Capacity>>comma>>No_Of_Airbags>>comma>>Air_Conditioning>>comma>>Infotainment_System>>comma>>Colour>>comma>>No_Of_Dents>>comma>>No_Of_Scratches>>comma>>Condition_Of_Headlights>>comma>>Other_Remarks>>comma>>Booking_Charge_Day>>comma>>Overdue_Charge>>comma>>Damage_Cost>>comma>>Available_For_Rent>>comma>>On_Rent>>comma>>Start_Date>>comma>>End_Date>>comma>>Base_Payment>>comma>>Current_No_Of_Days>>comma>>Current_Payment_Due>>comma>>Renter_ID>>comma>>Managing_Employee_ID;
        Car_Class New_Car(Car_ID, Car_Plate_No, Company, Model, Engine, Engine_Size, Power_Output, Litres_p100kms, Transmission, Kilometres_Driven, Seating_Capacity, No_Of_Airbags, Air_Conditioning, Infotainment_System, Colour, No_Of_Dents, No_Of_Scratches, Condition_Of_Headlights, Other_Remarks, Booking_Charge_Day, Overdue_Charge, Damage_Cost,Available_For_Rent, On_Rent, Start_Date, End_Date, Base_Payment, Current_No_Of_Days, Current_Payment_Due, Renter_ID, Managing_Employee_ID);
        Cars_Present.push_back(New_Car);
        Cars_Map[Car_ID] = Total_No_Of_Cars;
        Total_No_Of_Cars++;
    }
    file.close();
}

void Create_Customers_Present()
{
    Total_No_Of_Customers = 0;
    ifstream file("customer_database.csv");
    string line;
    getline(file, line);
    char comma;
    while (getline(file, line))
    {
        string Customer_ID;
        string Password;
        string First_Name;
        string Last_Name;
        int Age;
        string Gender;
        string Personal_Email;
        long long Phone_No;
        string DL_No;
        int Total_Rented;
        int Total_Overdue;
        int Dents_Caused;
        int Scratches_Caused;
        long long Damage_Cost;
        int Cars_Rented;
        int Discount;
        int Eligibility;
        istringstream iss(line);
        iss>>Customer_ID>>comma>>Password>>comma>>First_Name>>comma>>Last_Name>>comma>>Age>>comma>>Gender>>comma>>Personal_Email>>comma>>Phone_No>>comma>>DL_No>>comma>>Total_Rented>>comma>>Total_Overdue>>comma>>Dents_Caused>>comma>>Scratches_Caused>>comma>>Damage_Cost>>comma>>Cars_Rented>>comma>>Discount>>comma>>Eligibility;
        Customer_Class New_Customer(Customer_ID, Password, First_Name, Last_Name, Age,Gender, Personal_Email, Phone_No, DL_No, Total_Rented, Total_Overdue, Dents_Caused, Scratches_Caused, Damage_Cost, Cars_Rented, Discount, Eligibility);
        Customers_Present.push_back(New_Customer);
        Customers_Map[Customer_ID] = Total_No_Of_Customers;
        Total_No_Of_Customers++;
    }
    file.close(); 
}

void Create_Employees_Present()
{
    Total_No_Of_Employees = 0;
    ifstream file("employee_database.csv");
    string line;
    getline(file, line);
    char comma;
    while (getline(file, line))
    {
        string Employee_ID;
        string Password;
        string First_Name;
        string Last_Name;
        int Age;
        string Gender;
        string Official_Email;
        string Personal_Email;
        long long Phone_No;
        string DL_No;
        int Total_Rented;
        int Total_Overdue;
        int Dents_Caused;
        int Scratches_Caused;
        long long Damage_Cost;
        int Cars_Rented;
        int Employee_Score;
        int Discount;
        int Eligibility ;
        istringstream iss(line);
        iss>>Employee_ID>>comma>>Password>>comma>>First_Name>>comma>>Last_Name>>comma>>Age>>comma>>Gender>>comma>>Official_Email>>comma>>Personal_Email>>comma>>Phone_No>>comma>>DL_No>>comma>>Total_Rented>>comma>>Total_Overdue>>comma>>Dents_Caused>>comma>>Scratches_Caused>>comma>>Damage_Cost>>comma>>Cars_Rented>>comma>>Employee_Score>>comma>>Discount>>comma>>Eligibility;
        Employee_Class New_Employee(Employee_ID, Password, First_Name, Last_Name, Age,Gender, Official_Email, Personal_Email, Phone_No, DL_No, Total_Rented, Total_Overdue, Dents_Caused, Scratches_Caused, Damage_Cost, Cars_Rented, Employee_Score, Discount, Eligibility);
        Employees_Present.push_back(New_Employee);
        Employees_Map[Employee_ID] = Total_No_Of_Employees;
        Total_No_Of_Employees++;
    }
    file.close(); 
}

void Create_Managers_Present()
{
    Total_No_Of_Managers = 0;
    ifstream file("manager_database.csv");
    string line;
    char comma;
    getline(file, line);
    while (getline(file, line))
    {
        string Manager_ID;
        string Password;
        string First_Name;
        string Last_Name;
        istringstream iss(line);
        iss>>Manager_ID>>comma>>Password>>comma>>First_Name>>comma>>Last_Name;
        Manager_Class New_Manager(Manager_ID, Password, First_Name, Last_Name);
        Managers_Present.push_back(New_Manager);
        Managers_Map[Manager_ID] = Total_No_Of_Managers;
        Total_No_Of_Managers++;
    }
    file.close();
}

void Update_Cars_Present()
{
    for(int ite=0;ite<Cars_Present.size();ite++)
    {
        if(Cars_Present[ite].On_Rent=="Yes")
        {
            Cars_Present[ite].Update_Booking();
        }
    }
}

int Is_Member_Cars_Present(string Car_ID)
{
    for(int ite=0;ite<Cars_Present.size();ite++)
    {
        if(Cars_Present[ite].Car_ID==Car_ID)
        {
            return 1;            
        }
    }
    cout<<">> Invalid Car ID"<<endl;
    return 0;
}

int Is_Member_Employees_Present(string Employee_ID)
{
    for(int ite=0;ite<Employees_Present.size();ite++)
    {
        if(Employees_Present[ite].User_ID==Employee_ID)
        {
            return 1;            
        }
    }
    cout<<">> Invalid Employee ID"<<endl;
    return 0;
}

int Is_Member_Customers_Present(string Customer_ID)
{
    for(int ite=0;ite<Customers_Present.size();ite++)
    {
        if(Customers_Present[ite].User_ID==Customer_ID)
        {
            return 1;            
        }
    }
    cout<<">> Invalid Customer ID"<<endl;
    return 0;
}

void Update_Car_Database()
{
    ofstream outputFile("car_database.csv");
    outputFile<<"Car_ID, Car_Plate_No, Company, Model, Engine, Engine_Size, Power_Output, Litres_p100kms, Transmission, Kilometres_Driven, Seating_Capacity, No_Of_Airbags, Air_Conditioning, Infotainment_System, Colour, No_Of_Dents, No_Of_Scratches, Condition_Of_Headlights, Other_Remarks, Booking_Charge_Day, Overdue_Charge, Damage_Cost,Available_For_Rent, On_Rent, Start_Date, End_Date, Base_Payment, Current_No_Of_Days, Current_Payment_Due, Renter_ID, Managing_Employee_ID";
    for(int ite=0;ite<Total_No_Of_Cars;ite++)
    {
        if(Cars_Present[ite].Status=="Active")
        {
            outputFile<<endl;
            outputFile<<Cars_Present[ite].Car_ID<<" ,"<<Cars_Present[ite].Car_Plate_No<<" ,"<<Cars_Present[ite].Company<<" ,"<<Cars_Present[ite].Model<<" ,"<<Cars_Present[ite].Engine<<" ,"<<Cars_Present[ite].Engine_Size<<" ,"<<Cars_Present[ite].Power_Output<<" ,"<<Cars_Present[ite].Litres_p100kms<<" ,"<<Cars_Present[ite].Transmission<<" ,"<<Cars_Present[ite].Kilometres_Driven<<" ,"<<Cars_Present[ite].Seating_Capacity<<" ,"<<Cars_Present[ite].No_Of_Airbags<<" ,"<<Cars_Present[ite].Air_Conditioning<<" ,"<<Cars_Present[ite].Infotainment_System<<" ,"<<Cars_Present[ite].Colour<<" ,"<<Cars_Present[ite].No_Of_Dents<<" ,"<<Cars_Present[ite].No_Of_Scratches<<" ,"<<Cars_Present[ite].Condition_Of_Headlights<<" ,"<<Cars_Present[ite].Other_Remarks<<" ,"<<Cars_Present[ite].Booking_Charge_Day<<" ,"<<Cars_Present[ite].Overdue_Charge<<" ,"<<Cars_Present[ite].Damage_Cost<<" ,"<<Cars_Present[ite].Available_For_Rent<<" ,"<<Cars_Present[ite].On_Rent<<" ,"<<Cars_Present[ite].Start_Date<<" ,"<<Cars_Present[ite].End_Date<<" ,"<<Cars_Present[ite].Base_Payment<<" ,"<<Cars_Present[ite].Current_No_Of_Days<<" ,"<<Cars_Present[ite].Current_Payment_Due<<" ,"<<Cars_Present[ite].Renter_ID<<" ,"<<Cars_Present[ite].Managing_Employee_ID; 
        }   
    }
    outputFile.close();
}

void Update_Customer_Database()
{
   ofstream outputFile("customer_database.csv");
   outputFile<<"Customer_ID ,Password ,First_Name ,Last_Name ,Age ,Gender ,Personal_Email ,Phone_No ,DL_No ,Total_Rented ,Total_Overdue ,Dents_Caused ,Scratches_Caused ,Damage_Cost ,Cars_Rented ,Discount ,Eligibility ";
   for(int ite=0;ite<Total_No_Of_Customers;ite++)
   {
        if(Customers_Present[ite].Status=="Active")
        {
            outputFile<<endl;
            int Cars_Rented_Stored=Customers_Present[ite].Calculate_Cars_Rented();
            outputFile<<Customers_Present[ite].User_ID<<" ,"<<Customers_Present[ite].Get_Password()<<" ,"<<Customers_Present[ite].First_Name<<" ,"<<Customers_Present[ite].Last_Name<<" ,"<<Customers_Present[ite].Age<<" ,"<<Customers_Present[ite].Gender<<" ,"<<Customers_Present[ite].Personal_Email<<" ,"<<Customers_Present[ite].Phone_No<<" ,"<<Customers_Present[ite].DL_No<<" ,"<<Customers_Present[ite].Total_Rented<<" ,"<<Customers_Present[ite].Total_Overdue<<" ,"<<Customers_Present[ite].Dents_Caused<<" ,"<<Customers_Present[ite].Scratches_Caused<<" ,"<<Customers_Present[ite].Damage_Cost<<" ,"<<Cars_Rented_Stored<<" ,"<<Customers_Present[ite].Discount<<" ,"<<Customers_Present[ite].Eligibility;
        }
   }
   outputFile.close();
}


void Update_Employee_Database()
{
   ofstream outputFile("employee_database.csv");
   outputFile<<"Employee_ID ,Password ,First_Name ,Last_Name ,Age ,Gender ,Official_Email ,Personal_Email ,Phone_No ,DL_No ,Total_Rented ,Total_Overdue ,Dents_Caused ,Scratches_Caused ,Damage_Cost ,Cars_Rented ,Employee_Score ,Discount ,Eligibility ";
   for(int ite=0;ite<Total_No_Of_Employees;ite++)
   {
        if(Employees_Present[ite].Status=="Active")
        {
            outputFile<<endl;
            int Cars_Rented_Stored=Employees_Present[ite].Calculate_Cars_Rented();
            outputFile<<Employees_Present[ite].User_ID<<" ,"<<Employees_Present[ite].Get_Password()<<" ,"<<Employees_Present[ite].First_Name<<" ,"<<Employees_Present[ite].Last_Name<<" ,"<<Employees_Present[ite].Age<<" ,"<<Employees_Present[ite].Gender<<" ,"<<Employees_Present[ite].Official_Email<<" ,"<<Employees_Present[ite].Personal_Email<<" ,"<<Employees_Present[ite].Phone_No<<" ,"<<Employees_Present[ite].DL_No<<" ,"<<Employees_Present[ite].Total_Rented<<" ,"<<Employees_Present[ite].Total_Overdue<<" ,"<<Employees_Present[ite].Dents_Caused<<" ,"<<Employees_Present[ite].Scratches_Caused<<" ,"<<Employees_Present[ite].Damage_Cost<<" ,"<<Cars_Rented_Stored<<" ,"<<Employees_Present[ite].Employee_Score<<" ,"<<Employees_Present[ite].Discount<<" ,"<<Employees_Present[ite].Eligibility;
        }
   }
   outputFile.close();
}


void Update_Manager_Database()
{
   ofstream outputFile("manager_database.csv");
   outputFile<<"Manager_ID, Password, First_Name, Last_Name";
   for(int ite=0;ite<Total_No_Of_Managers;ite++)
   {
       outputFile<<endl;
       outputFile<<Managers_Present[ite].User_ID<<" ,"<<Managers_Present[ite].Get_Password()<<" ,"<<Managers_Present[ite].First_Name<<" ,"<<Managers_Present[ite].Last_Name;
   }
   outputFile.close();
}


void Update_Parameters()
{
    ofstream outputFile("parameters.csv");
    outputFile<<"Total_No_Of_Cars_AllTime ,Total_No_Of_Customers_AllTime ,Total_No_Of_Employees_AllTime ,Total_No_Of_Managers_AllTime ,Current_Date ";
    outputFile<<endl;
    outputFile<<Total_No_Of_Cars_AllTime<<" ,"<<Total_No_Of_Customers_AllTime<<" ,"<<Total_No_Of_Employees_AllTime<<" ,"<<Total_No_Of_Managers_AllTime<<" ,"<<Current_Date;
    outputFile.close();
}

template<typename T> string login(const vector<T>& users)
{
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
    string lUser_ID;
    string lPassword;  
    cout<<">> Please enter your User ID"<<endl;
    cin>>lUser_ID;
    cout<<">> Please enter your password"<<endl;
    cin>>lPassword;

    int status=0;

    for (const auto& user : users) 
    {
        if (user.User_ID==lUser_ID && user.Get_Password()==lPassword && user.Status=="Active") 
        {
            status=1;
            break;
        }
        else if(user.User_ID==lUser_ID && user.Get_Password()!=lPassword)
        {
            status=2;
            break;
        }
    }
    switch(status)
    {
        case 1:
        {
            return lUser_ID;
            break;
        }
        case 2:
        {
            cout<<">> Invalid Password"<<endl;
            return to_string(-1);
            break;
        }
        default:
        {
            cout<<">> Invalid User ID"<<endl;
            return to_string(-1);
            break;
        }
    }
}

int Viable_Date(string Input_date)
{
    int Flag=1;
    if(Input_date.length()!=8)
    {
        cout<<">> Invalid Date"<<endl;
        return 0;
    }
    else if(!Contains_Digits(Input_date))
    {
        cout<<">> Invalid Date"<<endl;
        return 0;
    }
    else
    {
        int Day=stoi(Input_date.substr(0,2));
        int Month=stoi(Input_date.substr(2,2));
        int Year=stoi(Input_date.substr(4,4));
        if(Month==1 && Day<=31 && Day>=0) return 1;
        else if(Month==2 && Day<=29 && Day>=0 && Year%4==0) return 1;
        else if(Month==2 && Day<=28 && Day>=0 && Year%4!=0) return 1;
        else if(Month==3 && Day<=31 && Day>=0) return 1;
        else if(Month==4 && Day<=30 && Day>=0) return 1;
        else if(Month==5 && Day<=31 && Day>=0) return 1;
        else if(Month==6 && Day<=30 && Day>=0) return 1;
        else if(Month==7 && Day<=31 && Day>=0) return 1;
        else if(Month==8 && Day<=31 && Day>=0) return 1;
        else if(Month==9 && Day<=30 && Day>=0) return 1;
        else if(Month==10 && Day<=31 && Day>=0) return 1;
        else if(Month==11 && Day<=30 && Day>=0) return 1;
        else if(Month==12 && Day<=31 && Day>=0) return 1;
        else
        {
            cout<<">> Invalid Date"<<endl;
            return 0;
        }
    }
}

void Update_Date()
{
    string Main_Program_Current_Date_Update;
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
    cout<<">> Is the current date "<<Current_Date.substr(0,2)<<"/"<<Current_Date.substr(2,2)<<"/"<<Current_Date.substr(4,8)<<" (Y/N)"<<endl;
    cin>>Main_Program_Current_Date_Update;

    if(Main_Program_Current_Date_Update=="Y") ;
    else if(Main_Program_Current_Date_Update=="N")
    {
        string Prev_Date=Current_Date;
        do
        {
            cout<<">> Please enter the current date in the format DDMMYYYY"<<endl;
            cin>>Current_Date;
        }while(!Viable_Date(Current_Date) || Date_Difference(Prev_Date ,Current_Date)<0);
        Update_Cars_Present();
    }
    else
    {
        cout<<">> Invalid Entry"<<endl;
        Update_Date();
    }
}

void User_Type()
{
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
    cout<<">> Please select the index corresponding to your profile type:"<<endl;
    cout<<">> 1. Customer"<<endl;
    cout<<">> 2. Employee"<<endl;
    cout<<">> 3. Manager"<<endl;
    cout<<">> 4. Exit"<<endl;
    string Main_Program_User_Type;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>Main_Program_User_Type;
                wrong++;
            } while (!Contains_Digits(Main_Program_User_Type));

    int Main_Program_User_Type_Int=stoi(Main_Program_User_Type);
    switch(Main_Program_User_Type_Int)  //insert error handling
    {
        case 1:
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">>Please Login or Sign Up:"<<endl;
            cout<<">> 1. Sign Up"<<endl;
            cout<<">> 2. Login"<<endl;
            string Main_Program_Customer_Profile_Entry;
            int wrong=0;
            do
            {
                if(wrong) cout<<">> Invalid Entry"<<endl;
                cin>>Main_Program_Customer_Profile_Entry;
                wrong++;
            } while (!Contains_Digits(Main_Program_Customer_Profile_Entry));

            int Main_Program_Customer_Profile_Entry_Int=stoi(Main_Program_Customer_Profile_Entry);
            switch(Main_Program_Customer_Profile_Entry_Int) //insert error handling
            {
                //SIGN UP FOR CUSTOMERS
                case 1:
                {
                    Customer_Class New_Customer;
                    if(New_Customer.Customer_SignUp())
                    {
                        Customers_Present.push_back(New_Customer);
                        Customers_Map[New_Customer.User_ID] = Total_No_Of_Customers;
                        Total_No_Of_Customers_AllTime++;
                        Total_No_Of_Customers++; 
                        New_Customer.Navbar();
                        User_Type();
                        break;
                    }   
                    else
                    {
                        cout<<">> Sign Up failed, Underage user"<<endl;
                        User_Type();
                        break;
                    }        
                }
                //LOGIN FOR CUSTOMERS
                case 2:
                { 
                    string status=login(Customers_Present);
                    if(status!="-1")
                    {
                        int Customer_Index=Customers_Map[status];
                        Customers_Present[Customer_Index].Navbar();
                        User_Type();
                    }
                    else User_Type();
                    break;
                }
                default:
                {
                    cout<<">> Invalid Entry"<<endl;
                    User_Type();
                    break;
                }  
            }
            break;
        }
        //LOGIN FOR EMPLOYEES
        case 2:
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Please Login!"<<endl;
            string status=login(Employees_Present);
            if(status!="-1")
            {
                int Employee_Index=Employees_Map[status];
                Employees_Present[Employee_Index].Navbar();
                User_Type();
            }
            else User_Type();
            break;
        }
        //LOGIN FOR MANAGERS
        case 3:
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Please Login!"<<endl;
            string status=login(Managers_Present);
            if(status!="-1")
            {
                int Manager_Index=Managers_Map[status];
                Managers_Present[Manager_Index].Navbar();
                User_Type();
            }
            else User_Type();
            break;
        }
        //EXIT
        case 4:
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Thanks for visiting!"<<endl;
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            break;
        }
        //INVALID ENTRY
        default:
        {
            cout<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout<<">> Invalid Entry"<<endl;
            User_Type();
            break;
        }
    }
}

