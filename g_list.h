#ifndef G_LIST_H
#define G_LIST_H

//Item struct
struct item
{
  std::string name = "";
  unsigned short int quantity;
  float servSize;
  float weight;
  float servPp;
  float servPd;

  void dailyRed();
};

void notif(const item(&)[1000]);

#endif //G_LIST_H
