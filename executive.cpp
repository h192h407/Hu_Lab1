/*
Author: Haonan Hu
File: executive.cpp
Date:2/20/2019
Brief:File is cpp file
*/

#include "executive.h"
#include "Linked_list.h"
#include <stdexcept>
#include <iostream>
#include <limits>
using namespace std;

executive::executive(string fileName)
{
  ifstream infile;
  infile.open(fileName);
  int data;
  if(infile.is_open())  //  file read successful
  {
    while(infile >> data) // make sure file input is valid
    {
      myList.Insert(data);
    }
  }
  else
    cout << "Unable to open file\n";
}
void executive::run()
{
  int choice;
  for(;;)
  {
    cout << "Choose one operation from the options below: \n\n";
    cout << "   1. Is Empty\n";
    cout << "   2. Length\n";
    cout << "   3. Insert\n";
    cout << "   4. Delete\n";
    cout << "   5. Delete Duplicates\n";
    cout << "   6. Find\n";
    cout << "   7. Find Next\n";
    cout << "   8. Print\n";
    cout << "   9. Reverse List\n";
    cout << "   10.Print At\n";
    cout << "   11.Exit \n\n";
    cin >> choice;
    cout << '\n';
    while(1)
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Wrong input!\n\n";
        cout << "..................................\n\n";
        cout << "Choose one operation from the options below: \n\n";
        cout << "   1. Is Empty\n";
        cout << "   2. Length\n";
        cout << "   3. Insert\n";
        cout << "   4. Delete\n";
        cout << "   5. Delete Duplicates\n";
        cout << "   6. Find\n";
        cout << "   7. Find Next\n";
        cout << "   8. Print\n";
        cout << "   9. Reverse List\n";
        cout << "   10.Print At\n";
        cout << "   11.Exit \n\n";
        cin >> choice;
        cout << '\n';
      }
      if(!cin.fail())
        break;
    }
    if(choice == 1) //  Checking empty list
    {
      if(myList.IsEmpty() == true)
      {
        cout << "The list is empty.\n\n";
        cout << "..................................\n\n";
      }
      else
      {
        cout << "The list is not empty.\n\n";
        cout << "..................................\n\n";
      }
    }
    else if(choice == 2) // checking length of the list
    {
      cout << "The length of the list is: " << myList.Length() << "\n\n";
      cout << "..................................\n\n";
    }
    else if(choice == 3) // Insert to the list
    {
      int entry;
      cout << "Choose a number to be inserted: \n\n";
      cin >> entry;
      cin.ignore();
      cout << '\n';
      myList.Insert(entry);
      if(myList.getFront()->getEntry() == entry)
      {
        cout << entry << " is inserted.\n\n";
        cout << "..................................\n\n";
      }
      else
      {
        cout << "Insert not successful.\n\n";
        cout << "..................................\n\n";
      }
    }
    else if(choice == 4) // Delete from the list
    {
      int entry;
      cout << "Choose a number to be deleted from the list: \n\n";
      cin >> entry;
      cin.ignore();
      cout << '\n';
      if(myList.Find(entry))
      {
        try
        {
          myList.Delete(entry);
          cout << "The last occurence of " << entry << " has been deleted from the list.\n\n";
          cout << "..................................\n\n";
        }
        catch(runtime_error &rte)
        {
          cout << rte.what() << '\n';
          cout << "..................................\n\n";
        }
      }
      else
      {
        cout << entry << " is not found in the list.\n\n";
        cout << "..................................\n\n";
      }
    }
    else if(choice == 5) //Delete duplicates from the list
    {
      try
      {
        myList.DeleteDuplicates();
        cout << "Duplicates deleted.\n\n";
        cout << "..................................\n\n";
      }
      catch(runtime_error &rte)
      {
        cout << rte.what() << '\n';
        cout << "..................................\n\n";
      }
    }
    else if(choice == 6) // Find element in the list
    {
      int entry;
      cout << "Enter the number to find: \n\n";
      cin >> entry;
      cin.ignore();
      cout << '\n';
      try
      {
        if(myList.Find(entry))
        {
          cout << entry << " is in the list.\n\n";
          cout << "..................................\n\n";
        }
        else
        {
          cout << entry << " is not found in the list.\n\n";
          cout << "..................................\n\n";
        }
      }
      catch(runtime_error &rte)
      {
        cout << rte.what() << '\n';
        cout << "..................................\n\n";
      }
    }
    else if(choice == 7)// Find the next element
    {
      int entry;
      cout << "Enter the number to find its next element: \n\n";
      cin >> entry;
      cin.ignore();
      cout << '\n';
      if(!myList.IsEmpty())
      {
        myList.FindNext(entry);
        cout << "..................................\n\n";
      }
      else
        cout << "The list is Empty.\n\n";
    }
    else if(choice == 8) // Print the list
    {
      try
      {
        myList.Print();
        cout << "..................................\n\n";
      }
      catch(runtime_error &rte)
      {
        cout << rte.what() << '\n';
        cout << "..................................\n\n";
      }
    }
    else if(choice == 9) //Print the Reverse list
    {
      try
      {
        myList.ReverseList();
        cout << "..................................\n\n";
      }
      catch(runtime_error &rte)
      {
        cout << rte.what() << '\n';
        cout << "..................................\n\n";
      }
    }
    else if(choice == 10) //Print the element at the given position
    {
      int position;
      cout << "Choose a position to print element: \n\n";
      cin >> position;
      cin.ignore();
      cout << '\n';
      try
      {
        myList.PrintAt(position);
        cout << "..................................\n\n";
      }
      catch(runtime_error &rte)
      {
        cout << rte.what() << '\n';
        cout << "..................................\n\n";
      }
    }
    else if(choice == 11)
    {
      cout << "Program execution complete!\n";
      break;
    }
    else
    {
      cout << " Wrong input!\n\n";
      cout << "..................................\n\n";
    }
  }
}
