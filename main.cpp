#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "g_list.h"

unsigned short int addItem(item*, unsigned short int);
unsigned short int delItem(item*, unsigned short int);
void viewItemList(const item(&)[1000]);
void runDR(const item(&)[1000]);

int main(int argc, char** argv)
{
  item gList[1000] = {};

  unsigned short int index = 0;
  char select;
  while(select != 'E')
  {
    std::cout << "\nWelcome to Grocery List!" << std::endl;
    std::cout << "Please select an option:\n" << std::endl;
    std::cout << "(A)dd Item " << " (D)elete Item "<< " (V)iew Grocery List "<< " (E)xit "<< std::endl;
    std::cin >> select;
    std::cin.ignore();

    switch(select)
    {
      case 'A':
           index = addItem(gList, index);
           break;
      case 'D':
           index = delItem(gList, index);
           break;
      case 'V':
           viewItemList(gList);
           break;
      case 'E':
           std::cout << "Bye! Have a nice day!" << std::endl;
           break;
      default:
           std::cout << "Error occured!" << std::endl;
    }
  }

  return 0;
}

unsigned short int addItem(item* gList, unsigned short int index)
{

  item aItem;

  std::cout << "\nEnter item name: " << std::endl;
  std::getline(std::cin, aItem.name);

  std::cout << "Enter item quantity: " << std::endl;
  std::cin >> aItem.quantity;

  std::cout << "Enter item weight: " << std::endl;
  std::cin >> aItem.weight;

  std::cout << "Enter item serving size: " << std::endl;
  std::cin >> aItem.servSize;

  std::cout << "Enter servings per item: " << std::endl;
  std::cin >> aItem.servPp;

  std::cout << "Enter item servings used daily: " << std::endl;
  std::cin >> aItem.servPd;

  if(index < 1000)
  {
    gList[index] = aItem;
  }
  else
  {
    std::cout << "Index full!" << std::endl;
    return index;
  }

  index++;
  return index;
}

unsigned short int delItem(item* gList, unsigned short int index)
{
  unsigned short int delIndex;
  std::cout << "Select an item number to delete\n" << std::endl;
  std::cin >> delIndex;

  index--;

  for(int i = delIndex; i < 1000; i++)
  {
    if(gList[i].name == "")
    {
      return index;
    }
    else if(i == 999)
    {
      item nullItem;
      gList[i] = nullItem;
      return index;
    }
    else
    {
      gList[i] = gList[i+1];
    }
  }

  return index;
}

void viewItemList(const item(& gList)[1000])
{
  unsigned short int index = 0;

  for(auto i : gList)
  {
    if(i.name == "")
    {
      break;
    }
    else
    {
      std::cout << i.name << std::endl;
      std::cout << i.quantity << std::endl;
      std::cout << i.weight << std::endl;
      std::cout << i.servSize << std::endl;
      std::cout << i.servPp << std::endl;
      std::cout << i.servPd << std::endl;
    }
  }
}

void runDR(const item(& gList)[1000])
{
  for(auto i : gList)
  {
    if(i.name == "")
    {
      break;
    }
    else
    {
      std::cout << i.name << std::endl;
      i.dailyRed();
    }
  }

  notif(gList);
}
