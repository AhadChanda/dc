#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n1;
  int n2;

  cout << "Enter number of events in Process 1: ";
  cin >> n1;
  cout << "Enter number of events in Process 2: ";
  cin >> n2;

  int tp1[n1], tp2[n2];
  int dependencyMatrix[n1][n2];
  // setting initial value of timestamps
  for (int i = 0; i < n1; i++)
    tp1[i] = i + 1;
  for (int i = 0; i < n2; i++)
    tp2[i] = i + 1;

  cout << "\n\nEnter Dependency matrix";
  cout << "\n1 \t-\t P1->P2\n-1 \t-\t P2->P1\n0 \t-\t otherwise\n";
  for (int i = 0; i < n2; i++) 
  {
    cout << "\tP2:" << i + 1;
  }
  for (int i = 0; i < n1; i++) 
  {
    cout << "\nP1:" << i + 1 << "\t";
    for (int j = 0; j < n2; j++) 
    {
      cin >> dependencyMatrix[i][j];
    }
  }

  // generating time stamps for each event
  for (int i = 0; i < n1; i++) 
  {
    for (int j = 0; j < n2; j++) 
     {
      switch (dependencyMatrix[i][j]) 
      {
      case 1:
        tp2[j] = max(tp2[j], tp1[i] + 1);
        for (int k = j; k < n2 - 1; k++)
          tp2[k + 1] = tp2[k] + 1;
        break;
      case -1:
        tp1[i] = max(tp1[i], tp2[j] + 1);
        for (int k = i; k < n1 - 1; k++)
          tp1[k + 1] = tp1[k] + 1;
        break;
      case 0:
        break;
      default:
        cout << "Invalid Dependency Matrix";
        break;
      }
    }
  }

  cout << "Process P1 - ";
  for (int i = 0; i < n1; i++)
    cout<< i + 1 << " :" << tp1[i] << "  ";
  cout << "\nProcess P2 - ";
  for (int i = 0; i < n2; i++)
    cout<< i + 1 << " :" << tp2[i] << "  ";
  return 0;
}
