#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main (int argc, char *argv[])
{

  if(argc < 3){
    printf("Invalid number of arguments!\n");
    exit(1);
  }

  std::string input = argv[1];
  std::string output = argv[2];

  int inFD = open(input.c_str(), O_RDONLY);
  int outFD = open(output.c_str(), O_WRONLY | O_CREAT);

  if(inFD == -1){
    printf("Input file not found.\n");
    exit(1);
  }

  if(outFD == -1){
    printf("Output file not found.\n");
    exit(1);
  }

  struct stat st;
  stat(input.c_str(), &st);
  int size = st.st_size;

  char buf[size];

  read(inFD, buf, size);
  write(outFD, buf, size);

  close(inFD);
  close(outFD);


  return 0;
}
