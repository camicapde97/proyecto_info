#include <iostream>
#include <iomanip>
#include <ctime>

int main()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;
}



//////////////////////////////////////////////////////////////////



#include <iostream>
#include <ctime>

int main ()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
  std::string str(buffer);

  std::cout << str;

  return 0;
}