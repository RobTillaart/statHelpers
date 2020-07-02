//
//    FILE: perm1.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2010-11-23
//
// PUPROSE: demo permutations
//
char permstring[12] = "123456789A";

uint32_t start, stop;

void permutate(char * array, uint8_t n)
{
  if (n == 0) // end reached print the string
  {
    Serial.println(array);  // process permutation
    return;
  }

  for (int i = 0; i < n; i++)
  {
    // swap
    char t = array[i];
    array[i] = array[n - 1];
    array[n - 1] = t;

    // permutate substrings
    permutate(n - 1);

    // swap back
    t = array[i];
    array[i] = array[n - 1];
    array[n - 1] = t;
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Can take some time..");
  Serial.print("perm1 strlen: ");
  Serial.println(strlen(permstring));

  start = millis();
  permutate(permstring, strlen(permstring));
  stop = millis();
  
  Serial.print("TIME: ");
  Serial.println(stop - start);
}

void loop()
{
}

// -- END OF FILE --

