#include <iostream>
#include "g_list.h"

void item::daily_red()
{
  this->weight = this->weight - ((short int)this->serv_size * (short int)this->serv_pd);
}

void notif(item* item_list, size_t arr_size)
{
  for(int i = 0; i < arr_size; i++)
  {
    if(item_list[i].name != "")
    {
      if(item_list[i].weight <= 0)
      {
        item_list[i].quantity = 0;
        item_list[i].weight = 0;
        std::cout << item_list[i].name << " is finished. Urgent resupply!" << std::endl;
      }
      else if(item_list[i].weight <= 2*(item_list[i].serv_size) && item_list[i].weight > 0)
      {
        std::cout << item_list[i].name << " is running low. Stock up soon!" << std::endl;
      }
    }
  }
}
