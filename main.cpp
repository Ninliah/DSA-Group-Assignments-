#include <iostream>

using namespace std;

void physics(){

   int a_num, b_num, c_num, d_num;
   cout << "  Enter assignment marks: ";
   cin >> a_num;
   cout << "  Enter coursework marks: ";
   cin >> b_num;
   cout << "  Enter Midterm marks: ";
   cin >> c_num;
   cout << "  Enter end term marks: ";
   cin >> d_num;

   int y = a_num + b_num + c_num + d_num;
   float average = y/4.0;
   cout << "   Average for Physics: " << average << endl;
}

void chemistry(){

   int a_num, b_num, c_num, d_num;
   cout << "  \nEnter assignment marks: ";
   cin >> a_num;
   cout << "  Enter coursework marks: ";
   cin >> b_num;
   cout << "  Enter Midterm marks: ";
   cin >> c_num;
   cout << "  Enter end term marks: ";
   cin >> d_num;

   int y = a_num + b_num + c_num + d_num;
   float average = y/4.0;
   cout << "  Average for Chemistry: " << average << endl;
}

void math(){

   int a_num, b_num, c_num, d_num;
   cout << "  \nEnter assignment marks: ";
   cin >> a_num;
   cout << "  Enter coursework marks: ";
   cin >> b_num;
   cout << "  Enter Midterm marks: ";
   cin >> c_num;
   cout << "  Enter end term marks: ";
   cin >> d_num;

   int y = a_num + b_num + c_num + d_num;
   float average = y/4.0;
   cout << "  Average for math: " << average << endl;

}

int main(){
  physics();
  chemistry();
  math();

  return 0;
}
