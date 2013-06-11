/*
 * Exercise 5.1
 */

int main()
{
    char *cp;                   // pointer to char
    int arr[10];                // a array containing 10 ints
    int (&arr_ref)[10] = arr;   // a reference to array containing 10 ints
    char *str;                  // a pointer to a string
    char **p;                   // a pointer to pointer to char
    const int a = 1;            // a constant integer
    const int *ap = &a;         // pointer to const int
    int b = 2;
    int *const cip = &b;        // constant pointer to int

}
