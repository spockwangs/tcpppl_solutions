/*
 * Exercise 5.3
 */

int main()
{
    typedef unsigned char u_char;
    typedef const unsigned char con_u_char;
    typedef int *int_p;
    typedef char **char_pp;
    typedef char (*char_arr_p)[10];     // pointer to char array containing 10 members
    typedef int *int_ap[7];     // array of 7 pointers to int

    // pointer to an array of 7 pointers to int
    typedef int *(*int_array)[7];

    // a two-dimensional array of pointers to int
    typedef int *arr_arr[8][7];
}
