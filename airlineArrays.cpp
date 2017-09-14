// Author     :      Kekeli dos Akouete
// File       :      airlineArrays.cpp
// Description:      A plane ticket purchase program
// IDE used   :      NetBeans IDE8.1




#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>

using namespace std;

#include "array.h"

const int TOTALSEAT = 36;



void displayPlane(char [ROW][COL]);
// Display the title of the airline 
// Display the the available seat to be purchased
void getData(int & row , char & seat );
// read input from the user
// the reference of row and seat are supplied to main
int getSeat();
// obtain the seat in each class and track it in an array
// counts the number of "X" in it
void displaySales(int SeatSold);
// display the number of seats sold
// and the percentage occupied when user enter -1

void displaySlsRpt (int classCtr[], string classes[], double fare[] );
// uses the three arrays to produce a sales report
// the total of each class, the fare and the classCtr are displayed in main




int main()
{
using namespace std;



int Row,indexSeat,SeatSold;
char Seat;


displayPlane(layout);
getData(Row,Seat);
while( Row > 0)
{
// converting the rows and seats to legal indices 
// and assigning X to the chosen seats  
  
Row -= 1;
indexSeat = Seat - 65;
if(layout[Row][indexSeat] == 'X')
    cout << "  The seat is taken! "<< endl;
else
{
  for(int i = 0; i < ROW; i++)
    {
       for( int c = 0; c < COL; c++)
         {
          
           layout[Row ][indexSeat] = 'X';
         }
    } 
}

    
displayPlane(layout);


  getData(Row,Seat); 
}  

// the sales report goes here
displaySales(SeatSold);
displaySlsRpt(classCtr,classes,fare);

return 0;
}



void displayPlane( char [ROW][COL])
{
    using namespace std;
// title of the airline
    cout <<"\n        Chesapeake Airlines        "<< endl << endl;    
// display available seats in rows and columns
   for(int index = 0; index < ROW ; index++)
    {
        cout << setw(5) << index + 1 ;
        for(int i = 0; i < COL; i++)
        {
          cout  << setw(5) << layout[index][i] << " ";
        }  
        cout << endl;
    }
    return;
}

void getData(int& Row, char& Seat)
{
    using namespace std;    
    cout << endl;
    cout << "Enter  a row: or -1 to stop>  ";
    cin >> Row;
 if(Row > 0)
   {   
// character are converted from lower case to uppercase 
       cout << "Enter  a seat letter A-D:   ";
       cin >> Seat;
       if(Seat == 'a')
           Seat = toupper('a');
       else if(Seat == 'b')
           Seat = toupper('b');
       else if(Seat == 'c')
           Seat = toupper('c');
       else 
           Seat = toupper('d');
   }    
 else
       return; 
}

int getSeat()
{
    using namespace std;
    
    int totalSeat = 0;
    int first = 0, business = 0, coach = 0;
    
    for(int a = 0; a < ROW; a++ )
    {
       for(int i = 0; i < COL; i++ ) 
       {
            if(a == 0 && layout[a][i] == 'X')
            first += 1;
            else if(a < 4 && layout[a][i] == 'X')
            business += 1;

            else if(a > 3 && layout[a][i] == 'X')
                coach += 1;     
       }
    }
    classCtr[0] = first;
    classCtr[1] = business;
    classCtr[2] = coach;

    for(int index = 0; index < CTR; index++)
    {
        totalSeat += classCtr[index];
    }
    return totalSeat;
}

void displaySales(int SeatSold)
{
  using namespace std;

double percent;        
SeatSold = getSeat();
cout <<"\n       Total Seats = " << SeatSold
                                 << endl;
percent = static_cast<double>(SeatSold*100)/TOTALSEAT;
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
cout <<"       Percent occupied = " << setw(4) << percent
                                     << endl << endl;
return;
}

void displaySlsRpt (int classCtr[], string classes[], double fare[] )
{
    using namespace std;
    double sum = 0,totalSale = 0;
    cout <<"                                 Sales Report" << endl << endl;
    cout <<"                      Ticket Price" << setw(20) << "Total Sales"
                                                << endl;
    for(int i = 0; i < CTR; i++)
    {
        totalSale = classCtr[i] * fare[i];
        cout << setw(15) << classes[i] << setw(15) << fare[i] << setw(10)
                                        << classCtr[i] << setw(10) << totalSale
                                        << endl << endl;
   
        sum = sum + totalSale;
    }    
    
    cout << " Total Sales =  $   " << sum << endl;
    
    
    return;
}
