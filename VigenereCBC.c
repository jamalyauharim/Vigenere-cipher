// Jamal Yauhari Martinez - ja843104
// CIS3360-18
#include <stdio.h>
#include <string.h>
#include <ctype.h>

 int main(int argc, char **argv)
 {
// declaration of all arrays, variables and counters.
   int i, j, n, k = 0, x, sizeOfIV, sizeOfKey, keyValue, newResult, result, counter,
    value, encryptedLetter, plaintextLength, decryptedLetter;
   char plaintext[20];
   char* key = argv[2];
   char* initialVector = argv[3];
   char arrayWithResult[50] = {0};
   char arrayWithDecryption[100];

   sizeOfKey = strlen(key);
   sizeOfIV = strlen(initialVector);
// checking if length of initial vector and key are the same.
   if (sizeOfKey != sizeOfIV)
   {
     printf("Size of key is not equal to the size of the IV\n");
     return 0;
   }
// checking that the vector and key are lowercase
   for( i = 0; i < sizeOfKey; i++)
   {
     if ((argv[2][i] < 97 && argv[2][i] < 122)  || (argv[3][i] < 97 && argv[3][i] < 122))
     {
       printf("Please only input lower case key and vector.\n");
       return 0;
     }
   }
// printing the data inputed.
   printf("Key: %s\n", key);
   printf("IV: %s\n", initialVector);
   printf("Block Size : %d\n", sizeOfKey);
   printf("Plaintext: ");

   n = strlen(argv[1]);
// getting rid of special characters utilizing ascii value comparison.
  for (i = 0; i < n ; i++)
  {
     if ((argv[1][i] >= 65 && argv[1][i] <= 90) || (argv[1][i] >= 97 && argv[1][i] <= 122))
     {
      plaintext[k] = argv[1][i];
      k++;
     }
  }

  n = strlen(plaintext);
// prints out the lenght of the plaintext.
   for (j = 0; j < n; j++)
   {
     printf("%c", tolower(plaintext[j]));
   }
   printf("\n");
   printf("Number of characters in plaintext : %d\n", n);
// while loop to develop padding if plaintext is not even in comparison with its keys.
   while ( (n/sizeOfKey)% 2 == 0 )
   {
     plaintext[n] = 'x';
     n++;
   }
   n = strlen(plaintext);
// prints the length of the plaintext after padding
   printf("Number of characters after padding : %d\n", n);
// first equation of the vigenere encipher with cbc Block
// three arrays, one for the key, one for the IV, and one for the first block of the plaintext
   for (i = 0; i < sizeOfKey; i++)
   {
     keyValue = (key[i] - 'a');
     value = (plaintext[i] - 'a');
     result = (initialVector[i] - 'a');
// all the encrypted letters are stored in an array.
     encryptedLetter = (((keyValue + value + result) % 26) + 65);
     arrayWithResult[i] = encryptedLetter;

   }

   n = strlen(arrayWithResult);

   counter = i;
   plaintextLength = strlen(plaintext);
   j = 0;
   k = 0;
// encryption for all the missing characters in the Plaintext.
// same array of key is utilized, and same array of Plaintext.
// array with previous encrypted letters is now being utilize to be applied to the formula.

   for (i = counter; i < plaintextLength; i ++)
   {
     if (k == sizeOfKey)
     {
       k = 0;
     }
     keyValue = (key[k] - 'a');
     value = (plaintext[i] - 'a');
     result = (arrayWithResult[j] - 65);
// all the missing characters are added to the Encryption array.
     encryptedLetter = (((keyValue + value + result)% 26) + 65);
     arrayWithResult[i] = encryptedLetter;

     j++;
     k++;
   }
   n = strlen(arrayWithResult);
// now the array with the encrypted characters is utilized within a for loop to print all the values stored.
// in esence the encryption.
   printf("Encryption : ");
   for (i = 0; i < n; i++)
   {
     printf("%c", arrayWithResult[i]);
   }
   printf("\n");

// same method for encryption but now is being utilized for decryption,
// math formula changes here, instead of summing all the characteres
// we substract them and add a multiple of 26 to make the % operand successfull.
   for (i = 0; i < sizeOfKey; i++)
   {
     keyValue = (key[i] - 'a');
     value = (arrayWithResult[i] - 'A');
     result = (initialVector[i] - 'a');

     decryptedLetter = ((2600 + value - result - keyValue)% 26) + 65;
     arrayWithDecryption[i] = decryptedLetter;
   }

   n = strlen(arrayWithDecryption);

   counter = i;
   plaintextLength = strlen(plaintext);
   j = 0;
   k = 0;
// decryption for loop is implemented for the rest of the array that holds all the encrypted letters.
   for (i = counter; i < plaintextLength; i ++)
   {
     if (k == sizeOfKey)
     {
       k = 0;
     }
     keyValue = (key[k] - 'a');
     value = (arrayWithResult[i] - 'A');
     result = (arrayWithResult[j] - 'A');
// same formula is applied to the array to decrypt rest of the missing letters.
     decryptedLetter = ((26000 + value - result - keyValue)% 26) + 65;
     arrayWithDecryption[i] = decryptedLetter;

     j++;
     k++;
   }
   n = strlen(arrayWithDecryption);
// array with decrypted letters is utilized within loop to print the value.
   printf("Decryption : ");

   for (i = 0; i < n; i++)
   {
     printf("%c", arrayWithDecryption[i]);
   }

   printf("\n");
   return 0;
 }
