#include <iostream>
#include "g_list.h"

//Reduce the weight of the item by (serving size * serving used per day).
void item::dailyRed()
{
  if(this->weight > 0)
  {
    this->weight += - (this->servSize * this->servPd);
  }
}

//Notify user once item has serving size of 2 or less that item is low
//Notify user there is no more of the item left.
void notif(const item(& itemList)[1000])
{
  for(auto i : itemList)
  {
    if(i.name == "")
       break;

    if(i.weight <= 0)
    {
      i.quantity = 0;
      i.weight = 0;
      std::cout << i.name << " is finished. Urgent resupply!" << std::endl;
    }
    else if(i.weight <= 3*(i.servSize) && i.weight > 0)
    {
      std::cout << i.name << " is running low. Stock up soon!" << std::endl;
    }
  }
}
