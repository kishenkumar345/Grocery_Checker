#include <iostream>
#include <unistd.h>
#include "g_list.h"

int main(int argc, char** argv)
{
  item g_list[50] = {};

  item bread;
  bread.name = "Tip Top The One White Sandwich Bread";
  bread.quantity = 1;
  bread.weight = 700;
  bread.serv_size = 74;
  bread.serv_pp = 9.5;
  bread.serv_pd = 1.5;

  g_list[0] = bread;
  size_t g_list_size = sizeof(g_list)/sizeof(g_list[0]);

  int temp = 0;
  while(temp == 0)
  {
    for(int i = 0; i < g_list_size; i++)
    {
      if(g_list[i].name != "")
      {
        g_list[i].daily_red();
      }
    }

    notif(g_list, g_list_size);
    std::cout << "See you tomorrow!" << std::endl;
    sleep(5);
  }

  return 0;
}
