#ifndef G_LIST_H
#define G_LIST_H

struct item
{
public:
  std::string name = "";
  short int weight;
  unsigned short int serv_size;
  unsigned short int serv_pp;
  unsigned short int quantity;
  unsigned short int serv_pd;
  void daily_red();
};

void notif(item*, size_t);


#endif //G_LIST_H
