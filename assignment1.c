
/* ------Question 1------*/
#include <stdio.h>

#define MAX 100

int floatingNumValid(char num[])
{
  
  int isValidFloat = 0;
  for (int i = 0; i < MAX - 1; i++)
  {
    if (num[i] == '.' && num[i + 1] != 0)
      isValidFloat = 1;
  }
  return isValidFloat;
}

int main()
{
  char num[MAX] = {0};
  printf("Enter number > ");
  scanf("%s", num);

  printf("Floating number is %s\n", ((floatingNumValid(num)) ? "valid" : "invalid"));

  return 0;
}
/* ------Question 2------*/


#include <stdio.h>

#define MAX 50

int validDomain(char email[], int atIndex)
{
  int periodIndex = -1;
  if (email[atIndex + 1] != '.')
  {

    for (int i = atIndex + 2; i < MAX - 1; i++)
    {
      if (email[i] == '.')
        periodIndex = i;
    }

    if (periodIndex == -1)
      return 0;
    else
      return 1;
  }
  else
    return 0;
}

int isValidEmail(char email[])
{
  int atIndex = -1;
  for (int i = 0; i < MAX - 4; i++)
  {
    if (email[i] == '@')
      atIndex = i;
  }

  if (atIndex == -1)
    return 0;
  else
    return validDomain(email, atIndex);
}

int main()
{

  char email[MAX] = {0};
  printf("Enter Email > ");
  scanf("%s", email);

  printf("The email is %s\n", ((isValidEmail(email)) ? "valid" : "invalid"));
  return 0;
}



/* ------Question 3------*/


#include <stdio.h>

int main() {
  int n, m;
  printf("Enter n m > ");
  scanf("%d %d", &n, &m);
  
  int arrayOneD[n*m];
  int arrayTwoD[n][m];
  for(int i = 0; i<n*m; i++)
    scanf("%d", &arrayOneD[i]);

  for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++)
      arrayTwoD[i][j] = arrayOneD[(i*m) + j];

  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++)
      printf("%d ", arrayTwoD[i][j]);
    printf("\n");
  }
  return 0;
}





/* ------Question 4------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (int)1e4


void generateRandomInput(int n, int input[]) {
  for(int i = 0; i<n; i++)
    input[i] = rand()%MAX;
}

void generateSortedInput(int n, int input[]) {
  for(int i = 0; i<n; i++)
    input[i] = i;
}

int main() {

  srand(time(0));
  int n;
  printf("Enter size of input > ");
  scanf("%d", &n);

  int input[n];

  int k;
  printf("\n");
  printf("1. Randomly Generated\n");
  printf("2. Already Sorted\n");
  printf("Enter type of input 1/2 > ");
  scanf("%d", &k);

  switch(k) {
    case 1:
      generateRandomInput(n, input);
      break;

    case 2:
      generateSortedInput(n, input);
      break;
    
    default:
      printf("Incorrect option\n");
      return 0;
      break;
  }

  FILE *inputFile = fopen("input.txt", "w");
  
  if (inputFile != NULL) {
    printf("Input File Generation Successfull !\n");
  }
  else {
    printf("Input File Generation Failed.\n");
    return -1;
  }
  
  fprintf(inputFile, "%d\n", n);
  for(int i = 0; i<n; i++) fprintf(inputFile, "%d ", input[i]);

  fclose(inputFile);

  return 0;
}

/* ------Bubble sort------*/


#include <stdio.h>
#include <time.h>

int inputSize(FILE *inputFile) {
  int n;
  fscanf(inputFile, "%d", &n);
  return n;
}

void fileInput(FILE *inputFile, int n, int input[]) {

  for(int i = 0; i<n; i++)
    fscanf(inputFile, "%d", &input[i]);
}

void swapInts(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int input[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if(input[j] > input[j+1]) swapInts(&input[j], &input[j+1]);
    }
  }

}

int main() {
  FILE *inputFile = fopen("input.txt", "r");
  if (inputFile != NULL) {
    printf("Input File Successfully Opened !\n");
  }
  else {
    printf("Input File Opening Failed.\n");
    return -1;
  }

  int n = inputSize(inputFile);
  int input[n];

  fileInput(inputFile, n, input);

  clock_t start = clock();

  bubbleSort(input, n);

  clock_t end = clock();
  printf("Total elapsed time : %f\n", (double)(end - start)/(double)CLOCKS_PER_SEC);
  fclose(inputFile);
  return 0;
}


/* ------Selection sort------*/

#include <stdio.h>
#include <time.h>

int inputSize(FILE *inputFile) {
  int n;
  fscanf(inputFile, "%d", &n);
  return n;
}

void fileInput(FILE *inputFile, int n, int input[]) {

  for(int i = 0; i<n; i++)
    fscanf(inputFile, "%d", &input[i]);
}

void swapInts(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int input[], int n) {
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if(input[j] < input[min]) min = j;
    }
    swapInts(&input[min], &input[i]);
  }

}

int main() {
  FILE *inputFile = fopen("input.txt", "r");
  if (inputFile != NULL) {
    printf("Input File Successfully Opened !\n");
  }
  else {
    printf("Input File Opening Failed.\n");
    return -1;
  }

  int n = inputSize(inputFile);
  int input[n];

  fileInput(inputFile, n, input);

  clock_t start = clock();

  selectionSort(input, n);

  clock_t end = clock();
  printf("Total elapsed time : %f\n", (double)(end - start)/(double)CLOCKS_PER_SEC);
  fclose(inputFile);
  return 0;
}