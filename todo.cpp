/* todo-task app
** Semester-end mini project
** Submitted by: Rahul Gurung (1726262) & Rahul Sharma (1726266)
**   Submitted to: Mr. Tejpal Sir
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void display(string tasks[], int total_tasks);
void clearscreen();
void write(string tasks[], int total_tasks);

int main()
{
  int ch, total_tasks = 0, invalid_flag = 0;
  string tasks[20], temp;

  ifstream infile;
  infile.open("tasks.txt");
  if (infile) {
    string data;

    // this is used to import total_tasks from file
    for (int i = 0; i < 2; i++) {
      infile >> data;
    }
    infile >> total_tasks;
    cout << total_tasks;

    // importing each tasks into a single index
    for (int i = 0; i < total_tasks; i++) {
      infile >> data;
      infile >> data;
      infile >> data;
      infile >> temp;

      while (temp != "$$") {
        data = data + " " + temp;
        infile >> temp;
      }

      tasks[i] = data;
    }

    clearscreen();
    display(tasks, total_tasks);
  }

  while (true) {

    cout << "----------------------------------------------------------"
            "--------"
         << endl;
    cout << "Choose your option:" << endl
         << "1) Enter new tasks." << endl
         << "2) Delete old tasks." << endl
         << "3) Exit." << endl;
    cout << "----------------------------------------------------------"
            "--------"
         << endl;

    if ( invalid_flag == 1 )
    {
      cout << "Invalid Input." << endl;
      invalid_flag = 0;
    }

    cin >> ch;

    clearscreen();

    if (ch == 1) {
      cout << "Enter tasks:" << endl;
      cin.ignore();
      getline(cin, tasks[total_tasks]);
      total_tasks++;
      clearscreen();
    }

    else if (ch == 2) {
      cout << "Choose the number of data to be deleted" << endl;
      int deletion_flag;
      display(tasks, total_tasks);
      cout << ":";
      cin >> deletion_flag;
      deletion_flag--;
      for (int i = deletion_flag; i < total_tasks; i++) {
        tasks[i] = tasks[i + 1];
      }
      total_tasks--;
      clearscreen();
    }

    else if (ch == 3) {
      write(tasks, total_tasks);
      cout << "Thanks for using Todo-List" << endl;
      exit(0);
    }

    else {
      invalid_flag = 1;
    }

    display(tasks, total_tasks);

  }
}

/* this function displays the tasks */
void display(string tasks[], int total_tasks) {
  for (int i = 0; i < total_tasks; i++) {
    cout << i + 1 << ")";
    cout << tasks[i] << endl;
  }
}

/* this function clears the screen to the bottom */
void clearscreen() {
  for (int i = 0; i < 100; i++)
    cout << endl;
}

/* this function writes our tasks to a separate .txt file */
void write(string tasks[], int total_tasks) {
  ofstream outfile;
  outfile.open("tasks.txt");
  outfile << "Total Tasks: " << total_tasks << endl;
  for (int i = 0; i < total_tasks; i++) {
    outfile << i + 1 << ") ";
    outfile << "$$ ";
    outfile << tasks[i];
    outfile << " $$";
    outfile << endl;
  }
  outfile.close();
}
