#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main (int argc, char *argv[])
{

  try {

    if (argc < 3)
      throw(-1);

    std::string input = argv[1];
    std::string output = argv[2];

    int inFD = open(input.c_str(), O_RDONLY);
    int outFD = open(output.c_str(), O_WRONLY | O_CREAT);

    if ((inFD == -1) || (outFD == -1))
      throw (-1);

    struct stat st;
    stat(input.c_str(), &st);
    int size = st.st_size;

    char buf[size];

    read(inFD, buf, size);
    write(outFD, buf, size);

    close(inFD);
    close(outFD);

  }

  catch (int err) {
    printf("Invalid input.\n");
    exit(1);
  }

  return 0;
}
