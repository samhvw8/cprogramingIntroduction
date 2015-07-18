#include <stdio.h>
#define BOLDRED     "\033[1;31m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"
#define BLACK   "\033[30m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BBLUE "\x1b[44m"


main () {
  printf(" ____________________________________________________\n");
  printf("| |   |                                              |\n");
  printf("| |   |"BOLDBLUE"       Truong Dai hoc Bach Khoa Ha Noi"RESET"        |\n");
  printf("| |___| "BOLDRED"             THE SINH VIEN" RESET "                   |\n" );
  printf("|                                                    |\n");
  printf("| _________                                          |\n");
  printf("| "BBLUE"|       |"RESET""BLUE" MSSV:"RESET" 20133270"RESET"         "BLUE" Lop: "RESET"BK2.07"RESET"      |\n");
  printf("| "BBLUE"|       |"RESET""BLUE" Ho Ten:"RESET" HOANG VAN SAM"RESET"                    |\n");
  printf("| "BBLUE"|       |"RESET""BLUE" Ngay Sinh: "RESET"08/01/1994"RESET"  "" Nam""              |\n");
  printf("| "BBLUE"|       |"RESET""BLUE" Ho khau:"RESET" Dong Da - Ha Noi"RESET"                |\n");
  printf("| "BBLUE"|       |"RESET""BLUE" Nhom nganh:"RESET"Dien,DTVT,CNTT,Toan Tin UD"RESET"    |\n");
  printf("| "BBLUE"|_______|"RESET""BLUE" Khoa hoc:"RESET" K58"RESET" "BLUE" Co Gia tri Den:"RESET"30/06/2018"RESET" |\n");
  printf("|                    |||||||||||||||||||||||||||||   |\n");
  printf("| NPH:10/09/2013     |||||||||||||||||||||||||||||   |\n");
  printf("|____________________________________________________|\n");

}
