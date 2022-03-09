#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //biblioteca local apenas pra acentuação, pode ser tirada em conjunto com a primeira linha do main sem problemas

int main(){
SetConsoleOutputCP(65001); //essa aqui
printf("Hello, World! Caráios");
return 0;
}