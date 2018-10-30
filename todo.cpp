/* todo-task app
** Semester-end mini project
** Submitted by: Rahul Gurung (1726262) & Rahul Sharma (1726266)
**   Submitted to: Mr. Tejpal Sir
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void display(string[], int total_tasks);
void clearscreen();
void write(string[], int total_tasks);

int main()
{
	  int ch, deletion_flag, total_tasks = 0;
    string tasks[20];

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

            display(tasks, total_tasks);
          }
}

void display(string tasks[], int total_tasks) {
  for (int i = 0; i < total_tasks; i++) {
    cout << i + 1 << ")";
    cout << tasks[i] << endl;
  }
}

void clearscreen() {
  // special characters which clears the screen
  cout << "\033[2J\033[1;1H";
}

void write(string tasks[], int total_tasks) {
  ofstream file;
  file.open("tasks.txt");
  file << "Total Tasks: " << total_tasks << endl;
  for (int i = 0; i < total_tasks; i++) {
    file << i + 1 << ") ";
    file << tasks[i] << endl;
  }
  file.close();
}
