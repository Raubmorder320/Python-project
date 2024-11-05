#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

void printArray(int arr[], int n) { // функция для вывода массива на экран
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n - 1) {
      printf(", "); 
    }
  }
  printf("]\n");
}

//sort 4
void sort_4(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
  int i = 0, j = 0, k = 0;

  // Сравниваем элементы из обоих массивов и добавляем меньший в arr3
  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      arr3[k++] = arr1[i++];
    } else {
      arr3[k++] = arr2[j++];
    }
  }

  // Добавляем оставшиеся элементы из arr1, если они есть
  while (i < n1) {
    arr3[k] = arr1[i];
    k +=1;
    i +=1;
  }

  // Добавляем оставшиеся элементы из arr2, если они есть
  while (j < n2) {
    arr3[k] = arr2[j];
    k+=1;
    j+=1;
  }
}


//search 2a
int search_2a(int arr[], int length, int num) {
  int left = 0;
  int right = length - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2; 

    if (arr[mid] == num) {
      return mid; // Элемент найден, возвращаем его индекс
    }

    if (arr[mid] < num) {
      left = mid + 1; // Ищем в правой половине
    } else {
      right = mid - 1; // Ищем в левой половине
    }
  }

  return -1; // Элемент не найден
}


//search 2b
int search_2b(int arr[], int left, int right, int x) {
  if (right >= left) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
      return mid; 
    }

    if (arr[mid] > x) {
      return search_2b(arr, left, mid - 1, x);
    }

    return search_2b(arr, mid + 1, right, x);
  }

  return -1;
}

//search 5
int search_5(int arr[], int length, int num) {
  int left = 0;
  int right = length - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2; 

    if (arr[mid] == num) {
      right = mid;
      if ( arr[mid-1]!=num || mid == 0){
        return mid; // Элемент найден, возвращаем его индекс
      }
      
       // Элемент найден, возвращаем его индекс
    }

    if (arr[mid] < num) {
      left = mid + 1; // Ищем в правой половине
    } else {
      right = mid - 1; // Ищем в левой половине
    }
  }

  return -1; // Элемент не найден
}


//str 1a
int getString(int pos, int len, char string[])  //функция для взятия среза от pos до конца строки
{
    int i = 0;
    char substring[1000];

    while (i < len) {
        substring[i] = string[pos + i - 1];
        i++;
    }

    substring[i] = '\0';

    // Print the result
    puts(substring);
    
    return 0;
}

//str 1a
void str_1a(){
    char s[] = "C:/ubuntu/is/the/best.h";
    int length = sizeof(s)/sizeof(char);
   
    char* startp = s;
    char* symbolp = strrchr(s, '/');
    int slash = symbolp - startp;
    char s2[slash+1];
    strncpy(s2, s, slash);
    s2[slash] = '\0';
    char* startp2 = s2;
    char* symbolp2 = strrchr(s2, '/');
    int slash2 = symbolp2 - startp2 + 1;
    //Вывод результата
    getString(slash2, slash+1, s2);
}


//str 1b
void str_1b(){
    char s[] = "C:/ubuntu/is/the/best.h"; 
    int length = sizeof(s)/sizeof(char);
    char* startp = s;
    char* dotp = strrchr(s, '.');
    int dot = dotp - startp + 1;
    char s2[dot+5];
    strncpy(s2, s, dot);
    s2[dot] = '\0';
    strcat(s2, "html");
    puts(s2);
}


//str 2a
int str_2a(char* str, char* sub) {
    int count = 0; //счетчик
    int len = strlen(sub);
    for (int i = 0; i <= strlen(str) - len; i++) { //цикл от начала строки до длины строки минус длина образца
        if (strncmp(str + i, sub, len) == 0) { //условие сравнивает срез строки с образцом с помощью арифметики указателей
            count++;
        }
    }
    return count;
}

//str 2b
int str_2b(char* str, char* sub) {
    int count = 0; //счетчик
    int len = strlen(sub);
    int i = 0;
    int length = strlen(str); 
    while (i<=length){
      if (strncmp(str + i, sub, len) == 0) { //условие сравнивает срез строки с образцом с помощью арифметики указателей
            count++;
            if (i+len<=length){ //проверка, можно ли перепрыгнуть на конец найденного образца, чтобы избежать перекрытий
              i+=len;
              continue;
            }
          
        }
        i++;
      
    }

    return count;
}

//str 3
char* str_3(char* str, char* sub){
    int len = strlen(sub);
    char* enter = strstr(str, sub); //указатель на первое вхождение образца
    char* res = (char*)malloc(strlen(str) - len);
    strncpy(res, str, (int)(enter - str)); //копируем все от начала до первого вхождения
    strncat(res, enter+len, strlen(str)); //складываем с тем что после найденного вхождения
    
    return res;
}

//struct cars
struct car{
  int value;
  char color[100];
  double power;
  bool available;
};

void initialization(struct car cars[]){
  for (int i=0; i < 10; i++){
    cars[i].available = false;
  }
}

void fillStorage(struct car cars[]) {
  for (int i = 0; i < 10; i++) {
    printf("Введите цену автомобиля\n"); scanf("%d", &cars[i].value);
    printf("Введите мощность автомобиля\n"); scanf("%lf", &cars[i].power);
    printf("Введите цвет автомобиля\n"); scanf("%s", cars[i].color);
    cars[i].available = true;
  }
}

void information(struct car cars[]){
  for (int i = 0; i < 10; i++){
    if(cars[i].available){
    printf("Цена: %d\n Цвет: %s\n Мощность: %lf\n", cars[i].value, cars[i].color, cars[i].power);
    }
  }
}

void sale(struct car cars[]){
  for (int i = 0; i < 10; i++){
    if (cars[i].available){
      cars[i].available = false;
    }
  }
}

//union
typedef enum{
   type_real, type_int
} type;

union inouble{
  int integer;
  double real;
};

struct var{
  union inouble value;
  type type;
};
	
struct var id_operation(struct var a, struct var b, char flag){
  struct var result;
  switch (flag) {
    case '+':
    switch(a.type){
      case type_int:
      switch (b.type)
        {case type_int:
        result.value.integer = a.value.integer + b.value.integer;
        break;
        case type_real:
        result.value.real = a.value.integer + b.value.real;
        break;}
      break;
      case type_real:
      switch (b.type)
        {case type_int:
        result.value.real = a.value.real + b.value.integer;
        break;
        case type_real:
        result.value.real = a.value.real + b.value.real;
        break;}
      break; 
    }
    break;
    case '-':
      switch(a.type){
      case type_int:
      switch (b.type)
        {case type_int:
        result.value.integer = a.value.integer - b.value.integer;
        break;
        case type_real:
        result.value.real = a.value.integer - b.value.real;
        break;}
      break;
      case type_real:
      switch (b.type)
        {case type_int:
        result.value.real = a.value.real - b.value.integer;
        break;
        case type_real:
        result.value.real = a.value.real - b.value.real;
        break;} 
    }
    break;
    case '*':
      switch(a.type){
      case type_int:
      switch (b.type)
        {case type_int:
        result.value.integer = a.value.integer * b.value.integer;
        break;
        case type_real:
        result.value.real = a.value.integer * b.value.real;
        break;}
      break;
      case type_real:
      switch (b.type)
        {case type_int:
        result.value.integer = a.value.real * b.value.integer;
        break;
        case type_real:
        result.value.real = a.value.real * b.value.real;
        break;} 
    }
    break;
    case '/':
      if (abs(b.value.real) < 10e-6 || b.value.integer != 0)
      {
      switch(a.type){
      case type_int:
      switch (b.type)
        {case type_int:
        result.value.real = (double)a.value.integer / (double)b.value.integer;
        break;
        case type_real:
        result.value.real = (double)a.value.integer / b.value.real;
        break;
        }
      break;
      case type_real:
      switch (b.type)
        {case type_int:
        result.value.real = a.value.real / (double)b.value.integer;
        break;
        case type_real:
        result.value.real = a.value.real / b.value.real;
        break;
        } 
    }
    break;}
    else{
    printf("Деление на ноль\n");
    }
  };

  return result;
}


bool id_compare(struct var a, struct var b, char flag){
  switch (flag){
    case '<':
    switch(a.type){
      case type_int:
      switch (b.type)
        {case type_int:
        return a.value.integer < b.value.integer;
        break;
        case type_real:
        return a.value.integer < b.value.real;
        break;}
      break;
      case type_real:
      switch (b.type)
        {case type_int:
        return a.value.real < b.value.integer;
        break;
        case type_real:
        return a.value.real < b.value.real;
        break;} 
    }
    break;
    case '>':
    switch(a.type){
      case type_int:
      switch (b.type)
        {case type_int:
        return a.value.integer > b.value.integer;
        break;
        case type_real:
        return a.value.integer > b.value.real;
        break;}
      break;
      case type_real:
      switch (b.type)
        {case type_int:
        return a.value.real > b.value.integer;
        break;
        case type_real:
        return a.value.real > b.value.real;
        break;} 
    }
    break;
    case '=':
    switch(a.type){
      case type_int:
      switch (b.type)
        {case type_int:
        return a.value.integer == b.value.integer;
        break;
        case type_real:
        return a.value.integer == b.value.real;
        break;}
      break;
      case type_real:
      switch (b.type)
        {case type_int:
        return a.value.real == b.value.integer;
        break;
        case type_real:
        return abs(a.value.real - b.value.real) < 10e-6;
        break;} 
    }
    break;
  }
}


//input-output
int sinus(){
    
    
    FILE* fp = fopen("sin.txt", "w");
    
    if (fp == NULL){
      return -1;
    }
    fprintf(fp, "x  sin(x)\n");
    
    for (double i = 0; i < 11; i++){

      
      
      fprintf(fp, "%.1f   %.6lf\n", i/10, sin(i/10));
    };

    fclose(fp);
}
int exam(){
  FILE* ep = fopen("exam.txt","r");
  FILE* fp = fopen("f.txt","w");
  if (fp == NULL)
    return -1;
  char str[256];
  int x, y;
  fscanf(ep, "%s", str);
  fscanf(ep, "%s", str);
  fscanf(ep, "%s", str);
  while (fscanf(ep, "%s", str) == 1){
    fscanf(ep, "%d", &x);
    fscanf(ep, "%d", &y);
    fprintf(fp, "%s   %d\n", str, x+y);
  }

  fclose(fp);
  
}

int copy(){
  FILE* fp = fopen("text.txt", "r");
  FILE* gp = fopen("copy.txt", "w");
  if (fp == NULL || gp == NULL)
    return -1;
  char str[256];
  while (fscanf(fp, "%s", str) == 1){
    fprintf(gp, "%s ", str);
  }

  
}

//основная функция
int main ()
{

//sort 4, search 2,5
// int A[]={1,2,3,3,3,3,3,3,3,4,7,8,9,10};
// int B[]={2,4,6,8,10};
// int lengthA = sizeof(A)/sizeof(int);
// int lengthB = sizeof(B)/sizeof(int);
// int length = lengthA+lengthB;
// int C[length];
// sort_4(A, lengthA, B, lengthB, C);
// int x = 3;
// printArray(C, length);

//     printf("%d результат двоичного нерекурсивного поиска\n", search_2a(C, length, x));
//     printf("%d результат поиска первого вхождения элемента двоичным поиском\n", search_5(C, length, x));


// strings
// str_1a();
// str_1b();
// printf("%d", str_2a("aaabcaabcabcaaa", "aa"));
// printf("%d", str_2b("aaabcaabcabcaaa", "aa"));
// printf("%s",str_3("abcaaabc","aa"));


//struct car
  // struct car car1;
  // struct car car2;
  // struct car car3;
  // struct car car4;
  // struct car car5;
  // struct car car6;
  // struct car car7;
  // struct car car8;
  // struct car car9;
  // struct car car10;

  //   struct car cars[10] = {car1, car2, car3, car4, car5, car6, car7, car8, car9, car10}; 
   
  //  while (true){
  //   printf("Введите желаемую операцию:\n 1: Инициализация\n 2: Заполнение склада\n 3: Печать информации\n 4: Продажа автомобиля\n 5: Выход\n");
  //   int user;
  //   scanf("%d", &user);
  //   switch(user){
  //     case 1:
  //     initialization(cars);
  //     break;
  //     case 2:
  //     fillStorage(cars);
  //     break;
  //     case 3:
  //     information(cars);
  //     break;
  //     case 4:
  //     sale(cars);
  //     break;
  //     case 5:
  //     goto stop;
  //     break;
  //   }

  //  }
  //  stop: printf("Вы вышли из программы\n");
    
    //union
    struct var x;
    struct var y;
    x.value.integer = 5;
    x.type = type_int;
    y.value.real = 2.4;
    y.type = type_real;
    struct var res;
    res = id_operation(y,x,'/');
    printf("%d\n", id_compare(x, y, '='));
    printf("%d\n", res.value.integer);
    printf("%.2lf\n", res.value.real);
    
    // sinus();
    // exam();
    // copy();


    printf("\n");
    return 0;
    
}
