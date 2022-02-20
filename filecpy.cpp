#include <stdio.h>

int main (int argc, char *argv[])
{

  if(argc < 3){
    printf("Invalid number of arguments!\n");
    exit(1);
  };

  String input = argv[1];
  String output = argv[2];

  int inputCheck = open(input);
  int outputCheck = open(output);

  if(inputCheck == -1){
    printf("Input file not found.\n")
    exit(1);
  };

  if(outputCheck == -1){
    printf("Output file not found.\n")
  };



  return 0;
}
