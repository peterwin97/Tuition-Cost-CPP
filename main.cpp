/*
  Peter Nguyen
  Dr. T
  11/12/19
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "Input_Validation_Extended.h"

using namespace std;

class cost{
  private:
    double costPerHour = 349.87;
    double bookCost = 120.60;
    double roomBoardCost = 858.50;
    double foodCost = 150.00;
    double travelCost = 90.00;
  public:
    double getCostPerHour() { return costPerHour; }
    double getBookCost() { return bookCost; }
    double getRoomBoardCost() { return roomBoardCost; }
    double getFoodCost() { return foodCost; }
    double getTravelCost() { return travelCost; }
    void setCostPerHour(double d) { costPerHour = d; }
    void setBookCost(double d) { bookCost = d; }
    void setRoomBoardCost(double d) { roomBoardCost = d; }
    void setFoodCost(double d) { foodCost = d; }
    void setTravelCost(double d) { travelCost = d; }

    void showAllCosts(){
      cout << fixed << setprecision(2);
      cout << "Cost/Credit Hour: \t$" << costPerHour << endl;
      cout << "Book Cost/Class: \t$" << bookCost << endl;
      cout << "Room & Board/Month: $" << roomBoardCost << endl;
      cout << "Food/Month: \t\t$" << foodCost << endl;
      cout << "Travel/Month: \t\t$" << travelCost << endl << endl;
    }
};

class semester: public cost {
  private:
    int creditHrs;
    int monthsInSemester = 4;
    int semestersInYear = 3;
    int hoursPerClass = 3;
    
  public:
    semester(int numOfCreditHours): creditHrs(numOfCreditHours) { }
    int getCreditHrs() { return creditHrs; }
    void setCreditHours(int i) { creditHrs = i; }
    
    string colorB = "\x1b[36;1m";
    string colorO = "\x1b[33;1m";
    string colorGrey = "\x1b[37;1m";
    string reset = "\x1b[0m";
    string line = "\x1b[39;4m";

    void showCostPerSemester()
    {
      cout << "Tuition: \t$" << getCostPerHour() * creditHrs << endl;
      cout << "Room/Board: $" << getRoomBoardCost() * monthsInSemester << endl;
      cout << "Travel: \t$" << getTravelCost() * monthsInSemester << endl;
      cout << "Food: \t\t$" << getFoodCost() * monthsInSemester << endl;
      cout << line << "Books:      $" << getBookCost() * (creditHrs/hoursPerClass) << reset << endl << endl;
      cout << colorGrey << "Total: \t\t$" << getCostPerHour() * creditHrs + getRoomBoardCost() * monthsInSemester + getTravelCost() * monthsInSemester + getFoodCost() * monthsInSemester + getBookCost() * (creditHrs/hoursPerClass) << reset << endl << endl;
    }

};


void changePriceMenu(){
  cout << "Change Pricing for:" << endl;
  cout << "A. Cost/Credit Hour" << endl;
  cout << "B. Book Cost/Class" << endl;
  cout << "C. Room & Board/Month" << endl;
  cout << "D. Food/Month" << endl;
  cout << "E. Travel/Month" << endl;
  cout << "X. Exit Program" << endl;
  cout << "Please make a choice: ";
}
void handleOption(semester &ft, semester &pt, semester &ht, char choice, double newPrice){
  
  cout << "\033[2J\033[1;1H";
  if (choice == 'a' || choice == 'A'){
    
    ft.cost::setCostPerHour(newPrice);
    pt.cost::setCostPerHour(newPrice);
    ht.cost::setCostPerHour(newPrice);
  } else if (choice == 'b' || choice == 'B') {
    
    ft.cost::setBookCost(newPrice);
    pt.cost::setBookCost(newPrice);
    ht.cost::setBookCost(newPrice);
  } else if (choice == 'c' || choice == 'C') {
    
    ft.cost::setRoomBoardCost(newPrice);
    pt.cost::setRoomBoardCost(newPrice);
    ht.cost::setRoomBoardCost(newPrice);
  } else if (choice == 'd' || choice == 'D') {
    
    ft.cost::setFoodCost(newPrice);
    pt.cost::setFoodCost(newPrice);
    ht.cost::setFoodCost(newPrice);
  } else if (choice == 'e' || choice == 'E') {
    
    ft.cost::setTravelCost(newPrice);
    pt.cost::setTravelCost(newPrice);
    ht.cost::setTravelCost(newPrice);
  } else if (choice == 'x' || choice == 'X') {
    cout << "Adios amigo.";
  }
}
  

int main() {
  char choice = 'a';
  double newPrice;
  
  semester ft(12);
  semester pt(9);
  semester ht(6);

  do{
    cout << "\033[2J\033[1;1H";
    cout << ft.colorB << "UT @ Arlington Costs: " << ft.reset << endl;
    ft.showAllCosts();

    cout << ft.colorO << "Full Time:" << ft.reset << endl;
    ft.showCostPerSemester();
    
    cout << ft.colorO << "Part Time:" << ft.reset << endl;
    pt.showCostPerSemester();
    
    cout << ft.colorO << "Half Time:" << ft.reset << endl;
    ht.showCostPerSemester();

    changePriceMenu();
    choice = validateChar(choice);
      
    if (choice != 'x' && choice != 'X'){
      cout << "Enter new price: ";
      newPrice = validateDouble(newPrice);
    }
    
    handleOption(ft,pt,ht,choice,newPrice);

  } while (choice != 'x' && choice != 'X');
}